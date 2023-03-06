#include "game/graphics/model/model.h"
#include <iostream>
#include <image/stb_image.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>
#include "game/SourceHeader.h"
map<string, shared_ptr<Model>> Model::defaults{};
void Model::Draw(Renderer& renderer)
{
	for (auto& mesh : meshes)
		mesh.Draw(renderer);
}

map<string, BoneInfo>& Model::GetBoneInfoMap()
{
	return m_BoneInfoMap;
}

int& Model::GetBoneCount()
{
	return m_BoneCounter;
}

AABB Model::GetAabb() const
{
	return *(bounds.get());
}

Model::Model(XMLElement* element)
{
	string path = element->Attribute("res");
	gammaCorrection = StringUtil::ParseBool(element->Attribute("gamma"));
	layout = make_unique<VertexBufferLayout>(
		element->FirstChildElement("layout"));
	// read file via ASSIMP
	Importer importer;
	const aiScene* scene = importer.ReadFile(
		path, aiProcess_Triangulate | aiProcess_GenSmoothNormals |
		aiProcess_CalcTangentSpace);
	// check for errors
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->
		mRootNode) // if is Not Zero
	{
		cout << "ERROR:: " << importer.GetErrorString() << endl;
		return;
	}
	// retrieve the directory path of the filepath
	directory = path.substr(0, path.find_last_of('/'));

	// process ASSIMP 's root node recursively
	ProcessNode(scene->mRootNode, scene);
	bounds.reset( AABB::GenerateAabb(*this));
}

void Model::ProcessNode(aiNode* node, const aiScene* scene)
{
	// process each mesh located at the current node
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		// the node object only contains indices to index the actual objects in the scene. 
		// the scene contains all the data, node is just to keep stuff organized (like relations between nodes).
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.emplace_back(ProcessMesh(mesh, scene));
	}
	// after we've processed all of the meshes (if any) we then recursively process each of the children nodes
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		ProcessNode(node->mChildren[i], scene);
	}
}

void Model::SetVertexBoneDataToDefault(Vertex& vertex)
{
	for (int i = 0; i < MAX_BONE_INFLUENCE; i++)
	{
		vertex.boneIDs[i] = -1;
		vertex.weights[i] = 0.0f;
	}
}

Mesh&& Model::ProcessMesh(aiMesh* mesh, const aiScene* scene)
{
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<size_t> textures;
	auto elements = layout->GetElements();
	bool normal = elements.find("normal") != elements.end();
	bool texCoords = elements.find("texCoords") != elements.end();
	bool tangent = elements.find("tangent") != elements.end();
	bool bitangent = elements.find("bitangent") != elements.end();
	bool bone = elements.find("bone") != elements.end();
	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex vertex;
		SetVertexBoneDataToDefault(vertex);
		vertex.position = TypeUtil::GlmVec3(mesh->mVertices[i]);
		if (normal)vertex.normal = TypeUtil::GlmVec3(mesh->mNormals[i]);
		if (tangent)vertex.tangent = TypeUtil::GlmVec3(mesh->mTangents[i]);
		if (bitangent)
			vertex.bitangent = TypeUtil::GlmVec3(
				mesh->mBitangents[i]);
		if (texCoords && mesh->mTextureCoords[0])
		{
			vec2 vec;
			vec.x = mesh->mTextureCoords[0][i].x;
			vec.y = mesh->mTextureCoords[0][i].y;
			vertex.texCoords = vec;
		}
		else
			vertex.texCoords = vec2(0.0f, 0.0f);

		vertices.push_back(vertex);
	}
	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}
	aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
	vector<size_t> diffuseMaps = LoadMaterialTextures(
		material, aiTextureType_DIFFUSE, "texture_diffuse");
	textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
	vector<size_t> specularMaps = LoadMaterialTextures(
		material, aiTextureType_SPECULAR, "texture_specular");
	textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	vector<size_t> normalMaps = LoadMaterialTextures(
		material, aiTextureType_HEIGHT, "texture_normal");
	textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
	vector<size_t> heightMaps = LoadMaterialTextures(
		material, aiTextureType_AMBIENT, "texture_height");
	textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

	if (bone)ExtractBoneWeightForVertices(vertices, mesh, scene);

	return move(Mesh(vertices, indices, textures, layout.get()));
}

void Model::SetVertexBoneData(Vertex& vertex, int boneID, float weight)
{
	for (int i = 0; i < MAX_BONE_INFLUENCE; ++i)
	{
		if (vertex.boneIDs[i] < 0)
		{
			vertex.weights[i] = weight;
			vertex.boneIDs[i] = boneID;
			break;
		}
	}
}

void Model::ExtractBoneWeightForVertices(vector<Vertex>& vertices,
										aiMesh* mesh, const aiScene* scene)
{
	auto& boneInfoMap = m_BoneInfoMap;
	int& boneCount = m_BoneCounter;

	for (unsigned int boneIndex = 0; boneIndex < mesh->mNumBones; ++boneIndex)
	{
		int boneId;
		string boneName = mesh->mBones[boneIndex]->mName.C_Str();
		if (boneInfoMap.find(boneName) == boneInfoMap.end())
		{
			BoneInfo newBoneInfo;
			newBoneInfo.id = boneCount;
			newBoneInfo.offset = TypeUtil::GlmMat4(
				mesh->mBones[boneIndex]->mOffsetMatrix);
			boneInfoMap[boneName] = newBoneInfo;
			boneId = boneCount;
			boneCount++;
		}
		else
		{
			boneId = boneInfoMap[boneName].id;
		}
		assert(boneId != -1);
		auto weights = mesh->mBones[boneIndex]->mWeights;
		int numWeights = mesh->mBones[boneIndex]->mNumWeights;

		for (int weightIndex = 0; weightIndex < numWeights; ++weightIndex)
		{
			int vertexId = weights[weightIndex].mVertexId;
			float weight = weights[weightIndex].mWeight;
			assert(vertexId <= vertices.size());
			SetVertexBoneData(vertices[vertexId], boneId, weight);
		}
	}
}

vector<size_t> Model::LoadMaterialTextures(aiMaterial* mat, aiTextureType type,
											const string& typeName)
{
	vector<size_t> textures;
	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		// check if texture was loaded before and if so, continue to next iteration: skip loading a new texture

		auto filename = directory + '/' + str.C_Str();
		textures.push_back(
			Entry::res.LoadTexture(filename, typeName, gammaCorrection));
	}
	return textures;
}

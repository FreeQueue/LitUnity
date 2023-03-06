#pragma once

#include "mesh.h"

#include <assimp/scene.h>
#include <memory>
#include <string>
#include <map>
#include <vector>

#include "Boundings.h"
#include "game/graphics/animation/Animdata.h"

namespace Game
{
	class Model
	{
	public:
		std::string xmlPath;
		std::string directory;
		bool gammaCorrection = false;

		std::unique_ptr<AABB> bounds{};
		std::vector<Mesh> meshes{};
		std::unique_ptr<VertexBufferLayout> layout{};

		static std::map<std::string, std::shared_ptr<Model>> defaults;

	private:
		std::map<std::string, BoneInfo> m_BoneInfoMap{};
		int m_BoneCounter = 0;

	public:
		explicit Model(tinyxml2::XMLElement* element);
		~Model() = default;
		// draws the model, and thus all its meshes
		void Draw(Renderer& renderer);
		std::map<std::string, BoneInfo>& GetBoneInfoMap();
		int& GetBoneCount();
		AABB GetAabb() const;

	private:
		// processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
		void ProcessNode(aiNode* node, const aiScene* scene);

		void SetVertexBoneDataToDefault(Vertex& vertex);

		Mesh&& ProcessMesh(aiMesh* mesh, const aiScene* scene);

		void SetVertexBoneData(Vertex& vertex, int boneID, float weight);

		void ExtractBoneWeightForVertices(std::vector<Vertex>& vertices,
										aiMesh* mesh, const aiScene* scene);

		// checks all material textures of a given type and loads the textures if they're not loaded yet.
		// the required info is returned as a Texture struct.
		std::vector<size_t> LoadMaterialTextures(
			aiMaterial* mat, aiTextureType type, const std::string& typeName);
	};
}

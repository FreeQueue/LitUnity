#include <assimp/Importer.hpp>

#include "game/graphics/animation/animation.h"

#include <assimp/postprocess.h>

#include "game/SourceHeader.h"

Animation::Animation(const string& animationPath, Model* model)
{
	Importer importer;
	const aiScene* scene = importer.ReadFile(animationPath, aiProcess_Triangulate);
	assert(scene && scene->mRootNode);
	auto animation = scene->mAnimations[0];
	m_Duration = animation->mDuration;
	m_TicksPerSecond = animation->mTicksPerSecond;
	aiMatrix4x4 globalTransformation = scene->mRootNode->mTransformation;
	globalTransformation = globalTransformation.Inverse();
	ReadHeirarchyData(m_RootNode, scene->mRootNode);
	ReadMissingBones(animation, *model);
}

Animation::~Animation()
= default;

Bone* Animation::FindBone(const string& name)
{
	auto iter = find_if(m_Bones.begin(), m_Bones.end(),
						[&](const Bone& bone)
						{
							return bone.GetBoneName() == name;
						}
	);
	if (iter == m_Bones.end()) return nullptr;
	return &(*iter);
}

const map<string, BoneInfo>& Animation::GetBoneIdMap()
{
	return m_BoneInfoMap;
}

void Animation::ReadMissingBones(const aiAnimation* animation, Model& model)
{
	int size = animation->mNumChannels;

	auto& boneInfoMap = model.GetBoneInfoMap(); //getting m_BoneInfoMap from Model class
	int& boneCount = model.GetBoneCount(); //getting the m_BoneCounter from Model class

	//reading channels(bones engaged in an animation and their keyframes)
	for (int i = 0; i < size; i++)
	{
		auto channel = animation->mChannels[i];
		string boneName = channel->mNodeName.data;

		if (boneInfoMap.find(boneName) == boneInfoMap.end())
		{
			boneInfoMap[boneName].id = boneCount;
			boneCount++;
		}
		m_Bones.emplace_back(channel->mNodeName.data,
							boneInfoMap[channel->mNodeName.data].id, channel);
	}

	m_BoneInfoMap = boneInfoMap;
}

void Animation::ReadHeirarchyData(AssimpNodeData& dest, const aiNode* src)
{
	assert(src);

	dest.name = src->mName.data;
	dest.transformation = TypeUtil::GlmMat4(src->mTransformation);
	dest.childrenCount = src->mNumChildren;

	for (unsigned i = 0; i < src->mNumChildren; i++)
	{
		AssimpNodeData newData;
		ReadHeirarchyData(newData, src->mChildren[i]);
		dest.children.push_back(newData);
	}
}

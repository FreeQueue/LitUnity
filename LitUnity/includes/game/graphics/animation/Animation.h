#pragma once

#include <vector>
#include <map>
#include <glm/glm.hpp>
#include <assimp/scene.h>
#include "bone.h"
#include "animdata.h"
#include "game/graphics/model/Model.h"

namespace Game
{
	struct AssimpNodeData
	{
		glm::mat4 transformation{};
		std::string name;
		int childrenCount{};
		std::vector<AssimpNodeData> children{};
	};

	class Animation
	{
	public:
		Animation() = default;

		Animation(const std::string& animationPath, Model* model);

		~Animation();

		Bone* FindBone(const std::string& name);


		int GetTicksPerSecond() const { return m_TicksPerSecond; }
		float GetDuration() const { return m_Duration; }
		const AssimpNodeData& GetRootNode() { return m_RootNode; }

		const std::map<std::string, BoneInfo>& GetBoneIdMap();

	private:
		void ReadMissingBones(const aiAnimation* animation, Model& model);

		void ReadHeirarchyData(AssimpNodeData& dest, const aiNode* src);

		float m_Duration;
		int m_TicksPerSecond;
		std::vector<Bone> m_Bones;
		AssimpNodeData m_RootNode;
		std::map<std::string, BoneInfo> m_BoneInfoMap;
	};
}

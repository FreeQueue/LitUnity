#pragma once
#include <vector>
#include <assimp/scene.h>
#include <glm/glm.hpp>

#include <glm/detail/type_quat.hpp>

namespace Game
{
	struct KeyPosition
	{
		glm::vec3 position;
		float timeStamp;
	};

	struct KeyRotation
	{
		glm::quat orientation;
		float timeStamp;
	};

	struct KeyScale
	{
		glm::vec3 scale;
		float timeStamp;
	};

	class Bone
	{
	public:
		Bone(std::string name, int id, const aiNodeAnim* channel);

		void Update(float animationTime);

		glm::mat4 GetLocalTransform() const { return m_LocalTransform; }
		std::string GetBoneName() const { return m_Name; }
		int GetBoneId() const { return m_Id; }


		int GetPositionIndex(float animationTime) const;

		int GetRotationIndex(float animationTime) const;

		int GetScaleIndex(float animationTime) const;

	private:
		static float GetScaleFactor(float lastTimeStamp, float nextTimeStamp,
									float animationTime);

		glm::mat4 InterpolatePosition(float animationTime);

		glm::mat4 InterpolateRotation(float animationTime);

		glm::mat4 InterpolateScaling(float animationTime);

		std::vector<KeyPosition> m_Positions;
		std::vector<KeyRotation> m_Rotations;
		std::vector<KeyScale> m_Scales;
		int m_NumPositions;
		int m_NumRotations;
		int m_NumScalings;

		glm::mat4 m_LocalTransform;
		std::string m_Name;
		int m_Id;
	};
}

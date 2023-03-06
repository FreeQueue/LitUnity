#include "game/graphics/animation/bone.h"
#include "glm/gtx/quaternion.hpp"
#include "game/SourceHeader.h"

Bone::Bone(string name, int id, const aiNodeAnim* channel):
	m_LocalTransform(1.0f),
	m_Name(move(name)),
	m_Id(id)
{
	m_NumPositions = channel->mNumPositionKeys;

	for (int positionIndex = 0; positionIndex < m_NumPositions; ++positionIndex)
	{
		aiVector3D aiPosition = channel->mPositionKeys[positionIndex].mValue;
		float timeStamp = channel->mPositionKeys[positionIndex].mTime;
		KeyPosition data{};
		data.position = TypeUtil::GlmVec3(aiPosition);
		data.timeStamp = timeStamp;
		m_Positions.push_back(data);
	}

	m_NumRotations = channel->mNumRotationKeys;
	for (int rotationIndex = 0; rotationIndex < m_NumRotations; ++rotationIndex)
	{
		aiQuaternion aiOrientation = channel->mRotationKeys[rotationIndex].mValue;
		float timeStamp = channel->mRotationKeys[rotationIndex].mTime;
		KeyRotation data{};
		data.orientation = TypeUtil::GlmQuat(aiOrientation);
		data.timeStamp = timeStamp;
		m_Rotations.push_back(data);
	}

	m_NumScalings = channel->mNumScalingKeys;
	for (int keyIndex = 0; keyIndex < m_NumScalings; ++keyIndex)
	{
		aiVector3D scale = channel->mScalingKeys[keyIndex].mValue;
		float timeStamp = channel->mScalingKeys[keyIndex].mTime;
		KeyScale data{};
		data.scale = TypeUtil::GlmVec3(scale);
		data.timeStamp = timeStamp;
		m_Scales.push_back(data);
	}
}

void Bone::Update(const float animationTime)
{
	mat4 translation = InterpolatePosition(animationTime);
	mat4 rotation = InterpolateRotation(animationTime);
	mat4 scale = InterpolateScaling(animationTime);
	m_LocalTransform = translation * rotation * scale;
}

int Bone::GetPositionIndex(const float animationTime) const
{
	for (int index = 0; index < m_NumPositions - 1; ++index)
	{
		if (animationTime < m_Positions[index + 1].timeStamp)
			return index;
	}
	assert(0);
	return 0;
}

int Bone::GetRotationIndex(const float animationTime) const
{
	for (int index = 0; index < m_NumRotations - 1; ++index)
	{
		if (animationTime < m_Rotations[index + 1].timeStamp)
			return index;
	}
	assert(0);
	return 0;
}

int Bone::GetScaleIndex(const float animationTime) const
{
	for (int index = 0; index < m_NumScalings - 1; ++index)
	{
		if (animationTime < m_Scales[index + 1].timeStamp)
			return index;
	}
	assert(0);
	return 0;
}

float Bone::GetScaleFactor(float lastTimeStamp, float nextTimeStamp, float animationTime)
{
	const float midWayLength = animationTime - lastTimeStamp;
	const float framesDiff = nextTimeStamp - lastTimeStamp;
	float scaleFactor = midWayLength / framesDiff;
	return scaleFactor;
}

mat4 Bone::InterpolatePosition(const float animationTime)
{
	if (1 == m_NumPositions)
		return translate(mat4(1.0f), m_Positions[0].position);

	int p0Index = GetPositionIndex(animationTime);
	int p1Index = p0Index + 1;
	float scaleFactor = GetScaleFactor(m_Positions[p0Index].timeStamp,
										m_Positions[p1Index].timeStamp, animationTime);
	vec3 finalPosition = mix(m_Positions[p0Index].position, m_Positions[p1Index].position
							, scaleFactor);
	return translate(mat4(1.0f), finalPosition);
}

mat4 Bone::InterpolateRotation(const float animationTime)
{
	if (1 == m_NumRotations)
	{
		auto rotation = normalize(m_Rotations[0].orientation);
		return toMat4(rotation);
	}

	int p0Index = GetRotationIndex(animationTime);
	int p1Index = p0Index + 1;
	float scaleFactor = GetScaleFactor(m_Rotations[p0Index].timeStamp,
										m_Rotations[p1Index].timeStamp, animationTime);
	quat finalRotation = slerp(m_Rotations[p0Index].orientation, m_Rotations[p1Index].orientation
								, scaleFactor);
	finalRotation = normalize(finalRotation);
	return toMat4(finalRotation);
}

mat4 Bone::InterpolateScaling(const float animationTime)
{
	if (1 == m_NumScalings)
		return scale(mat4(1.0f), m_Scales[0].scale);

	int p0Index = GetScaleIndex(animationTime);
	int p1Index = p0Index + 1;
	float scaleFactor = GetScaleFactor(m_Scales[p0Index].timeStamp,
										m_Scales[p1Index].timeStamp, animationTime);
	vec3 finalScale = mix(m_Scales[p0Index].scale, m_Scales[p1Index].scale
						, scaleFactor);
	return scale(mat4(1.0f), finalScale);
}

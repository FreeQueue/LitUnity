#include "game/graphics/animation/Animator.h"
#include "game/SourceHeader.h"

Animator::Animator(Animation* animation)
{
	m_CurrentTime = 0.0;
	m_CurrentAnimation = animation;

	m_FinalBoneMatrices.reserve(100);

	for (int i = 0; i < 100; i++)
		m_FinalBoneMatrices.push_back(mat4(1.0f));
}

void Animator::UpdateAnimation(float dt)
{
	m_DeltaTime = dt;
	if (m_CurrentAnimation)
	{
		m_CurrentTime += m_CurrentAnimation->GetTicksPerSecond() * dt;
		m_CurrentTime = fmod(m_CurrentTime, m_CurrentAnimation->GetDuration());
		CalculateBoneTransform(&m_CurrentAnimation->GetRootNode(), mat4(1.0f));
	}
}

void Animator::PlayAnimation(Animation* pAnimation)
{
	m_CurrentAnimation = pAnimation;
	m_CurrentTime = 0.0f;
}

void Animator::CalculateBoneTransform(const AssimpNodeData* node, mat4 parentTransform)
{
	std::string nodeName = node->name;
	mat4 nodeTransform = node->transformation;

	Bone* Bone = m_CurrentAnimation->FindBone(nodeName);

	if (Bone)
	{
		Bone->Update(m_CurrentTime);
		nodeTransform = Bone->GetLocalTransform();
	}

	mat4 globalTransformation = parentTransform * nodeTransform;

	auto boneInfoMap = m_CurrentAnimation->GetBoneIdMap();
	if (boneInfoMap.find(nodeName) != boneInfoMap.end())
	{
		int index = boneInfoMap[nodeName].id;
		mat4 offset = boneInfoMap[nodeName].offset;
		m_FinalBoneMatrices[index] = globalTransformation * offset;
	}

	for (int i = 0; i < node->childrenCount; i++)
		CalculateBoneTransform(&node->children[i], globalTransformation);
}

std::vector<mat4> Animator::GetFinalBoneMatrices()
{
	return m_FinalBoneMatrices;
}

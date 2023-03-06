#include "game/base/Transform.h"
#include <glm/gtc/quaternion.hpp>

#include "game/SourceHeader.h"

mat4 Transform::GetLocalModelMatrix()
{
	// translation * rotation * scale (also know as TRS matrix)
	return translate(mat4(1.0f), m_Pos) * mat4_cast(m_Rotation) * scale(
		mat4(1.0f), m_Scale);
}

void Transform::ComputeModelMatrix()
{
	m_ModelMatrix = GetLocalModelMatrix();
}

void Transform::ComputeModelMatrix(const mat4& parentGlobalModelMatrix)
{
	m_ModelMatrix = parentGlobalModelMatrix * GetLocalModelMatrix();
}

void Transform::AddLocalPosition(const vec3& addPosition)
{
	m_Pos += addPosition;
	m_IsDirty = true;
}

void Transform::AddLocalRotation(const quat& addRotation)
{
	m_Rotation += addRotation;
	m_IsDirty = true;
}

void Transform::AddLocalScale(const vec3& addScale)
{
	m_Scale += addScale;
	m_IsDirty = true;
}

void Transform::SetLocalPosition(const vec3& newPosition)
{
	m_Pos = newPosition;
	m_IsDirty = true;
}

void Transform::SetLocalRotation(const quat& newRotation)
{
	m_Rotation = newRotation;
	m_IsDirty = true;
}

void Transform::SetLocalScale(const vec3& newScale)
{
	m_Scale = newScale;
	m_IsDirty = true;
}

vec3 Transform::GetGlobalPosition() const
{
	return m_ModelMatrix[3];
}

const vec3& Transform::GetLocalPosition() const
{
	return m_Pos;
}

const quat& Transform::GetLocalRotation() const
{
	return m_Rotation;
}

const vec3& Transform::GetLocalScale() const
{
	return m_Scale;
}

const mat4& Transform::GetModelMatrix() const
{
	return m_ModelMatrix;
}

vec3 Transform::GetRight() const
{
	return m_ModelMatrix[0];
}

vec3 Transform::GetUp() const
{
	return m_ModelMatrix[1];
}

vec3 Transform::GetBackward() const
{
	return m_ModelMatrix[2];
}

vec3 Transform::GetForward() const
{
	return -m_ModelMatrix[2];
}

vec3 Transform::GetGlobalScale() const
{
	return {length(GetRight()), length(GetUp()), length(GetBackward())};
}

bool Transform::IsDirty() const
{
	return m_IsDirty;
}

void Transform::Serialize(XMLElement* element)
{
	element->SetAttribute("pos", StringUtil::WriteVec3(m_Pos).c_str());
	element->SetAttribute("rotation",
						StringUtil::WriteVec4(TypeUtil::GlmVec4(m_Rotation)).
						c_str());
	element->SetAttribute("scale", StringUtil::WriteVec3(m_Scale).c_str());
}

void Transform::Deserialize(XMLElement* element)
{
	m_IsDirty = true;
	m_Pos = StringUtil::ParseVec3(element->Attribute("pos","0"));
	m_Rotation = TypeUtil::GlmQuat(
		StringUtil::ParseVec4(element->Attribute("rotation","0")));
	m_Scale = StringUtil::ParseVec3(element->Attribute("scale","1"));
}

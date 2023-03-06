#pragma once
#include <assimp/matrix4x4.h>
#include <assimp/quaternion.h>
#include <assimp/vector3.h>

#include<glm/glm.hpp>
#include<glm/gtc/quaternion.hpp>

class TypeUtil
{
public:
	//assimp-glm
	static glm::mat4 GlmMat4(const aiMatrix4x4& from);

	static glm::vec3 GlmVec3(const aiVector3D& from);

	static glm::quat GlmQuat(const aiQuaternion& from);
	//glm
	static glm::vec4 GlmVec4(const glm::quat& from);
	static glm::quat GlmQuat(const glm::vec4& from);
};

#include "game/utils/TypeUtil.h"
#include "game/SourceHeader.h"

mat4 TypeUtil::GlmMat4(const aiMatrix4x4& from)
{
	mat4 to;
	//the a,b,c,d in assimp is the row ; the 1,2,3,4 is the column
	to[0][0] = from.a1;
	to[1][0] = from.a2;
	to[2][0] = from.a3;
	to[3][0] = from.a4;
	to[0][1] = from.b1;
	to[1][1] = from.b2;
	to[2][1] = from.b3;
	to[3][1] = from.b4;
	to[0][2] = from.c1;
	to[1][2] = from.c2;
	to[2][2] = from.c3;
	to[3][2] = from.c4;
	to[0][3] = from.d1;
	to[1][3] = from.d2;
	to[2][3] = from.d3;
	to[3][3] = from.d4;
	return to;
}

vec3 TypeUtil::GlmVec3(const aiVector3D& from)
{
	return {from.x, from.y, from.z};
}

quat TypeUtil::GlmQuat(const aiQuaternion& from)
{
	return {from.w, from.x, from.y, from.z};
}

vec4 TypeUtil::GlmVec4(const quat& from)
{
	return {from.x, from.y, from.z, from.w};
}

quat TypeUtil::GlmQuat(const vec4& from)
{
	return {from.w, from.x, from.y, from.z};
}

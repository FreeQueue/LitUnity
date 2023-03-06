/// @ref gtx_normal

namespace glm
{
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> triangleNormal
	(
		const vec<3, T, Q>& p1,
		const vec<3, T, Q>& p2,
		const vec<3, T, Q>& p3
	)
	{
		return normalize(cross(p1 - p2, p1 - p3));
	}
} //namespace glm

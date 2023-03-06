/// @ref gtx_handed_coordinate_space

namespace glm
{
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER bool rightHanded
	(
		const vec<3, T, Q>& tangent,
		const vec<3, T, Q>& binormal,
		const vec<3, T, Q>& normal
	)
	{
		return dot(cross(normal, tangent), binormal) > T(0);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER bool leftHanded
	(
		const vec<3, T, Q>& tangent,
		const vec<3, T, Q>& binormal,
		const vec<3, T, Q>& normal
	)
	{
		return dot(cross(normal, tangent), binormal) < T(0);
	}
} //namespace glm

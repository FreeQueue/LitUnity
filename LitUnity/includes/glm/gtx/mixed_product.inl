/// @ref gtx_mixed_product

namespace glm
{
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T mixedProduct
	(
		const vec<3, T, Q>& v1,
		const vec<3, T, Q>& v2,
		const vec<3, T, Q>& v3
	)
	{
		return dot(cross(v1, v2), v3);
	}
} //namespace glm

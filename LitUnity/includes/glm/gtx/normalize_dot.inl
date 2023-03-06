/// @ref gtx_normalize_dot

namespace glm
{
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T normalizeDot(const vec<L, T, Q>& x, const vec<L, T, Q>& y)
	{
		return glm::dot(x, y) * glm::inversesqrt(glm::dot(x, x) * glm::dot(y, y));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T fastNormalizeDot(const vec<L, T, Q>& x, const vec<L, T, Q>& y)
	{
		return glm::dot(x, y) * glm::fastInverseSqrt(glm::dot(x, x) * glm::dot(y, y));
	}
} //namespace glm

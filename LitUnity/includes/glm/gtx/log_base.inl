/// @ref gtx_log_base

namespace glm
{
	template <typename genType>
	GLM_FUNC_QUALIFIER genType log(const genType& x, const genType& base)
	{
		return glm::log(x) / glm::log(base);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> log(const vec<L, T, Q>& x, const vec<L, T, Q>& base)
	{
		return glm::log(x) / glm::log(base);
	}
} //namespace glm

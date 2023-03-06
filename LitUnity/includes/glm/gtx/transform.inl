/// @ref gtx_transform

namespace glm
{
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> translate(const vec<3, T, Q>& v)
	{
		return translate(mat<4, 4, T, Q>(static_cast<T>(1)), v);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> rotate(T angle, const vec<3, T, Q>& v)
	{
		return rotate(mat<4, 4, T, Q>(static_cast<T>(1)), angle, v);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> scale(const vec<3, T, Q>& v)
	{
		return scale(mat<4, 4, T, Q>(static_cast<T>(1)), v);
	}
} //namespace glm

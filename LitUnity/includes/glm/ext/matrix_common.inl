#include "../matrix.hpp"

namespace glm
{
	template <length_t C, length_t R, typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER mat<C, R, T, Q> mix(const mat<C, R, T, Q>& x, const mat<C, R, T, Q>& y, U a)
	{
		return mat<C, R, U, Q>(x) * (static_cast<U>(1) - a) + mat<C, R, U, Q>(y) * a;
	}

	template <length_t C, length_t R, typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER mat<C, R, T, Q> mix(const mat<C, R, T, Q>& x, const mat<C, R, T, Q>& y, const mat<C, R, U, Q>& a)
	{
		return matrixCompMult(mat<C, R, U, Q>(x), static_cast<U>(1) - a) + matrixCompMult(mat<C, R, U, Q>(y), a);
	}
} //namespace glm

/// @ref gtx_matrix_transform_2d
/// @author Miguel Ángel Pérez Martínez

#include "../trigonometric.hpp"

namespace glm
{
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<3, 3, T, Q> translate(
		const mat<3, 3, T, Q>& m,
		const vec<2, T, Q>& v)
	{
		mat<3, 3, T, Q> Result(m);
		Result[2] = m[0] * v[0] + m[1] * v[1] + m[2];
		return Result;
	}


	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<3, 3, T, Q> rotate(
		const mat<3, 3, T, Q>& m,
		T angle)
	{
		const T a = angle;
		const T c = cos(a);
		const T s = sin(a);

		mat<3, 3, T, Q> Result;
		Result[0] = m[0] * c + m[1] * s;
		Result[1] = m[0] * -s + m[1] * c;
		Result[2] = m[2];
		return Result;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<3, 3, T, Q> scale(
		const mat<3, 3, T, Q>& m,
		const vec<2, T, Q>& v)
	{
		mat<3, 3, T, Q> Result;
		Result[0] = m[0] * v[0];
		Result[1] = m[1] * v[1];
		Result[2] = m[2];
		return Result;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<3, 3, T, Q> shearX(
		const mat<3, 3, T, Q>& m,
		T y)
	{
		mat<3, 3, T, Q> Result(1);
		Result[0][1] = y;
		return m * Result;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<3, 3, T, Q> shearY(
		const mat<3, 3, T, Q>& m,
		T x)
	{
		mat<3, 3, T, Q> Result(1);
		Result[1][0] = x;
		return m * Result;
	}
} //namespace glm

#include "../vector_relational.hpp"
#include "../common.hpp"
#include "../detail/qualifier.hpp"
#include "../detail/type_float.hpp"

namespace glm
{
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> equal(const vec<L, T, Q>& x, const vec<L, T, Q>& y, T Epsilon)
	{
		return equal(x, y, vec<L, T, Q>(Epsilon));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> equal(const vec<L, T, Q>& x, const vec<L, T, Q>& y,
															const vec<L, T, Q>& Epsilon)
	{
		return lessThanEqual(abs(x - y), Epsilon);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> notEqual(const vec<L, T, Q>& x, const vec<L, T, Q>& y, T Epsilon)
	{
		return notEqual(x, y, vec<L, T, Q>(Epsilon));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> notEqual(const vec<L, T, Q>& x, const vec<L, T, Q>& y,
															const vec<L, T, Q>& Epsilon)
	{
		return greaterThan(abs(x - y), Epsilon);
	}


	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> equal(const vec<L, T, Q>& x, const vec<L, T, Q>& y, int MaxULPs)
	{
		return equal(x, y, vec<L, int, Q>(MaxULPs));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> equal(const vec<L, T, Q>& x, const vec<L, T, Q>& y,
															const vec<L, int, Q>& MaxULPs)
	{
		vec<L, bool, Q> Result(false);
		for (length_t i = 0; i < L; ++i)
		{
			const detail::float_t<T> a(x[i]);
			const detail::float_t<T> b(y[i]);

			// Different signs means they do not match.
			if (a.negative() != b.negative())
			{
				// Check for equality to make sure +0==-0
				Result[i] = a.mantissa() == b.mantissa() && a.exponent() == b.exponent();
			}
			else
			{
				// Find the difference in ULPs.
				const typename detail::float_t<T>::int_type DiffULPs = abs(a.i - b.i);
				Result[i] = DiffULPs <= MaxULPs[i];
			}
		}
		return Result;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> notEqual(const vec<L, T, Q>& x, const vec<L, T, Q>& y, int MaxULPs)
	{
		return notEqual(x, y, vec<L, int, Q>(MaxULPs));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> notEqual(const vec<L, T, Q>& x, const vec<L, T, Q>& y,
															const vec<L, int, Q>& MaxULPs)
	{
		return not_(equal(x, y, MaxULPs));
	}
} //namespace glm

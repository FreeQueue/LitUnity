/// @ref gtx_norm

#include "../detail/qualifier.hpp"

namespace glm
{
	namespace detail
	{
		template <length_t L, typename T, qualifier Q, bool Aligned>
		struct compute_length2
		{
			GLM_FUNC_QUALIFIER static T call(const vec<L, T, Q>& v)
			{
				return dot(v, v);
			}
		};
	} //namespace detail

	template <typename genType>
	GLM_FUNC_QUALIFIER genType length2(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'length2' accepts only floating-point inputs");
		return x * x;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T length2(const vec<L, T, Q>& v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'length2' accepts only floating-point inputs");
		return detail::compute_length2<L, T, Q, detail::is_aligned<Q>::value>::call(v);
	}

	template <typename T>
	GLM_FUNC_QUALIFIER T distance2(T p0, T p1)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'distance2' accepts only floating-point inputs");
		return length2(p1 - p0);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T distance2(const vec<L, T, Q>& p0, const vec<L, T, Q>& p1)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'distance2' accepts only floating-point inputs");
		return length2(p1 - p0);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T l1Norm(const vec<3, T, Q>& a, const vec<3, T, Q>& b)
	{
		return abs(b.x - a.x) + abs(b.y - a.y) + abs(b.z - a.z);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T l1Norm(const vec<3, T, Q>& v)
	{
		return abs(v.x) + abs(v.y) + abs(v.z);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T l2Norm(const vec<3, T, Q>& a, const vec<3, T, Q>& b
	)
	{
		return length(b - a);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T l2Norm(const vec<3, T, Q>& v)
	{
		return length(v);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T lxNorm(const vec<3, T, Q>& x, const vec<3, T, Q>& y, unsigned int Depth)
	{
		return pow(pow(abs(y.x - x.x), T(Depth)) + pow(abs(y.y - x.y), T(Depth)) + pow(abs(y.z - x.z), T(Depth)),
					T(1) / T(Depth));
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T lxNorm(const vec<3, T, Q>& v, unsigned int Depth)
	{
		return pow(pow(abs(v.x), T(Depth)) + pow(abs(v.y), T(Depth)) + pow(abs(v.z), T(Depth)), T(1) / T(Depth));
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T lMaxNorm(const vec<3, T, Q>& a, const vec<3, T, Q>& b)
	{
		return compMax(abs(b - a));
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T lMaxNorm(const vec<3, T, Q>& v)
	{
		return compMax(abs(v));
	}
} //namespace glm

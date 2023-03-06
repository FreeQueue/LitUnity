/// @ref gtx_common

#include <cmath>
#include "../gtc/epsilon.hpp"
#include "../gtc/constants.hpp"

namespace glm
{
	namespace detail
	{
		template <length_t L, typename T, qualifier Q, bool isFloat = true>
		struct compute_fmod
		{
			GLM_FUNC_QUALIFIER static vec<L, T, Q> call(const vec<L, T, Q>& a, const vec<L, T, Q>& b)
			{
				return functor2<vec, L, T, Q>::call(std::fmod, a, b);
			}
		};

		template <length_t L, typename T, qualifier Q>
		struct compute_fmod<L, T, Q, false>
		{
			GLM_FUNC_QUALIFIER static vec<L, T, Q> call(const vec<L, T, Q>& a, const vec<L, T, Q>& b)
			{
				return a % b;
			}
		};
	} //namespace detail

	template <typename T>
	GLM_FUNC_QUALIFIER bool isdenormal(const T& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isdenormal' only accept floating-point inputs");

#		if GLM_HAS_CXX11_STL
		return std::fpclassify(x) == FP_SUBNORMAL;
#		else
			return epsilonNotEqual(x, static_cast<T>(0), epsilon<T>()) && std::fabs(x) < std::numeric_limits<T>::min();
#		endif
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER typename vec<1, T, Q>::bool_type isdenormal
	(
		const vec<1, T, Q>& x
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isdenormal' only accept floating-point inputs");

		return typename vec<1, T, Q>::bool_type(
			isdenormal(x.x));
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER typename vec<2, T, Q>::bool_type isdenormal
	(
		const vec<2, T, Q>& x
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isdenormal' only accept floating-point inputs");

		return typename vec<2, T, Q>::bool_type(
			isdenormal(x.x),
			isdenormal(x.y));
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER typename vec<3, T, Q>::bool_type isdenormal
	(
		const vec<3, T, Q>& x
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isdenormal' only accept floating-point inputs");

		return typename vec<3, T, Q>::bool_type(
			isdenormal(x.x),
			isdenormal(x.y),
			isdenormal(x.z));
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER typename vec<4, T, Q>::bool_type isdenormal
	(
		const vec<4, T, Q>& x
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isdenormal' only accept floating-point inputs");

		return typename vec<4, T, Q>::bool_type(
			isdenormal(x.x),
			isdenormal(x.y),
			isdenormal(x.z),
			isdenormal(x.w));
	}

	// fmod
	template <typename genType>
	GLM_FUNC_QUALIFIER genType fmod(genType x, genType y)
	{
		return fmod(vec<1, genType>(x), y).x;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fmod(const vec<L, T, Q>& x, T y)
	{
		return detail::compute_fmod<L, T, Q, std::numeric_limits<T>::is_iec559>::call(x, vec<L, T, Q>(y));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fmod(const vec<L, T, Q>& x, const vec<L, T, Q>& y)
	{
		return detail::compute_fmod<L, T, Q, std::numeric_limits<T>::is_iec559>::call(x, y);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, bool, Q> openBounded(const vec<L, T, Q>& Value, const vec<L, T, Q>& Min,
													const vec<L, T, Q>& Max)
	{
		return greaterThan(Value, Min) && lessThan(Value, Max);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, bool, Q> closeBounded(const vec<L, T, Q>& Value, const vec<L, T, Q>& Min,
													const vec<L, T, Q>& Max)
	{
		return greaterThanEqual(Value, Min) && lessThanEqual(Value, Max);
	}
} //namespace glm

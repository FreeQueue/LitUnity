#include "scalar_integer.hpp"

namespace glm
{
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, bool, Q> isPowerOfTwo(const vec<L, T, Q>& Value)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'isPowerOfTwo' only accept integer inputs");

		const vec<L, T, Q> Result(abs(Value));
		return equal(Result & (Result - vec<L, T, Q>(1)), vec<L, T, Q>(0));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> nextPowerOfTwo(const vec<L, T, Q>& v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'nextPowerOfTwo' only accept integer inputs");

		return detail::compute_ceilPowerOfTwo<L, T, Q, std::numeric_limits<T>::is_signed>::call(v);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> prevPowerOfTwo(const vec<L, T, Q>& v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'prevPowerOfTwo' only accept integer inputs");

		return detail::functor1<vec, L, T, T, Q>::call(prevPowerOfTwo, v);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, bool, Q> isMultiple(const vec<L, T, Q>& Value, T Multiple)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'isMultiple' only accept integer inputs");

		return (Value % Multiple) == vec<L, T, Q>(0);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, bool, Q> isMultiple(const vec<L, T, Q>& Value, const vec<L, T, Q>& Multiple)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'isMultiple' only accept integer inputs");

		return (Value % Multiple) == vec<L, T, Q>(0);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> nextMultiple(const vec<L, T, Q>& Source, T Multiple)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'nextMultiple' only accept integer inputs");

		return detail::functor2<vec, L, T, Q>::call(nextMultiple, Source, vec<L, T, Q>(Multiple));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> nextMultiple(const vec<L, T, Q>& Source, const vec<L, T, Q>& Multiple)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'nextMultiple' only accept integer inputs");

		return detail::functor2<vec, L, T, Q>::call(nextMultiple, Source, Multiple);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> prevMultiple(const vec<L, T, Q>& Source, T Multiple)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'prevMultiple' only accept integer inputs");

		return detail::functor2<vec, L, T, Q>::call(prevMultiple, Source, vec<L, T, Q>(Multiple));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> prevMultiple(const vec<L, T, Q>& Source, const vec<L, T, Q>& Multiple)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'prevMultiple' only accept integer inputs");

		return detail::functor2<vec, L, T, Q>::call(prevMultiple, Source, Multiple);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, int, Q> findNSB(const vec<L, T, Q>& Source, vec<L, int, Q> SignificantBitCount)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'findNSB' only accept integer inputs");

		return detail::functor2_vec_int<L, T, Q>::call(findNSB, Source, SignificantBitCount);
	}
} //namespace glm

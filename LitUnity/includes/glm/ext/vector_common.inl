#include "../detail/_vectorize.hpp"

namespace glm
{
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> min(const vec<L, T, Q>& x, const vec<L, T, Q>& y,
													const vec<L, T, Q>& z)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'min' only accept floating-point or integer inputs");
		return glm::min(glm::min(x, y), z);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> min(const vec<L, T, Q>& x, const vec<L, T, Q>& y,
													const vec<L, T, Q>& z, const vec<L, T, Q>& w)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'min' only accept floating-point or integer inputs");
		return glm::min(glm::min(x, y), glm::min(z, w));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> max(const vec<L, T, Q>& x, const vec<L, T, Q>& y,
													const vec<L, T, Q>& z)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'max' only accept floating-point or integer inputs");
		return glm::max(glm::max(x, y), z);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> max(const vec<L, T, Q>& x, const vec<L, T, Q>& y,
													const vec<L, T, Q>& z, const vec<L, T, Q>& w)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'max' only accept floating-point or integer inputs");
		return glm::max(glm::max(x, y), glm::max(z, w));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fmin(const vec<L, T, Q>& a, T b)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmin' only accept floating-point inputs");
		return detail::functor2<vec, L, T, Q>::call(fmin, a, vec<L, T, Q>(b));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fmin(const vec<L, T, Q>& a, const vec<L, T, Q>& b)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmin' only accept floating-point inputs");
		return detail::functor2<vec, L, T, Q>::call(fmin, a, b);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fmin(const vec<L, T, Q>& a, const vec<L, T, Q>& b, const vec<L, T, Q>& c)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmin' only accept floating-point inputs");
		return fmin(fmin(a, b), c);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fmin(const vec<L, T, Q>& a, const vec<L, T, Q>& b, const vec<L, T, Q>& c,
										const vec<L, T, Q>& d)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmin' only accept floating-point inputs");
		return fmin(fmin(a, b), fmin(c, d));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fmax(const vec<L, T, Q>& a, T b)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmax' only accept floating-point inputs");
		return detail::functor2<vec, L, T, Q>::call(fmax, a, vec<L, T, Q>(b));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fmax(const vec<L, T, Q>& a, const vec<L, T, Q>& b)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmax' only accept floating-point inputs");
		return detail::functor2<vec, L, T, Q>::call(fmax, a, b);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fmax(const vec<L, T, Q>& a, const vec<L, T, Q>& b, const vec<L, T, Q>& c)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmax' only accept floating-point inputs");
		return fmax(fmax(a, b), c);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fmax(const vec<L, T, Q>& a, const vec<L, T, Q>& b, const vec<L, T, Q>& c,
										const vec<L, T, Q>& d)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmax' only accept floating-point inputs");
		return fmax(fmax(a, b), fmax(c, d));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fclamp(const vec<L, T, Q>& x, T minVal, T maxVal)
	{
		return fmin(fmax(x, vec<L, T, Q>(minVal)), vec<L, T, Q>(maxVal));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fclamp(const vec<L, T, Q>& x, const vec<L, T, Q>& minVal,
											const vec<L, T, Q>& maxVal)
	{
		return fmin(fmax(x, minVal), maxVal);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> clamp(const vec<L, T, Q>& Texcoord)
	{
		return glm::clamp(Texcoord, vec<L, T, Q>(0), vec<L, T, Q>(1));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> repeat(const vec<L, T, Q>& Texcoord)
	{
		return glm::fract(Texcoord);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> mirrorClamp(const vec<L, T, Q>& Texcoord)
	{
		return glm::fract(glm::abs(Texcoord));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> mirrorRepeat(const vec<L, T, Q>& Texcoord)
	{
		const vec<L, T, Q> Abs = glm::abs(Texcoord);
		const vec<L, T, Q> Clamp = glm::mod(glm::floor(Abs), vec<L, T, Q>(2));
		const vec<L, T, Q> Floor = glm::floor(Abs);
		const vec<L, T, Q> Rest = Abs - Floor;
		const vec<L, T, Q> Mirror = Clamp + Rest;
		return mix(Rest, vec<L, T, Q>(1) - Rest, glm::greaterThanEqual(Mirror, vec<L, T, Q>(1)));
	}
} //namespace glm

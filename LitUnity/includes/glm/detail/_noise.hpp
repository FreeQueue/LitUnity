#pragma once

#include "../common.hpp"

namespace glm
{
	namespace detail
	{
		template <typename T>
		GLM_FUNC_QUALIFIER T mod289(const T& x)
		{
			return x - floor(x * (static_cast<T>(1.0) / static_cast<T>(289.0))) * static_cast<T>(289.0);
		}

		template <typename T>
		GLM_FUNC_QUALIFIER T permute(const T& x)
		{
			return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
		}

		template <typename T, qualifier Q>
		GLM_FUNC_QUALIFIER vec<2, T, Q> permute(const vec<2, T, Q>& x)
		{
			return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
		}

		template <typename T, qualifier Q>
		GLM_FUNC_QUALIFIER vec<3, T, Q> permute(const vec<3, T, Q>& x)
		{
			return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
		}

		template <typename T, qualifier Q>
		GLM_FUNC_QUALIFIER vec<4, T, Q> permute(const vec<4, T, Q>& x)
		{
			return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
		}

		template <typename T>
		GLM_FUNC_QUALIFIER T taylorInvSqrt(const T& r)
		{
			return static_cast<T>(1.79284291400159) - static_cast<T>(0.85373472095314) * r;
		}

		template <typename T, qualifier Q>
		GLM_FUNC_QUALIFIER vec<2, T, Q> taylorInvSqrt(const vec<2, T, Q>& r)
		{
			return static_cast<T>(1.79284291400159) - static_cast<T>(0.85373472095314) * r;
		}

		template <typename T, qualifier Q>
		GLM_FUNC_QUALIFIER vec<3, T, Q> taylorInvSqrt(const vec<3, T, Q>& r)
		{
			return static_cast<T>(1.79284291400159) - static_cast<T>(0.85373472095314) * r;
		}

		template <typename T, qualifier Q>
		GLM_FUNC_QUALIFIER vec<4, T, Q> taylorInvSqrt(const vec<4, T, Q>& r)
		{
			return static_cast<T>(1.79284291400159) - static_cast<T>(0.85373472095314) * r;
		}

		template <typename T, qualifier Q>
		GLM_FUNC_QUALIFIER vec<2, T, Q> fade(const vec<2, T, Q>& t)
		{
			return (t * t * t) * (t * (t * static_cast<T>(6) - static_cast<T>(15)) + static_cast<T>(10));
		}

		template <typename T, qualifier Q>
		GLM_FUNC_QUALIFIER vec<3, T, Q> fade(const vec<3, T, Q>& t)
		{
			return (t * t * t) * (t * (t * static_cast<T>(6) - static_cast<T>(15)) + static_cast<T>(10));
		}

		template <typename T, qualifier Q>
		GLM_FUNC_QUALIFIER vec<4, T, Q> fade(const vec<4, T, Q>& t)
		{
			return (t * t * t) * (t * (t * static_cast<T>(6) - static_cast<T>(15)) + static_cast<T>(10));
		}
	} //namespace detail
} //namespace glm

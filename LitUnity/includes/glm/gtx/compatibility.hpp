/// @ref gtx_compatibility
/// @file glm/gtx/compatibility.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_compatibility GLM_GTX_compatibility
/// @ingroup gtx
///
/// Include <glm/gtx/compatibility.hpp> to use the features of this extension.
///
/// Provide functions to increase the compatibility with Cg and HLSL languages

#pragma once

// Dependency:
#include "../glm.hpp"
#include "../gtc/quaternion.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_compatibility is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_compatibility extension included")
#	endif
#endif

#if GLM_COMPILER & GLM_COMPILER_VC
#	include <cfloat>
#elif GLM_COMPILER & GLM_COMPILER_GCC
#	include <cmath>
#	if(GLM_PLATFORM & GLM_PLATFORM_ANDROID)
#		undef isfinite
#	endif
#endif//GLM_COMPILER

namespace glm
{
	/// @addtogroup gtx_compatibility
	/// @{

	template <typename T>
	GLM_FUNC_QUALIFIER T lerp(T x, T y, T a) { return mix(x, y, a); }

	//!< \brief Returns x * (1.0 - a) + y * a, i.e., the linear blend of x and y using the floating-point value a. The value for a is not restricted to the range [0, 1]. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<2, T, Q> lerp(const vec<2, T, Q>& x, const vec<2, T, Q>& y, T a) { return mix(x, y, a); }

	//!< \brief Returns x * (1.0 - a) + y * a, i.e., the linear blend of x and y using the floating-point value a. The value for a is not restricted to the range [0, 1]. (From GLM_GTX_compatibility)

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> lerp(const vec<3, T, Q>& x, const vec<3, T, Q>& y, T a) { return mix(x, y, a); }

	//!< \brief Returns x * (1.0 - a) + y * a, i.e., the linear blend of x and y using the floating-point value a. The value for a is not restricted to the range [0, 1]. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, T, Q> lerp(const vec<4, T, Q>& x, const vec<4, T, Q>& y, T a) { return mix(x, y, a); }

	//!< \brief Returns x * (1.0 - a) + y * a, i.e., the linear blend of x and y using the floating-point value a. The value for a is not restricted to the range [0, 1]. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<2, T, Q>
	lerp(const vec<2, T, Q>& x, const vec<2, T, Q>& y, const vec<2, T, Q>& a) { return mix(x, y, a); }

	//!< \brief Returns the component-wise result of x * (1.0 - a) + y * a, i.e., the linear blend of x and y using vector a. The value for a is not restricted to the range [0, 1]. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q>
	lerp(const vec<3, T, Q>& x, const vec<3, T, Q>& y, const vec<3, T, Q>& a) { return mix(x, y, a); }

	//!< \brief Returns the component-wise result of x * (1.0 - a) + y * a, i.e., the linear blend of x and y using vector a. The value for a is not restricted to the range [0, 1]. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, T, Q>
	lerp(const vec<4, T, Q>& x, const vec<4, T, Q>& y, const vec<4, T, Q>& a) { return mix(x, y, a); }

	//!< \brief Returns the component-wise result of x * (1.0 - a) + y * a, i.e., the linear blend of x and y using vector a. The value for a is not restricted to the range [0, 1]. (From GLM_GTX_compatibility)

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T saturate(T x) { return clamp(x, T(0), T(1)); }

	//!< \brief Returns clamp(x, 0, 1) for each component in x. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<2, T, Q> saturate(const vec<2, T, Q>& x) { return clamp(x, T(0), T(1)); }

	//!< \brief Returns clamp(x, 0, 1) for each component in x. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> saturate(const vec<3, T, Q>& x) { return clamp(x, T(0), T(1)); }

	//!< \brief Returns clamp(x, 0, 1) for each component in x. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, T, Q> saturate(const vec<4, T, Q>& x) { return clamp(x, T(0), T(1)); }

	//!< \brief Returns clamp(x, 0, 1) for each component in x. (From GLM_GTX_compatibility)

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T atan2(T x, T y) { return atan(x, y); }

	//!< \brief Arc tangent. Returns an angle whose tangent is y/x. The signs of x and y are used to determine what quadrant the angle is in. The range of values returned by this function is [-PI, PI]. Results are undefined if x and y are both 0. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<2, T, Q> atan2(const vec<2, T, Q>& x, const vec<2, T, Q>& y) { return atan(x, y); }

	//!< \brief Arc tangent. Returns an angle whose tangent is y/x. The signs of x and y are used to determine what quadrant the angle is in. The range of values returned by this function is [-PI, PI]. Results are undefined if x and y are both 0. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> atan2(const vec<3, T, Q>& x, const vec<3, T, Q>& y) { return atan(x, y); }

	//!< \brief Arc tangent. Returns an angle whose tangent is y/x. The signs of x and y are used to determine what quadrant the angle is in. The range of values returned by this function is [-PI, PI]. Results are undefined if x and y are both 0. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, T, Q> atan2(const vec<4, T, Q>& x, const vec<4, T, Q>& y) { return atan(x, y); }

	//!< \brief Arc tangent. Returns an angle whose tangent is y/x. The signs of x and y are used to determine what quadrant the angle is in. The range of values returned by this function is [-PI, PI]. Results are undefined if x and y are both 0. (From GLM_GTX_compatibility)

	template <typename genType>
	GLM_FUNC_DECL bool isfinite(const genType& x);
	//!< \brief Test whether or not a scalar or each vector component is a finite value. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, bool, Q> isfinite(const vec<1, T, Q>& x);
	//!< \brief Test whether or not a scalar or each vector component is a finite value. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_DECL vec<2, bool, Q> isfinite(const vec<2, T, Q>& x);
	//!< \brief Test whether or not a scalar or each vector component is a finite value. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, bool, Q> isfinite(const vec<3, T, Q>& x);
	//!< \brief Test whether or not a scalar or each vector component is a finite value. (From GLM_GTX_compatibility)
	template <typename T, qualifier Q>
	GLM_FUNC_DECL vec<4, bool, Q> isfinite(const vec<4, T, Q>& x);
	//!< \brief Test whether or not a scalar or each vector component is a finite value. (From GLM_GTX_compatibility)

	using bool1 = bool; //!< \brief boolean type with 1 component. (From GLM_GTX_compatibility extension)
	using bool2 = vec<2, bool, highp>;
	//!< \brief boolean type with 2 components. (From GLM_GTX_compatibility extension)
	using bool3 = vec<3, bool, highp>;
	//!< \brief boolean type with 3 components. (From GLM_GTX_compatibility extension)
	using bool4 = vec<4, bool, highp>;
	//!< \brief boolean type with 4 components. (From GLM_GTX_compatibility extension)

	using bool1x1 = bool; //!< \brief boolean matrix with 1 x 1 component. (From GLM_GTX_compatibility extension)
	using bool2x2 = mat<2, 2, bool, highp>;
	//!< \brief boolean matrix with 2 x 2 components. (From GLM_GTX_compatibility extension)
	using bool2x3 = mat<2, 3, bool, highp>;
	//!< \brief boolean matrix with 2 x 3 components. (From GLM_GTX_compatibility extension)
	using bool2x4 = mat<2, 4, bool, highp>;
	//!< \brief boolean matrix with 2 x 4 components. (From GLM_GTX_compatibility extension)
	using bool3x2 = mat<3, 2, bool, highp>;
	//!< \brief boolean matrix with 3 x 2 components. (From GLM_GTX_compatibility extension)
	using bool3x3 = mat<3, 3, bool, highp>;
	//!< \brief boolean matrix with 3 x 3 components. (From GLM_GTX_compatibility extension)
	using bool3x4 = mat<3, 4, bool, highp>;
	//!< \brief boolean matrix with 3 x 4 components. (From GLM_GTX_compatibility extension)
	using bool4x2 = mat<4, 2, bool, highp>;
	//!< \brief boolean matrix with 4 x 2 components. (From GLM_GTX_compatibility extension)
	using bool4x3 = mat<4, 3, bool, highp>;
	//!< \brief boolean matrix with 4 x 3 components. (From GLM_GTX_compatibility extension)
	using bool4x4 = mat<4, 4, bool, highp>;
	//!< \brief boolean matrix with 4 x 4 components. (From GLM_GTX_compatibility extension)

	using int1 = int; //!< \brief integer vector with 1 component. (From GLM_GTX_compatibility extension)
	using int2 = vec<2, int, highp>;
	//!< \brief integer vector with 2 components. (From GLM_GTX_compatibility extension)
	using int3 = vec<3, int, highp>;
	//!< \brief integer vector with 3 components. (From GLM_GTX_compatibility extension)
	using int4 = vec<4, int, highp>;
	//!< \brief integer vector with 4 components. (From GLM_GTX_compatibility extension)

	using int1x1 = int; //!< \brief integer matrix with 1 component. (From GLM_GTX_compatibility extension)
	using int2x2 = mat<2, 2, int, highp>;
	//!< \brief integer matrix with 2 x 2 components. (From GLM_GTX_compatibility extension)
	using int2x3 = mat<2, 3, int, highp>;
	//!< \brief integer matrix with 2 x 3 components. (From GLM_GTX_compatibility extension)
	using int2x4 = mat<2, 4, int, highp>;
	//!< \brief integer matrix with 2 x 4 components. (From GLM_GTX_compatibility extension)
	using int3x2 = mat<3, 2, int, highp>;
	//!< \brief integer matrix with 3 x 2 components. (From GLM_GTX_compatibility extension)
	using int3x3 = mat<3, 3, int, highp>;
	//!< \brief integer matrix with 3 x 3 components. (From GLM_GTX_compatibility extension)
	using int3x4 = mat<3, 4, int, highp>;
	//!< \brief integer matrix with 3 x 4 components. (From GLM_GTX_compatibility extension)
	using int4x2 = mat<4, 2, int, highp>;
	//!< \brief integer matrix with 4 x 2 components. (From GLM_GTX_compatibility extension)
	using int4x3 = mat<4, 3, int, highp>;
	//!< \brief integer matrix with 4 x 3 components. (From GLM_GTX_compatibility extension)
	using int4x4 = mat<4, 4, int, highp>;
	//!< \brief integer matrix with 4 x 4 components. (From GLM_GTX_compatibility extension)

	using float1 = float;
	//!< \brief single-qualifier floating-point vector with 1 component. (From GLM_GTX_compatibility extension)
	using float2 = vec<2, float, highp>;
	//!< \brief single-qualifier floating-point vector with 2 components. (From GLM_GTX_compatibility extension)
	using float3 = vec<3, float, highp>;
	//!< \brief single-qualifier floating-point vector with 3 components. (From GLM_GTX_compatibility extension)
	using float4 = vec<4, float, highp>;
	//!< \brief single-qualifier floating-point vector with 4 components. (From GLM_GTX_compatibility extension)

	using float1x1 = float;
	//!< \brief single-qualifier floating-point matrix with 1 component. (From GLM_GTX_compatibility extension)
	using float2x2 = mat<2, 2, float, highp>;
	//!< \brief single-qualifier floating-point matrix with 2 x 2 components. (From GLM_GTX_compatibility extension)
	using float2x3 = mat<2, 3, float, highp>;
	//!< \brief single-qualifier floating-point matrix with 2 x 3 components. (From GLM_GTX_compatibility extension)
	using float2x4 = mat<2, 4, float, highp>;
	//!< \brief single-qualifier floating-point matrix with 2 x 4 components. (From GLM_GTX_compatibility extension)
	using float3x2 = mat<3, 2, float, highp>;
	//!< \brief single-qualifier floating-point matrix with 3 x 2 components. (From GLM_GTX_compatibility extension)
	using float3x3 = mat<3, 3, float, highp>;
	//!< \brief single-qualifier floating-point matrix with 3 x 3 components. (From GLM_GTX_compatibility extension)
	using float3x4 = mat<3, 4, float, highp>;
	//!< \brief single-qualifier floating-point matrix with 3 x 4 components. (From GLM_GTX_compatibility extension)
	using float4x2 = mat<4, 2, float, highp>;
	//!< \brief single-qualifier floating-point matrix with 4 x 2 components. (From GLM_GTX_compatibility extension)
	using float4x3 = mat<4, 3, float, highp>;
	//!< \brief single-qualifier floating-point matrix with 4 x 3 components. (From GLM_GTX_compatibility extension)
	using float4x4 = mat<4, 4, float, highp>;
	//!< \brief single-qualifier floating-point matrix with 4 x 4 components. (From GLM_GTX_compatibility extension)

	using double1 = double;
	//!< \brief double-qualifier floating-point vector with 1 component. (From GLM_GTX_compatibility extension)
	using double2 = vec<2, double, highp>;
	//!< \brief double-qualifier floating-point vector with 2 components. (From GLM_GTX_compatibility extension)
	using double3 = vec<3, double, highp>;
	//!< \brief double-qualifier floating-point vector with 3 components. (From GLM_GTX_compatibility extension)
	using double4 = vec<4, double, highp>;
	//!< \brief double-qualifier floating-point vector with 4 components. (From GLM_GTX_compatibility extension)

	using double1x1 = double;
	//!< \brief double-qualifier floating-point matrix with 1 component. (From GLM_GTX_compatibility extension)
	using double2x2 = mat<2, 2, double, highp>;
	//!< \brief double-qualifier floating-point matrix with 2 x 2 components. (From GLM_GTX_compatibility extension)
	using double2x3 = mat<2, 3, double, highp>;
	//!< \brief double-qualifier floating-point matrix with 2 x 3 components. (From GLM_GTX_compatibility extension)
	using double2x4 = mat<2, 4, double, highp>;
	//!< \brief double-qualifier floating-point matrix with 2 x 4 components. (From GLM_GTX_compatibility extension)
	using double3x2 = mat<3, 2, double, highp>;
	//!< \brief double-qualifier floating-point matrix with 3 x 2 components. (From GLM_GTX_compatibility extension)
	using double3x3 = mat<3, 3, double, highp>;
	//!< \brief double-qualifier floating-point matrix with 3 x 3 components. (From GLM_GTX_compatibility extension)
	using double3x4 = mat<3, 4, double, highp>;
	//!< \brief double-qualifier floating-point matrix with 3 x 4 components. (From GLM_GTX_compatibility extension)
	using double4x2 = mat<4, 2, double, highp>;
	//!< \brief double-qualifier floating-point matrix with 4 x 2 components. (From GLM_GTX_compatibility extension)
	using double4x3 = mat<4, 3, double, highp>;
	//!< \brief double-qualifier floating-point matrix with 4 x 3 components. (From GLM_GTX_compatibility extension)
	using double4x4 = mat<4, 4, double, highp>;
	//!< \brief double-qualifier floating-point matrix with 4 x 4 components. (From GLM_GTX_compatibility extension)

	/// @}
} //namespace glm

#include "compatibility.inl"

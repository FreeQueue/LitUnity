/// @ref gtx_closest_point
/// @file glm/gtx/closest_point.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_closest_point GLM_GTX_closest_point
/// @ingroup gtx
///
/// Include <glm/gtx/closest_point.hpp> to use the features of this extension.
///
/// Find the point on a straight line which is the closet of a point.

#pragma once

// Dependency:
#include "../glm.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_closest_point is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_closest_point extension included")
#	endif
#endif

namespace glm
{
	/// @addtogroup gtx_closest_point
	/// @{

	/// Find the point on a straight line which is the closet of a point.
	/// @see gtx_closest_point
	template <typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> closestPointOnLine(
		const vec<3, T, Q>& point,
		const vec<3, T, Q>& a,
		const vec<3, T, Q>& b);

	/// 2d lines work as well
	template <typename T, qualifier Q>
	GLM_FUNC_DECL vec<2, T, Q> closestPointOnLine(
		const vec<2, T, Q>& point,
		const vec<2, T, Q>& a,
		const vec<2, T, Q>& b);

	/// @}
} // namespace glm

#include "closest_point.inl"

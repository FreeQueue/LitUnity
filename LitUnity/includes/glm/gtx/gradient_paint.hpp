/// @ref gtx_gradient_paint
/// @file glm/gtx/gradient_paint.hpp
///
/// @see core (dependence)
/// @see gtx_optimum_pow (dependence)
///
/// @defgroup gtx_gradient_paint GLM_GTX_gradient_paint
/// @ingroup gtx
///
/// Include <glm/gtx/gradient_paint.hpp> to use the features of this extension.
///
/// Functions that return the color of procedural gradient for specific coordinates.

#pragma once

// Dependency:
#include "../glm.hpp"
#include "../gtx/optimum_pow.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_gradient_paint is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_gradient_paint extension included")
#	endif
#endif

namespace glm
{
	/// @addtogroup gtx_gradient_paint
	/// @{

	/// Return a color from a radial gradient.
	/// @see - gtx_gradient_paint
	template <typename T, qualifier Q>
	GLM_FUNC_DECL T radialGradient(
		const vec<2, T, Q>& Center,
		const T& Radius,
		const vec<2, T, Q>& Focal,
		const vec<2, T, Q>& Position);

	/// Return a color from a linear gradient.
	/// @see - gtx_gradient_paint
	template <typename T, qualifier Q>
	GLM_FUNC_DECL T linearGradient(
		const vec<2, T, Q>& Point0,
		const vec<2, T, Q>& Point1,
		const vec<2, T, Q>& Position);

	/// @}
} // namespace glm

#include "gradient_paint.inl"

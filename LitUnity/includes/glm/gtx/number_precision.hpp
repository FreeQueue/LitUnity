/// @ref gtx_number_precision
/// @file glm/gtx/number_precision.hpp
///
/// @see core (dependence)
/// @see gtc_type_precision (dependence)
/// @see gtc_quaternion (dependence)
///
/// @defgroup gtx_number_precision GLM_GTX_number_precision
/// @ingroup gtx
///
/// Include <glm/gtx/number_precision.hpp> to use the features of this extension.
///
/// Defined size types.

#pragma once

// Dependency:
#include "../glm.hpp"
#include "../gtc/type_precision.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_number_precision is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_number_precision extension included")
#	endif
#endif

namespace glm
{
	namespace gtx
	{
		/////////////////////////////
		// Unsigned int vector types

		/// @addtogroup gtx_number_precision
		/// @{

		using u8vec1 = u8; //!< \brief 8bit unsigned integer scalar. (from GLM_GTX_number_precision extension)
		using u16vec1 = u16; //!< \brief 16bit unsigned integer scalar. (from GLM_GTX_number_precision extension)
		using u32vec1 = u32; //!< \brief 32bit unsigned integer scalar. (from GLM_GTX_number_precision extension)
		using u64vec1 = u64; //!< \brief 64bit unsigned integer scalar. (from GLM_GTX_number_precision extension)

		//////////////////////
		// Float vector types

		using f32vec1 = f32;
		//!< \brief Single-qualifier floating-point scalar. (from GLM_GTX_number_precision extension)
		using f64vec1 = f64;
		//!< \brief Single-qualifier floating-point scalar. (from GLM_GTX_number_precision extension)

		//////////////////////
		// Float matrix types

		using f32mat1 = f32;
		//!< \brief Single-qualifier floating-point scalar. (from GLM_GTX_number_precision extension)
		using f32mat1x1 = f32;
		//!< \brief Single-qualifier floating-point scalar. (from GLM_GTX_number_precision extension)
		using f64mat1 = f64;
		//!< \brief Double-qualifier floating-point scalar. (from GLM_GTX_number_precision extension)
		using f64mat1x1 = f64;
		//!< \brief Double-qualifier floating-point scalar. (from GLM_GTX_number_precision extension)

		/// @}
	} //namespace gtx
} //namespace glm

#include "number_precision.inl"

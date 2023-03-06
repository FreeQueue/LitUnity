/// @ref ext_quaternion_double_precision
/// @file glm/ext/quaternion_double_precision.hpp
///
/// @defgroup ext_quaternion_double_precision GLM_EXT_quaternion_double_precision
/// @ingroup ext
///
/// Exposes double-precision floating point quaternion type with various precision in term of ULPs.
///
/// Include <glm/ext/quaternion_double_precision.hpp> to use the features of this extension.

#pragma once

// Dependency:
#include "../detail/type_quat.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_quaternion_double_precision extension included")
#endif

namespace glm
{
	/// @addtogroup ext_quaternion_double_precision
	/// @{

	/// Quaternion of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	using lowp_dquat = qua<double, lowp>;

	/// Quaternion of medium double-qualifier floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	using mediump_dquat = qua<double, mediump>;

	/// Quaternion of high double-qualifier floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	using highp_dquat = qua<double, highp>;

	/// @}
} //namespace glm

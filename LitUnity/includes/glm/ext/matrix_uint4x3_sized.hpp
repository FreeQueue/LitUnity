/// @ref ext_matrix_uint4x3_sized
/// @file glm/ext/matrix_uint4x3_sized.hpp
///
/// @see core (dependence)
///
/// @defgroup ext_matrix_uint4x3_sized GLM_EXT_matrix_uint4x3_sized
/// @ingroup ext
///
/// Include <glm/ext/matrix_uint4x3_sized.hpp> to use the features of this extension.
///
/// Defines a number of matrices with integer types.

#pragma once

// Dependency:
#include "../mat4x3.hpp"
#include "../ext/scalar_uint_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_uint4x3_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_matrix_uint4x3_sized
	/// @{

	/// 8 bit unsigned integer 4x3 matrix.
	///
	/// @see ext_matrix_uint4x3_sized
	using u8mat4x3 = mat<4, 3, uint8, defaultp>;

	/// 16 bit unsigned integer 4x3 matrix.
	///
	/// @see ext_matrix_uint4x3_sized
	using u16mat4x3 = mat<4, 3, uint16, defaultp>;

	/// 32 bit unsigned integer 4x3 matrix.
	///
	/// @see ext_matrix_uint4x3_sized
	using u32mat4x3 = mat<4, 3, uint32, defaultp>;

	/// 64 bit unsigned integer 4x3 matrix.
	///
	/// @see ext_matrix_uint4x3_sized
	using u64mat4x3 = mat<4, 3, uint64, defaultp>;

	/// @}
} //namespace glm

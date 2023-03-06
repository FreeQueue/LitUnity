/// @ref ext_matrix_int3x3_sized
/// @file glm/ext/matrix_int3x3_sized.hpp
///
/// @see core (dependence)
///
/// @defgroup ext_matrix_int3x3_sized GLM_EXT_matrix_int3x3_sized
/// @ingroup ext
///
/// Include <glm/ext/matrix_int3x3_sized.hpp> to use the features of this extension.
///
/// Defines a number of matrices with integer types.

#pragma once

// Dependency:
#include "../mat3x3.hpp"
#include "../ext/scalar_int_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_int3x3_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_matrix_int3x3_sized
	/// @{

	/// 8 bit signed integer 3x3 matrix.
	///
	/// @see ext_matrix_int3x3_sized
	using i8mat3x3 = mat<3, 3, int8, defaultp>;

	/// 16 bit signed integer 3x3 matrix.
	///
	/// @see ext_matrix_int3x3_sized
	using i16mat3x3 = mat<3, 3, int16, defaultp>;

	/// 32 bit signed integer 3x3 matrix.
	///
	/// @see ext_matrix_int3x3_sized
	using i32mat3x3 = mat<3, 3, int32, defaultp>;

	/// 64 bit signed integer 3x3 matrix.
	///
	/// @see ext_matrix_int3x3_sized
	using i64mat3x3 = mat<3, 3, int64, defaultp>;


	/// 8 bit signed integer 3x3 matrix.
	///
	/// @see ext_matrix_int3x3_sized
	using i8mat3 = mat<3, 3, int8, defaultp>;

	/// 16 bit signed integer 3x3 matrix.
	///
	/// @see ext_matrix_int3x3_sized
	using i16mat3 = mat<3, 3, int16, defaultp>;

	/// 32 bit signed integer 3x3 matrix.
	///
	/// @see ext_matrix_int3x3_sized
	using i32mat3 = mat<3, 3, int32, defaultp>;

	/// 64 bit signed integer 3x3 matrix.
	///
	/// @see ext_matrix_int3x3_sized
	using i64mat3 = mat<3, 3, int64, defaultp>;

	/// @}
} //namespace glm
/// @ref ext_vector_int1_sized
/// @file glm/ext/vector_int1_sized.hpp
///
/// @defgroup ext_vector_int1_sized GLM_EXT_vector_int1_sized
/// @ingroup ext
///
/// Exposes sized signed integer vector types.
///
/// Include <glm/ext/vector_int1_sized.hpp> to use the features of this extension.
///
/// @see ext_scalar_int_sized
/// @see ext_vector_uint1_sized

#pragma once

#include "../ext/vector_int1.hpp"
#include "../ext/scalar_int_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_vector_int1_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_vector_int1_sized
	/// @{

	/// 8 bit signed integer vector of 1 component type.
	///
	/// @see ext_vector_int1_sized
	using i8vec1 = vec<1, int8, defaultp>;

	/// 16 bit signed integer vector of 1 component type.
	///
	/// @see ext_vector_int1_sized
	using i16vec1 = vec<1, int16, defaultp>;

	/// 32 bit signed integer vector of 1 component type.
	///
	/// @see ext_vector_int1_sized
	using i32vec1 = vec<1, int32, defaultp>;

	/// 64 bit signed integer vector of 1 component type.
	///
	/// @see ext_vector_int1_sized
	using i64vec1 = vec<1, int64, defaultp>;

	/// @}
} //namespace glm

/// @ref ext_vector_int4_sized
/// @file glm/ext/vector_int4_sized.hpp
///
/// @defgroup ext_vector_int4_sized GLM_EXT_vector_int4_sized
/// @ingroup ext
///
/// Exposes sized signed integer vector of 4 components type.
///
/// Include <glm/ext/vector_int4_sized.hpp> to use the features of this extension.
///
/// @see ext_scalar_int_sized
/// @see ext_vector_uint4_sized

#pragma once

#include "../ext/vector_int4.hpp"
#include "../ext/scalar_int_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_vector_int4_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_vector_int4_sized
	/// @{

	/// 8 bit signed integer vector of 4 components type.
	///
	/// @see ext_vector_int4_sized
	using i8vec4 = vec<4, int8, defaultp>;

	/// 16 bit signed integer vector of 4 components type.
	///
	/// @see ext_vector_int4_sized
	using i16vec4 = vec<4, int16, defaultp>;

	/// 32 bit signed integer vector of 4 components type.
	///
	/// @see ext_vector_int4_sized
	using i32vec4 = vec<4, int32, defaultp>;

	/// 64 bit signed integer vector of 4 components type.
	///
	/// @see ext_vector_int4_sized
	using i64vec4 = vec<4, int64, defaultp>;

	/// @}
} //namespace glm

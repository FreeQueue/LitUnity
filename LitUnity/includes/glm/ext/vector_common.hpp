/// @ref ext_vector_common
/// @file glm/ext/vector_common.hpp
///
/// @defgroup ext_vector_common GLM_EXT_vector_common
/// @ingroup ext
///
/// Exposes min and max functions for 3 to 4 vector parameters.
///
/// Include <glm/ext/vector_common.hpp> to use the features of this extension.
///
/// @see core_common
/// @see ext_scalar_common

#pragma once

// Dependency:
#include "../ext/scalar_common.hpp"
#include "../common.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_vector_common extension included")
#endif

namespace glm
{
	/// @addtogroup ext_vector_common
	/// @{

	/// Return the minimum component-wise values of 3 inputs
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> min(const vec<L, T, Q>& a, const vec<L, T, Q>& b, const vec<L, T, Q>& c);

	/// Return the minimum component-wise values of 4 inputs
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> min(const vec<L, T, Q>& a, const vec<L, T, Q>& b, const vec<L, T, Q>& c,
												const vec<L, T, Q>& d);

	/// Return the maximum component-wise values of 3 inputs
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> max(const vec<L, T, Q>& x, const vec<L, T, Q>& y, const vec<L, T, Q>& z);

	/// Return the maximum component-wise values of 4 inputs
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> max(const vec<L, T, Q>& x, const vec<L, T, Q>& y, const vec<L, T, Q>& z,
												const vec<L, T, Q>& w);

	/// Returns y if y < x; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmin">std::fmin documentation</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> fmin(const vec<L, T, Q>& x, T y);

	/// Returns y if y < x; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmin">std::fmin documentation</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> fmin(const vec<L, T, Q>& x, const vec<L, T, Q>& y);

	/// Returns y if y < x; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmin">std::fmin documentation</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> fmin(const vec<L, T, Q>& a, const vec<L, T, Q>& b, const vec<L, T, Q>& c);

	/// Returns y if y < x; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmin">std::fmin documentation</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> fmin(const vec<L, T, Q>& a, const vec<L, T, Q>& b, const vec<L, T, Q>& c,
									const vec<L, T, Q>& d);

	/// Returns y if x < y; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmax">std::fmax documentation</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> fmax(const vec<L, T, Q>& a, T b);

	/// Returns y if x < y; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmax">std::fmax documentation</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> fmax(const vec<L, T, Q>& a, const vec<L, T, Q>& b);

	/// Returns y if x < y; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmax">std::fmax documentation</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> fmax(const vec<L, T, Q>& a, const vec<L, T, Q>& b, const vec<L, T, Q>& c);

	/// Returns y if x < y; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmax">std::fmax documentation</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> fmax(const vec<L, T, Q>& a, const vec<L, T, Q>& b, const vec<L, T, Q>& c,
									const vec<L, T, Q>& d);

	/// Returns min(max(x, minVal), maxVal) for each component in x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_vector_common
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> fclamp(const vec<L, T, Q>& x, T minVal, T maxVal);

	/// Returns min(max(x, minVal), maxVal) for each component in x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_vector_common
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> fclamp(const vec<L, T, Q>& x, const vec<L, T, Q>& minVal, const vec<L, T, Q>& maxVal);

	/// Simulate GL_CLAMP OpenGL wrap mode
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_vector_common extension.
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> clamp(const vec<L, T, Q>& Texcoord);

	/// Simulate GL_REPEAT OpenGL wrap mode
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_vector_common extension.
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> repeat(const vec<L, T, Q>& Texcoord);

	/// Simulate GL_MIRRORED_REPEAT OpenGL wrap mode
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_vector_common extension.
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> mirrorClamp(const vec<L, T, Q>& Texcoord);

	/// Simulate GL_MIRROR_REPEAT OpenGL wrap mode
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_vector_common extension.
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> mirrorRepeat(const vec<L, T, Q>& Texcoord);

	/// @}
} //namespace glm

#include "vector_common.inl"

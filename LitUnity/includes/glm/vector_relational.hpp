/// @ref core
/// @file glm/vector_relational.hpp
///
/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.7 Vector Relational Functions</a>
///
/// @defgroup core_func_vector_relational Vector Relational Functions
/// @ingroup core
///
/// Relational and equality operators (<, <=, >, >=, ==, !=) are defined to
/// operate on scalars and produce scalar Boolean results. For vector results,
/// use the following built-in functions.
///
/// In all cases, the sizes of all the input and return vectors for any particular
/// call must match.
///
/// Include <glm/vector_relational.hpp> to use these core features.
///
/// @see ext_vector_relational

#pragma once

#include "detail/qualifier.hpp"
#include "detail/setup.hpp"

namespace glm
{
	/// @addtogroup core_func_vector_relational
	/// @{

	/// Returns the component-wise comparison result of x < y.
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	/// @tparam T A floating-point or integer scalar type.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/lessThan.xml">GLSL lessThan man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.7 Vector Relational Functions</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool, Q> lessThan(const vec<L, T, Q>& x, const vec<L, T, Q>& y);

	/// Returns the component-wise comparison of result x <= y.
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	/// @tparam T A floating-point or integer scalar type.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/lessThanEqual.xml">GLSL lessThanEqual man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.7 Vector Relational Functions</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool, Q> lessThanEqual(const vec<L, T, Q>& x, const vec<L, T, Q>& y);

	/// Returns the component-wise comparison of result x > y.
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	/// @tparam T A floating-point or integer scalar type.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/greaterThan.xml">GLSL greaterThan man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.7 Vector Relational Functions</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool, Q> greaterThan(const vec<L, T, Q>& x, const vec<L, T, Q>& y);

	/// Returns the component-wise comparison of result x >= y.
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	/// @tparam T A floating-point or integer scalar type.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/greaterThanEqual.xml">GLSL greaterThanEqual man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.7 Vector Relational Functions</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool, Q> greaterThanEqual(const vec<L, T, Q>& x, const vec<L, T, Q>& y);

	/// Returns the component-wise comparison of result x == y.
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	/// @tparam T A floating-point, integer or bool scalar type.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/equal.xml">GLSL equal man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.7 Vector Relational Functions</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool, Q> equal(const vec<L, T, Q>& x, const vec<L, T, Q>& y);

	/// Returns the component-wise comparison of result x != y.
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	/// @tparam T A floating-point, integer or bool scalar type.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/notEqual.xml">GLSL notEqual man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.7 Vector Relational Functions</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool, Q> notEqual(const vec<L, T, Q>& x, const vec<L, T, Q>& y);

	/// Returns true if any component of x is true.
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/any.xml">GLSL any man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.7 Vector Relational Functions</a>
	template <length_t L, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR bool any(const vec<L, bool, Q>& v);

	/// Returns true if all components of x are true.
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/all.xml">GLSL all man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.7 Vector Relational Functions</a>
	template <length_t L, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR bool all(const vec<L, bool, Q>& v);

	/// Returns the component-wise logical complement of x.
	/// /!\ Because of language incompatibilities between C++ and GLSL, GLM defines the function not but not_ instead.
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/not.xml">GLSL not man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.7 Vector Relational Functions</a>
	template <length_t L, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool, Q> not_(const vec<L, bool, Q>& v);

	/// @}
} //namespace glm

#include "detail/func_vector_relational.inl"

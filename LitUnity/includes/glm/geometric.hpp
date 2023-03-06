/// @ref core
/// @file glm/geometric.hpp
///
/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.5 Geometric Functions</a>
///
/// @defgroup core_func_geometric Geometric functions
/// @ingroup core
///
/// These operate on vectors as vectors, not component-wise.
///
/// Include <glm/geometric.hpp> to use these core features.

#pragma once

#include "detail/type_vec3.hpp"

namespace glm
{
	/// @addtogroup core_func_geometric
	/// @{

	/// Returns the length of x, i.e., sqrt(x * x).
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	/// @tparam T Floating-point scalar types.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/length.xml">GLSL length man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.5 Geometric Functions</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL T length(const vec<L, T, Q>& x);

	/// Returns the distance betwwen p0 and p1, i.e., length(p0 - p1).
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	/// @tparam T Floating-point scalar types.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/distance.xml">GLSL distance man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.5 Geometric Functions</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL T distance(const vec<L, T, Q>& p0, const vec<L, T, Q>& p1);

	/// Returns the dot product of x and y, i.e., result = x * y.
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	/// @tparam T Floating-point scalar types.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/dot.xml">GLSL dot man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.5 Geometric Functions</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL T dot(const vec<L, T, Q>& x, const vec<L, T, Q>& y);

	/// Returns the cross product of x and y.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/cross.xml">GLSL cross man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.5 Geometric Functions</a>
	template <typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> cross(const vec<3, T, Q>& x, const vec<3, T, Q>& y);

	/// Returns a vector in the same direction as x but with length of 1.
	/// According to issue 10 GLSL 1.10 specification, if length(x) == 0 then result is undefined and generate an error.
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	/// @tparam T Floating-point scalar types.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/normalize.xml">GLSL normalize man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.5 Geometric Functions</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> normalize(const vec<L, T, Q>& x);

	/// If dot(Nref, I) < 0.0, return N, otherwise, return -N.
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	/// @tparam T Floating-point scalar types.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/faceforward.xml">GLSL faceforward man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.5 Geometric Functions</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> faceforward(
		const vec<L, T, Q>& N,
		const vec<L, T, Q>& I,
		const vec<L, T, Q>& Nref);

	/// For the incident vector I and surface orientation N,
	/// returns the reflection direction : result = I - 2.0 * dot(N, I) * N.
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	/// @tparam T Floating-point scalar types.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/reflect.xml">GLSL reflect man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.5 Geometric Functions</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> reflect(
		const vec<L, T, Q>& I,
		const vec<L, T, Q>& N);

	/// For the incident vector I and surface normal N,
	/// and the ratio of indices of refraction eta,
	/// return the refraction vector.
	///
	/// @tparam L An integer between 1 and 4 included that qualify the dimension of the vector.
	/// @tparam T Floating-point scalar types.
	///
	/// @see <a href="http://www.opengl.org/sdk/docs/manglsl/xhtml/refract.xml">GLSL refract man page</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.5 Geometric Functions</a>
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, T, Q> refract(
		const vec<L, T, Q>& I,
		const vec<L, T, Q>& N,
		T eta);

	/// @}
} //namespace glm

#include "detail/func_geometric.inl"

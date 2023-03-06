/// @ref gtx_vector_query
/// @file glm/gtx/vector_query.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_vector_query GLM_GTX_vector_query
/// @ingroup gtx
///
/// Include <glm/gtx/vector_query.hpp> to use the features of this extension.
///
/// Query informations of vector types

#pragma once

// Dependency:
#include "../glm.hpp"
#include <cfloat>
#include <limits>

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_vector_query is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_vector_query extension included")
#	endif
#endif

namespace glm
{
	/// @addtogroup gtx_vector_query
	/// @{

	//! Check whether two vectors are collinears.
	/// @see gtx_vector_query extensions.
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL bool areCollinear(const vec<L, T, Q>& v0, const vec<L, T, Q>& v1, const T& epsilon);

	//! Check whether two vectors are orthogonals.
	/// @see gtx_vector_query extensions.
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL bool areOrthogonal(const vec<L, T, Q>& v0, const vec<L, T, Q>& v1, const T& epsilon);

	//! Check whether a vector is normalized.
	/// @see gtx_vector_query extensions.
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL bool isNormalized(const vec<L, T, Q>& v, const T& epsilon);

	//! Check whether a vector is null.
	/// @see gtx_vector_query extensions.
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL bool isNull(const vec<L, T, Q>& v, const T& epsilon);

	//! Check whether a each component of a vector is null.
	/// @see gtx_vector_query extensions.
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL vec<L, bool, Q> isCompNull(const vec<L, T, Q>& v, const T& epsilon);

	//! Check whether two vectors are orthonormal.
	/// @see gtx_vector_query extensions.
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL bool areOrthonormal(const vec<L, T, Q>& v0, const vec<L, T, Q>& v1, const T& epsilon);

	/// @}
} // namespace glm

#include "vector_query.inl"

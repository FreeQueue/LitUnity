/// @ref ext_quaternion_geometric
/// @file glm/ext/quaternion_geometric.hpp
///
/// @defgroup ext_quaternion_geometric GLM_EXT_quaternion_geometric
/// @ingroup ext
///
/// Provides geometric functions for quaternion types
///
/// Include <glm/ext/quaternion_geometric.hpp> to use the features of this extension.
///
/// @see core_geometric
/// @see ext_quaternion_float
/// @see ext_quaternion_double

#pragma once

// Dependency:
#include "../geometric.hpp"
#include "../exponential.hpp"
#include "../ext/vector_relational.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_quaternion_geometric extension included")
#endif

namespace glm
{
	/// @addtogroup ext_quaternion_geometric
	/// @{

	/// Returns the norm of a quaternions
	///
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_quaternion_geometric
	template <typename T, qualifier Q>
	GLM_FUNC_DECL T length(const qua<T, Q>& q);

	/// Returns the normalized quaternion.
	///
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_quaternion_geometric
	template <typename T, qualifier Q>
	GLM_FUNC_DECL qua<T, Q> normalize(const qua<T, Q>& q);

	/// Returns dot product of q1 and q2, i.e., q1[0] * q2[0] + q1[1] * q2[1] + ...
	///
	/// @tparam T Floating-point scalar types.
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_quaternion_geometric
	template <typename T, qualifier Q>
	GLM_FUNC_DECL T dot(const qua<T, Q>& x, const qua<T, Q>& y);

	/// Compute a cross product.
	///
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_quaternion_geometric
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER qua<T, Q> cross(const qua<T, Q>& q1, const qua<T, Q>& q2);

	/// @}
} //namespace glm

#include "quaternion_geometric.inl"

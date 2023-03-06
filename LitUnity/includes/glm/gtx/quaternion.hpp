/// @ref gtx_quaternion
/// @file glm/gtx/quaternion.hpp
///
/// @see core (dependence)
/// @see gtx_extented_min_max (dependence)
///
/// @defgroup gtx_quaternion GLM_GTX_quaternion
/// @ingroup gtx
///
/// Include <glm/gtx/quaternion.hpp> to use the features of this extension.
///
/// Extented quaternion types and functions

#pragma once

// Dependency:
#include "../glm.hpp"
#include "../gtc/constants.hpp"
#include "../gtc/quaternion.hpp"
#include "../ext/quaternion_exponential.hpp"
#include "../gtx/norm.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_quaternion is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_quaternion extension included")
#	endif
#endif

namespace glm
{
	/// @addtogroup gtx_quaternion
	/// @{

	/// Create an identity quaternion.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T, Q> quat_identity();

	/// Compute a cross product between a quaternion and a vector.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> cross(
		const qua<T, Q>& q,
		const vec<3, T, Q>& v);

	//! Compute a cross product between a vector and a quaternion.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> cross(
		const vec<3, T, Q>& v,
		const qua<T, Q>& q);

	//! Compute a point on a path according squad equation.
	//! q1 and q2 are control points; s1 and s2 are intermediate control points.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL qua<T, Q> squad(
		const qua<T, Q>& q1,
		const qua<T, Q>& q2,
		const qua<T, Q>& s1,
		const qua<T, Q>& s2,
		const T& h);

	//! Returns an intermediate control point for squad interpolation.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL qua<T, Q> intermediate(
		const qua<T, Q>& prev,
		const qua<T, Q>& curr,
		const qua<T, Q>& next);

	//! Returns quarternion square root.
	///
	/// @see gtx_quaternion
	//template<typename T, qualifier Q>
	//qua<T, Q> sqrt(
	//	qua<T, Q> const& q);

	//! Rotates a 3 components vector by a quaternion.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> rotate(
		const qua<T, Q>& q,
		const vec<3, T, Q>& v);

	/// Rotates a 4 components vector by a quaternion.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL vec<4, T, Q> rotate(
		const qua<T, Q>& q,
		const vec<4, T, Q>& v);

	/// Extract the real component of a quaternion.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL T extractRealComponent(
		const qua<T, Q>& q);

	/// Converts a quaternion to a 3 * 3 matrix.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> toMat3(
		const qua<T, Q>& x) { return mat3_cast(x); }

	/// Converts a quaternion to a 4 * 4 matrix.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 4, T, Q> toMat4(
		const qua<T, Q>& x) { return mat4_cast(x); }

	/// Converts a 3 * 3 matrix to a quaternion.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL qua<T, Q> toQuat(
		const mat<3, 3, T, Q>& x) { return quat_cast(x); }

	/// Converts a 4 * 4 matrix to a quaternion.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL qua<T, Q> toQuat(
		const mat<4, 4, T, Q>& x) { return quat_cast(x); }

	/// Quaternion interpolation using the rotation short path.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL qua<T, Q> shortMix(
		const qua<T, Q>& x,
		const qua<T, Q>& y,
		const T& a);

	/// Quaternion normalized linear interpolation.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL qua<T, Q> fastMix(
		const qua<T, Q>& x,
		const qua<T, Q>& y,
		const T& a);

	/// Compute the rotation between two vectors.
	/// @param orig vector, needs to be normalized
	/// @param dest vector, needs to be normalized
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL qua<T, Q> rotation(
		const vec<3, T, Q>& orig,
		const vec<3, T, Q>& dest);

	/// Returns the squared length of x.
	///
	/// @see gtx_quaternion
	template <typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR T length2(const qua<T, Q>& q);

	/// @}
} //namespace glm

#include "quaternion.inl"

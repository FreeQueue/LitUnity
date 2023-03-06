/// @ref gtx_euler_angles
/// @file glm/gtx/euler_angles.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_euler_angles GLM_GTX_euler_angles
/// @ingroup gtx
///
/// Include <glm/gtx/euler_angles.hpp> to use the features of this extension.
///
/// Build matrices from Euler angles.
///
/// Extraction of Euler angles from rotation matrix.
/// Based on the original paper 2014 Mike Day - Extracting Euler Angles from a Rotation Matrix.

#pragma once

// Dependency:
#include "../glm.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_euler_angles is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_euler_angles extension included")
#	endif
#endif

namespace glm
{
	/// @addtogroup gtx_euler_angles
	/// @{

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from an euler angle X.
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleX(
		const T& angleX);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from an euler angle Y.
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleY(
		const T& angleY);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from an euler angle Z.
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleZ(
		const T& angleZ);

	/// Creates a 3D 4 * 4 homogeneous derived matrix from the rotation matrix about X-axis.
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> derivedEulerAngleX(
		const T& angleX, const T& angularVelocityX);

	/// Creates a 3D 4 * 4 homogeneous derived matrix from the rotation matrix about Y-axis.
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> derivedEulerAngleY(
		const T& angleY, const T& angularVelocityY);

	/// Creates a 3D 4 * 4 homogeneous derived matrix from the rotation matrix about Z-axis.
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> derivedEulerAngleZ(
		const T& angleZ, const T& angularVelocityZ);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (X * Y).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleXY(
		const T& angleX,
		const T& angleY);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Y * X).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleYX(
		const T& angleY,
		const T& angleX);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (X * Z).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleXZ(
		const T& angleX,
		const T& angleZ);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Z * X).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleZX(
		const T& angle,
		const T& angleX);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Y * Z).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleYZ(
		const T& angleY,
		const T& angleZ);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Z * Y).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleZY(
		const T& angleZ,
		const T& angleY);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (X * Y * Z).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleXYZ(
		const T& t1,
		const T& t2,
		const T& t3);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Y * X * Z).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleYXZ(
		const T& yaw,
		const T& pitch,
		const T& roll);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (X * Z * X).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleXZX(
		const T& t1,
		const T& t2,
		const T& t3);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (X * Y * X).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleXYX(
		const T& t1,
		const T& t2,
		const T& t3);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Y * X * Y).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleYXY(
		const T& t1,
		const T& t2,
		const T& t3);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Y * Z * Y).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleYZY(
		const T& t1,
		const T& t2,
		const T& t3);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Z * Y * Z).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleZYZ(
		const T& t1,
		const T& t2,
		const T& t3);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Z * X * Z).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleZXZ(
		const T& t1,
		const T& t2,
		const T& t3);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (X * Z * Y).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleXZY(
		const T& t1,
		const T& t2,
		const T& t3);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Y * Z * X).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleYZX(
		const T& t1,
		const T& t2,
		const T& t3);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Z * Y * X).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleZYX(
		const T& t1,
		const T& t2,
		const T& t3);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Z * X * Y).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> eulerAngleZXY(
		const T& t1,
		const T& t2,
		const T& t3);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Y * X * Z).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<4, 4, T, defaultp> yawPitchRoll(
		const T& yaw,
		const T& pitch,
		const T& roll);

	/// Creates a 2D 2 * 2 rotation matrix from an euler angle.
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<2, 2, T, defaultp> orientate2(const T& angle);

	/// Creates a 2D 4 * 4 homogeneous rotation matrix from an euler angle.
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL mat<3, 3, T, defaultp> orientate3(const T& angle);

	/// Creates a 3D 3 * 3 rotation matrix from euler angles (Y * X * Z).
	/// @see gtx_euler_angles
	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> orientate3(const vec<3, T, Q>& angles);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Y * X * Z).
	/// @see gtx_euler_angles
	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 4, T, Q> orientate4(const vec<3, T, Q>& angles);

	/// Extracts the (X * Y * Z) Euler angles from the rotation matrix M
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL void extractEulerAngleXYZ(const mat<4, 4, T, defaultp>& M,
											T& t1,
											T& t2,
											T& t3);

	/// Extracts the (Y * X * Z) Euler angles from the rotation matrix M
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL void extractEulerAngleYXZ(const mat<4, 4, T, defaultp>& M,
											T& t1,
											T& t2,
											T& t3);

	/// Extracts the (X * Z * X) Euler angles from the rotation matrix M
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL void extractEulerAngleXZX(const mat<4, 4, T, defaultp>& M,
											T& t1,
											T& t2,
											T& t3);

	/// Extracts the (X * Y * X) Euler angles from the rotation matrix M
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL void extractEulerAngleXYX(const mat<4, 4, T, defaultp>& M,
											T& t1,
											T& t2,
											T& t3);

	/// Extracts the (Y * X * Y) Euler angles from the rotation matrix M
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL void extractEulerAngleYXY(const mat<4, 4, T, defaultp>& M,
											T& t1,
											T& t2,
											T& t3);

	/// Extracts the (Y * Z * Y) Euler angles from the rotation matrix M
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL void extractEulerAngleYZY(const mat<4, 4, T, defaultp>& M,
											T& t1,
											T& t2,
											T& t3);

	/// Extracts the (Z * Y * Z) Euler angles from the rotation matrix M
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL void extractEulerAngleZYZ(const mat<4, 4, T, defaultp>& M,
											T& t1,
											T& t2,
											T& t3);

	/// Extracts the (Z * X * Z) Euler angles from the rotation matrix M
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL void extractEulerAngleZXZ(const mat<4, 4, T, defaultp>& M,
											T& t1,
											T& t2,
											T& t3);

	/// Extracts the (X * Z * Y) Euler angles from the rotation matrix M
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL void extractEulerAngleXZY(const mat<4, 4, T, defaultp>& M,
											T& t1,
											T& t2,
											T& t3);

	/// Extracts the (Y * Z * X) Euler angles from the rotation matrix M
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL void extractEulerAngleYZX(const mat<4, 4, T, defaultp>& M,
											T& t1,
											T& t2,
											T& t3);

	/// Extracts the (Z * Y * X) Euler angles from the rotation matrix M
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL void extractEulerAngleZYX(const mat<4, 4, T, defaultp>& M,
											T& t1,
											T& t2,
											T& t3);

	/// Extracts the (Z * X * Y) Euler angles from the rotation matrix M
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL void extractEulerAngleZXY(const mat<4, 4, T, defaultp>& M,
											T& t1,
											T& t2,
											T& t3);

	/// @}
} //namespace glm

#include "euler_angles.inl"

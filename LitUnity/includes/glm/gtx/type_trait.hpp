/// @ref gtx_type_trait
/// @file glm/gtx/type_trait.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_type_trait GLM_GTX_type_trait
/// @ingroup gtx
///
/// Include <glm/gtx/type_trait.hpp> to use the features of this extension.
///
/// Defines traits for each type.

#pragma once

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_type_trait is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_type_trait extension included")
#	endif
#endif

// Dependency:
#include "../detail/qualifier.hpp"
#include "../gtc/quaternion.hpp"
#include "../gtx/dual_quaternion.hpp"

namespace glm
{
	/// @addtogroup gtx_type_trait
	/// @{

	template <typename T>
	struct type
	{
		static const bool is_vec = false;
		static const bool is_mat = false;
		static const bool is_quat = false;
		static const length_t components = 0;
		static const length_t cols = 0;
		static const length_t rows = 0;
	};

	template <length_t L, typename T, qualifier Q>
	struct type<vec<L, T, Q>>
	{
		static const bool is_vec = true;
		static const bool is_mat = false;
		static const bool is_quat = false;
		static const length_t components = L;
	};

	template <length_t C, length_t R, typename T, qualifier Q>
	struct type<mat<C, R, T, Q>>
	{
		static const bool is_vec = false;
		static const bool is_mat = true;
		static const bool is_quat = false;
		static const length_t components = C;
		static const length_t cols = C;
		static const length_t rows = R;
	};

	template <typename T, qualifier Q>
	struct type<qua<T, Q>>
	{
		static const bool is_vec = false;
		static const bool is_mat = false;
		static const bool is_quat = true;
		static const length_t components = 4;
	};

	template <typename T, qualifier Q>
	struct type<tdualquat<T, Q>>
	{
		static const bool is_vec = false;
		static const bool is_mat = false;
		static const bool is_quat = true;
		static const length_t components = 8;
	};

	/// @}
} //namespace glm

#include "type_trait.inl"

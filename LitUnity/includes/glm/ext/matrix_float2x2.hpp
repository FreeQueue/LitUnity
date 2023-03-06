/// @ref core
/// @file glm/ext/matrix_float2x2.hpp

#pragma once
#include "../detail/type_mat2x2.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 2 columns of 2 components matrix of single-precision floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	using mat2x2 = mat<2, 2, float, defaultp>;

	/// 2 columns of 2 components matrix of single-precision floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	using mat2 = mat<2, 2, float, defaultp>;

	/// @}
} //namespace glm

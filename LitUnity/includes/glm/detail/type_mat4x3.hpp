/// @ref core
/// @file glm/detail/type_mat4x3.hpp

#pragma once

#include "type_vec3.hpp"
#include "type_vec4.hpp"
#include <limits>
#include <cstddef>

namespace glm
{
	template <typename T, qualifier Q>
	struct mat<4, 3, T, Q>
	{
		using col_type = vec<3, T, Q>;
		using row_type = vec<4, T, Q>;
		using type = mat<4, 3, T, Q>;
		using transpose_type = mat<3, 4, T, Q>;
		using value_type = T;

	private:
		col_type value[4];

	public:
		// -- Accesses --

		using length_type = length_t;
		GLM_FUNC_DECL static GLM_CONSTEXPR length_type length() { return 4; }

		GLM_FUNC_DECL col_type& operator[](length_type i);
		GLM_FUNC_DECL GLM_CONSTEXPR const col_type& operator[](length_type i) const;

		// -- Constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR mat() GLM_DEFAULT;
		template <qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR mat(const mat<4, 3, T, P>& m);

		GLM_FUNC_DECL explicit GLM_CONSTEXPR mat(const T& x);
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			const T& x0, const T& y0, const T& z0,
			const T& x1, const T& y1, const T& z1,
			const T& x2, const T& y2, const T& z2,
			const T& x3, const T& y3, const T& z3);
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			const col_type& v0,
			const col_type& v1,
			const col_type& v2,
			const col_type& v3);

		// -- Conversions --

		template <
			typename X1, typename Y1, typename Z1,
			typename X2, typename Y2, typename Z2,
			typename X3, typename Y3, typename Z3,
			typename X4, typename Y4, typename Z4>
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			const X1& x1, const Y1& y1, const Z1& z1,
			const X2& x2, const Y2& y2, const Z2& z2,
			const X3& x3, const Y3& y3, const Z3& z3,
			const X4& x4, const Y4& y4, const Z4& z4);

		template <typename V1, typename V2, typename V3, typename V4>
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			const vec<3, V1, Q>& v1,
			const vec<3, V2, Q>& v2,
			const vec<3, V3, Q>& v3,
			const vec<3, V4, Q>& v4);

		// -- Matrix conversions --

		template <typename U, qualifier P>
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(const mat<4, 3, U, P>& m);

		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(const mat<2, 2, T, Q>& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(const mat<3, 3, T, Q>& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(const mat<4, 4, T, Q>& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(const mat<2, 3, T, Q>& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(const mat<3, 2, T, Q>& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(const mat<2, 4, T, Q>& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(const mat<4, 2, T, Q>& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(const mat<3, 4, T, Q>& x);

		// -- Unary arithmetic operators --

		template <typename U>
		GLM_FUNC_DECL mat<4, 3, T, Q>& operator=(const mat<4, 3, U, Q>& m);
		template <typename U>
		GLM_FUNC_DECL mat<4, 3, T, Q>& operator+=(U s);
		template <typename U>
		GLM_FUNC_DECL mat<4, 3, T, Q>& operator+=(const mat<4, 3, U, Q>& m);
		template <typename U>
		GLM_FUNC_DECL mat<4, 3, T, Q>& operator-=(U s);
		template <typename U>
		GLM_FUNC_DECL mat<4, 3, T, Q>& operator-=(const mat<4, 3, U, Q>& m);
		template <typename U>
		GLM_FUNC_DECL mat<4, 3, T, Q>& operator*=(U s);
		template <typename U>
		GLM_FUNC_DECL mat<4, 3, T, Q>& operator/=(U s);

		// -- Increment and decrement operators --

		GLM_FUNC_DECL mat<4, 3, T, Q>& operator++();
		GLM_FUNC_DECL mat<4, 3, T, Q>& operator--();
		GLM_FUNC_DECL mat<4, 3, T, Q> operator++(int);
		GLM_FUNC_DECL mat<4, 3, T, Q> operator--(int);
	};

	// -- Unary operators --

	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 3, T, Q> operator+(const mat<4, 3, T, Q>& m);

	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 3, T, Q> operator-(const mat<4, 3, T, Q>& m);

	// -- Binary operators --

	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 3, T, Q> operator+(const mat<4, 3, T, Q>& m, const T& s);

	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 3, T, Q> operator+(const mat<4, 3, T, Q>& m1, const mat<4, 3, T, Q>& m2);

	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 3, T, Q> operator-(const mat<4, 3, T, Q>& m, const T& s);

	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 3, T, Q> operator-(const mat<4, 3, T, Q>& m1, const mat<4, 3, T, Q>& m2);

	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 3, T, Q> operator*(const mat<4, 3, T, Q>& m, const T& s);

	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 3, T, Q> operator*(const T& s, const mat<4, 3, T, Q>& m);

	template <typename T, qualifier Q>
	GLM_FUNC_DECL typename mat<4, 3, T, Q>::col_type operator*(const mat<4, 3, T, Q>& m,
																const typename mat<4, 3, T, Q>::row_type& v);

	template <typename T, qualifier Q>
	GLM_FUNC_DECL typename mat<4, 3, T, Q>::row_type operator*(const typename mat<4, 3, T, Q>::col_type& v,
																const mat<4, 3, T, Q>& m);

	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<2, 3, T, Q> operator*(const mat<4, 3, T, Q>& m1, const mat<2, 4, T, Q>& m2);

	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> operator*(const mat<4, 3, T, Q>& m1, const mat<3, 4, T, Q>& m2);

	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 3, T, Q> operator*(const mat<4, 3, T, Q>& m1, const mat<4, 4, T, Q>& m2);

	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 3, T, Q> operator/(const mat<4, 3, T, Q>& m, const T& s);

	template <typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 3, T, Q> operator/(const T& s, const mat<4, 3, T, Q>& m);

	// -- Boolean operators --

	template <typename T, qualifier Q>
	GLM_FUNC_DECL bool operator==(const mat<4, 3, T, Q>& m1, const mat<4, 3, T, Q>& m2);

	template <typename T, qualifier Q>
	GLM_FUNC_DECL bool operator!=(const mat<4, 3, T, Q>& m1, const mat<4, 3, T, Q>& m2);
} //namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_mat4x3.inl"
#endif //GLM_EXTERNAL_TEMPLATE

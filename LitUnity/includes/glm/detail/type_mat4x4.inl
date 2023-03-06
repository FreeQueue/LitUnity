#include "../matrix.hpp"

namespace glm
{
	// -- Constructors --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T, qualifier Q>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat()
#			if GLM_CONFIG_CTOR_INIT == GLM_CTOR_INITIALIZER_LIST
				: value{col_type(1, 0, 0, 0), col_type(0, 1, 0, 0), col_type(0, 0, 1, 0), col_type(0, 0, 0, 1)}
#			endif
		{
#			if GLM_CONFIG_CTOR_INIT == GLM_CTOR_INITIALISATION
				this->value[0] = col_type(1, 0, 0, 0);
				this->value[1] = col_type(0, 1, 0, 0);
				this->value[2] = col_type(0, 0, 1, 0);
				this->value[3] = col_type(0, 0, 0, 1);
#			endif
		}
#	endif

	template <typename T, qualifier Q>
	template <qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(const mat<4, 4, T, P>& m)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
#		endif
	{
#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = m[0];
			this->value[1] = m[1];
			this->value[2] = m[2];
			this->value[3] = m[3];
#		endif
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(const T& s)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{col_type(s, 0, 0, 0), col_type(0, s, 0, 0), col_type(0, 0, s, 0), col_type(0, 0, 0, s)}
#		endif
	{
#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = col_type(s, 0, 0, 0);
			this->value[1] = col_type(0, s, 0, 0);
			this->value[2] = col_type(0, 0, s, 0);
			this->value[3] = col_type(0, 0, 0, s);
#		endif
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat
	(
		const T& x0, const T& y0, const T& z0, const T& w0,
		const T& x1, const T& y1, const T& z1, const T& w1,
		const T& x2, const T& y2, const T& z2, const T& w2,
		const T& x3, const T& y3, const T& z3, const T& w3
	)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{
			col_type(x0, y0, z0, w0),
			col_type(x1, y1, z1, w1),
			col_type(x2, y2, z2, w2),
			col_type(x3, y3, z3, w3)
		}
#		endif
	{
#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = col_type(x0, y0, z0, w0);
			this->value[1] = col_type(x1, y1, z1, w1);
			this->value[2] = col_type(x2, y2, z2, w2);
			this->value[3] = col_type(x3, y3, z3, w3);
#		endif
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(const col_type& v0, const col_type& v1, const col_type& v2,
														const col_type& v3)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{col_type(v0), col_type(v1), col_type(v2), col_type(v3)}
#		endif
	{
#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = v0;
			this->value[1] = v1;
			this->value[2] = v2;
			this->value[3] = v3;
#		endif
	}

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(const mat<4, 4, U, P>& m)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
#		endif
	{
#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = col_type(m[0]);
			this->value[1] = col_type(m[1]);
			this->value[2] = col_type(m[2]);
			this->value[3] = col_type(m[3]);
#		endif
	}

	// -- Conversions --

	template <typename T, qualifier Q>
	template <
		typename X1, typename Y1, typename Z1, typename W1,
		typename X2, typename Y2, typename Z2, typename W2,
		typename X3, typename Y3, typename Z3, typename W3,
		typename X4, typename Y4, typename Z4, typename W4>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat
	(
		const X1& x1, const Y1& y1, const Z1& z1, const W1& w1,
		const X2& x2, const Y2& y2, const Z2& z2, const W2& w2,
		const X3& x3, const Y3& y3, const Z3& z3, const W3& w3,
		const X4& x4, const Y4& y4, const Z4& z4, const W4& w4
	)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{col_type(x1, y1, z1, w1), col_type(x2, y2, z2, w2), col_type(x3, y3, z3, w3), col_type(x4, y4, z4, w4)}
#		endif
	{
		GLM_STATIC_ASSERT(
			std::numeric_limits<X1>::is_iec559 || std::numeric_limits<X1>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 1st parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<Y1>::is_iec559 || std::numeric_limits<Y1>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 2nd parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<Z1>::is_iec559 || std::numeric_limits<Z1>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 3rd parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<W1>::is_iec559 || std::numeric_limits<W1>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 4th parameter type invalid.");

		GLM_STATIC_ASSERT(
			std::numeric_limits<X2>::is_iec559 || std::numeric_limits<X2>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 5th parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<Y2>::is_iec559 || std::numeric_limits<Y2>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 6th parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<Z2>::is_iec559 || std::numeric_limits<Z2>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 7th parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<W2>::is_iec559 || std::numeric_limits<W2>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 8th parameter type invalid.");

		GLM_STATIC_ASSERT(
			std::numeric_limits<X3>::is_iec559 || std::numeric_limits<X3>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 9th parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<Y3>::is_iec559 || std::numeric_limits<Y3>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 10th parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<Z3>::is_iec559 || std::numeric_limits<Z3>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 11th parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<W3>::is_iec559 || std::numeric_limits<W3>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 12th parameter type invalid.");

		GLM_STATIC_ASSERT(
			std::numeric_limits<X4>::is_iec559 || std::numeric_limits<X4>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 13th parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<Y4>::is_iec559 || std::numeric_limits<Y4>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 14th parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<Z4>::is_iec559 || std::numeric_limits<Z4>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 15th parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<W4>::is_iec559 || std::numeric_limits<W4>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 16th parameter type invalid.");

#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = col_type(x1, y1, z1, w1);
			this->value[1] = col_type(x2, y2, z2, w2);
			this->value[2] = col_type(x3, y3, z3, w3);
			this->value[3] = col_type(x4, y4, z4, w4);
#		endif
	}

	template <typename T, qualifier Q>
	template <typename V1, typename V2, typename V3, typename V4>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(const vec<4, V1, Q>& v1, const vec<4, V2, Q>& v2,
														const vec<4, V3, Q>& v3, const vec<4, V4, Q>& v4)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{col_type(v1), col_type(v2), col_type(v3), col_type(v4)}
#		endif
	{
		GLM_STATIC_ASSERT(
			std::numeric_limits<V1>::is_iec559 || std::numeric_limits<V1>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 1st parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<V2>::is_iec559 || std::numeric_limits<V2>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 2nd parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<V3>::is_iec559 || std::numeric_limits<V3>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 3rd parameter type invalid.");
		GLM_STATIC_ASSERT(
			std::numeric_limits<V4>::is_iec559 || std::numeric_limits<V4>::is_integer ||
			GLM_CONFIG_UNRESTRICTED_GENTYPE,
			"*mat4x4 constructor only takes float and integer types, 4th parameter type invalid.");

#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = col_type(v1);
			this->value[1] = col_type(v2);
			this->value[2] = col_type(v3);
			this->value[3] = col_type(v4);
#		endif
	}

	// -- Matrix conversions --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(const mat<2, 2, T, Q>& m)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{col_type(m[0], 0, 0), col_type(m[1], 0, 0), col_type(0, 0, 1, 0), col_type(0, 0, 0, 1)}
#		endif
	{
#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = col_type(m[0], 0, 0);
			this->value[1] = col_type(m[1], 0, 0);
			this->value[2] = col_type(0, 0, 1, 0);
			this->value[3] = col_type(0, 0, 0, 1);
#		endif
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(const mat<3, 3, T, Q>& m)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{col_type(m[0], 0), col_type(m[1], 0), col_type(m[2], 0), col_type(0, 0, 0, 1)}
#		endif
	{
#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = col_type(m[0], 0);
			this->value[1] = col_type(m[1], 0);
			this->value[2] = col_type(m[2], 0);
			this->value[3] = col_type(0, 0, 0, 1);
#		endif
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(const mat<2, 3, T, Q>& m)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{col_type(m[0], 0), col_type(m[1], 0), col_type(0, 0, 1, 0), col_type(0, 0, 0, 1)}
#		endif
	{
#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = col_type(m[0], 0);
			this->value[1] = col_type(m[1], 0);
			this->value[2] = col_type(0, 0, 1, 0);
			this->value[3] = col_type(0, 0, 0, 1);
#		endif
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(const mat<3, 2, T, Q>& m)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{col_type(m[0], 0, 0), col_type(m[1], 0, 0), col_type(m[2], 1, 0), col_type(0, 0, 0, 1)}
#		endif
	{
#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = col_type(m[0], 0, 0);
			this->value[1] = col_type(m[1], 0, 0);
			this->value[2] = col_type(m[2], 1, 0);
			this->value[3] = col_type(0, 0, 0, 1);
#		endif
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(const mat<2, 4, T, Q>& m)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{col_type(m[0]), col_type(m[1]), col_type(0, 0, 1, 0), col_type(0, 0, 0, 1)}
#		endif
	{
#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = m[0];
			this->value[1] = m[1];
			this->value[2] = col_type(0, 0, 1, 0);
			this->value[3] = col_type(0, 0, 0, 1);
#		endif
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(const mat<4, 2, T, Q>& m)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{col_type(m[0], 0, 0), col_type(m[1], 0, 0), col_type(0, 0, 1, 0), col_type(0, 0, 0, 1)}
#		endif
	{
#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = col_type(m[0], 0, 0);
			this->value[1] = col_type(m[1], 0, 0);
			this->value[2] = col_type(0, 0, 1, 0);
			this->value[3] = col_type(0, 0, 0, 1);
#		endif
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(const mat<3, 4, T, Q>& m)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(0, 0, 0, 1)}
#		endif
	{
#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = m[0];
			this->value[1] = m[1];
			this->value[2] = m[2];
			this->value[3] = col_type(0, 0, 0, 1);
#		endif
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(const mat<4, 3, T, Q>& m)
#		if GLM_HAS_INITIALIZER_LISTS
		: value{col_type(m[0], 0), col_type(m[1], 0), col_type(m[2], 0), col_type(m[3], 1)}
#		endif
	{
#		if !GLM_HAS_INITIALIZER_LISTS
			this->value[0] = col_type(m[0], 0);
			this->value[1] = col_type(m[1], 0);
			this->value[2] = col_type(m[2], 0);
			this->value[3] = col_type(m[3], 1);
#		endif
	}

	// -- Accesses --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER typename mat<4, 4, T, Q>::col_type& mat<4, 4, T, Q>::operator[](length_type i)
	{
		assert(i < this->length());
		return this->value[i];
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR const typename mat<4, 4, T, Q>::col_type& mat<4, 4, T, Q>::operator[](
		length_type i) const
	{
		assert(i < this->length());
		return this->value[i];
	}

	// -- Unary arithmetic operators --

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q>& mat<4, 4, T, Q>::operator=(const mat<4, 4, U, Q>& m)
	{
		//memcpy could be faster
		//memcpy(&this->value, &m.value, 16 * sizeof(valType));
		this->value[0] = m[0];
		this->value[1] = m[1];
		this->value[2] = m[2];
		this->value[3] = m[3];
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q>& mat<4, 4, T, Q>::operator+=(U s)
	{
		this->value[0] += s;
		this->value[1] += s;
		this->value[2] += s;
		this->value[3] += s;
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q>& mat<4, 4, T, Q>::operator+=(const mat<4, 4, U, Q>& m)
	{
		this->value[0] += m[0];
		this->value[1] += m[1];
		this->value[2] += m[2];
		this->value[3] += m[3];
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q>& mat<4, 4, T, Q>::operator-=(U s)
	{
		this->value[0] -= s;
		this->value[1] -= s;
		this->value[2] -= s;
		this->value[3] -= s;
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q>& mat<4, 4, T, Q>::operator-=(const mat<4, 4, U, Q>& m)
	{
		this->value[0] -= m[0];
		this->value[1] -= m[1];
		this->value[2] -= m[2];
		this->value[3] -= m[3];
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q>& mat<4, 4, T, Q>::operator*=(U s)
	{
		this->value[0] *= s;
		this->value[1] *= s;
		this->value[2] *= s;
		this->value[3] *= s;
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q>& mat<4, 4, T, Q>::operator*=(const mat<4, 4, U, Q>& m)
	{
		return (*this = *this * m);
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q>& mat<4, 4, T, Q>::operator/=(U s)
	{
		this->value[0] /= s;
		this->value[1] /= s;
		this->value[2] /= s;
		this->value[3] /= s;
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q>& mat<4, 4, T, Q>::operator/=(const mat<4, 4, U, Q>& m)
	{
		return *this *= inverse(m);
	}

	// -- Increment and decrement operators --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q>& mat<4, 4, T, Q>::operator++()
	{
		++this->value[0];
		++this->value[1];
		++this->value[2];
		++this->value[3];
		return *this;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q>& mat<4, 4, T, Q>::operator--()
	{
		--this->value[0];
		--this->value[1];
		--this->value[2];
		--this->value[3];
		return *this;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> mat<4, 4, T, Q>::operator++(int)
	{
		mat<4, 4, T, Q> Result(*this);
		++*this;
		return Result;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> mat<4, 4, T, Q>::operator--(int)
	{
		mat<4, 4, T, Q> Result(*this);
		--*this;
		return Result;
	}

	// -- Unary constant operators --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> operator+(const mat<4, 4, T, Q>& m)
	{
		return m;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> operator-(const mat<4, 4, T, Q>& m)
	{
		return mat<4, 4, T, Q>(
			-m[0],
			-m[1],
			-m[2],
			-m[3]);
	}

	// -- Binary arithmetic operators --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> operator+(const mat<4, 4, T, Q>& m, const T& s)
	{
		return mat<4, 4, T, Q>(
			m[0] + s,
			m[1] + s,
			m[2] + s,
			m[3] + s);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> operator+(const T& s, const mat<4, 4, T, Q>& m)
	{
		return mat<4, 4, T, Q>(
			m[0] + s,
			m[1] + s,
			m[2] + s,
			m[3] + s);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> operator+(const mat<4, 4, T, Q>& m1, const mat<4, 4, T, Q>& m2)
	{
		return mat<4, 4, T, Q>(
			m1[0] + m2[0],
			m1[1] + m2[1],
			m1[2] + m2[2],
			m1[3] + m2[3]);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> operator-(const mat<4, 4, T, Q>& m, const T& s)
	{
		return mat<4, 4, T, Q>(
			m[0] - s,
			m[1] - s,
			m[2] - s,
			m[3] - s);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> operator-(const T& s, const mat<4, 4, T, Q>& m)
	{
		return mat<4, 4, T, Q>(
			s - m[0],
			s - m[1],
			s - m[2],
			s - m[3]);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> operator-(const mat<4, 4, T, Q>& m1, const mat<4, 4, T, Q>& m2)
	{
		return mat<4, 4, T, Q>(
			m1[0] - m2[0],
			m1[1] - m2[1],
			m1[2] - m2[2],
			m1[3] - m2[3]);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> operator*(const mat<4, 4, T, Q>& m, const T& s)
	{
		return mat<4, 4, T, Q>(
			m[0] * s,
			m[1] * s,
			m[2] * s,
			m[3] * s);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> operator*(const T& s, const mat<4, 4, T, Q>& m)
	{
		return mat<4, 4, T, Q>(
			m[0] * s,
			m[1] * s,
			m[2] * s,
			m[3] * s);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER typename mat<4, 4, T, Q>::col_type operator*
	(
		const mat<4, 4, T, Q>& m,
		const typename mat<4, 4, T, Q>::row_type& v
	)
	{
		/*
				__m128 v0 = _mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(0, 0, 0, 0));
				__m128 v1 = _mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(1, 1, 1, 1));
				__m128 v2 = _mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(2, 2, 2, 2));
				__m128 v3 = _mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(3, 3, 3, 3));
		
				__m128 m0 = _mm_mul_ps(m[0].data, v0);
				__m128 m1 = _mm_mul_ps(m[1].data, v1);
				__m128 a0 = _mm_add_ps(m0, m1);
		
				__m128 m2 = _mm_mul_ps(m[2].data, v2);
				__m128 m3 = _mm_mul_ps(m[3].data, v3);
				__m128 a1 = _mm_add_ps(m2, m3);
		
				__m128 a2 = _mm_add_ps(a0, a1);
		
				return typename mat<4, 4, T, Q>::col_type(a2);
		*/

		const typename mat<4, 4, T, Q>::col_type Mov0(v[0]);
		const typename mat<4, 4, T, Q>::col_type Mov1(v[1]);
		const typename mat<4, 4, T, Q>::col_type Mul0 = m[0] * Mov0;
		const typename mat<4, 4, T, Q>::col_type Mul1 = m[1] * Mov1;
		const typename mat<4, 4, T, Q>::col_type Add0 = Mul0 + Mul1;
		const typename mat<4, 4, T, Q>::col_type Mov2(v[2]);
		const typename mat<4, 4, T, Q>::col_type Mov3(v[3]);
		const typename mat<4, 4, T, Q>::col_type Mul2 = m[2] * Mov2;
		const typename mat<4, 4, T, Q>::col_type Mul3 = m[3] * Mov3;
		const typename mat<4, 4, T, Q>::col_type Add1 = Mul2 + Mul3;
		const typename mat<4, 4, T, Q>::col_type Add2 = Add0 + Add1;
		return Add2;

		/*
				return typename mat<4, 4, T, Q>::col_type(
					m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2] + m[3][0] * v[3],
					m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2] + m[3][1] * v[3],
					m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2] + m[3][2] * v[3],
					m[0][3] * v[0] + m[1][3] * v[1] + m[2][3] * v[2] + m[3][3] * v[3]);
		*/
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER typename mat<4, 4, T, Q>::row_type operator*
	(
		const typename mat<4, 4, T, Q>::col_type& v,
		const mat<4, 4, T, Q>& m
	)
	{
		return typename mat<4, 4, T, Q>::row_type(
			m[0][0] * v[0] + m[0][1] * v[1] + m[0][2] * v[2] + m[0][3] * v[3],
			m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2] + m[1][3] * v[3],
			m[2][0] * v[0] + m[2][1] * v[1] + m[2][2] * v[2] + m[2][3] * v[3],
			m[3][0] * v[0] + m[3][1] * v[1] + m[3][2] * v[2] + m[3][3] * v[3]);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<2, 4, T, Q> operator*(const mat<4, 4, T, Q>& m1, const mat<2, 4, T, Q>& m2)
	{
		return mat<2, 4, T, Q>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3]);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<3, 4, T, Q> operator*(const mat<4, 4, T, Q>& m1, const mat<3, 4, T, Q>& m2)
	{
		return mat<3, 4, T, Q>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2] + m1[3][2] * m2[2][3],
			m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1] + m1[2][3] * m2[2][2] + m1[3][3] * m2[2][3]);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> operator*(const mat<4, 4, T, Q>& m1, const mat<4, 4, T, Q>& m2)
	{
		const typename mat<4, 4, T, Q>::col_type SrcA0 = m1[0];
		const typename mat<4, 4, T, Q>::col_type SrcA1 = m1[1];
		const typename mat<4, 4, T, Q>::col_type SrcA2 = m1[2];
		const typename mat<4, 4, T, Q>::col_type SrcA3 = m1[3];

		const typename mat<4, 4, T, Q>::col_type SrcB0 = m2[0];
		const typename mat<4, 4, T, Q>::col_type SrcB1 = m2[1];
		const typename mat<4, 4, T, Q>::col_type SrcB2 = m2[2];
		const typename mat<4, 4, T, Q>::col_type SrcB3 = m2[3];

		mat<4, 4, T, Q> Result;
		Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1] + SrcA2 * SrcB0[2] + SrcA3 * SrcB0[3];
		Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1] + SrcA2 * SrcB1[2] + SrcA3 * SrcB1[3];
		Result[2] = SrcA0 * SrcB2[0] + SrcA1 * SrcB2[1] + SrcA2 * SrcB2[2] + SrcA3 * SrcB2[3];
		Result[3] = SrcA0 * SrcB3[0] + SrcA1 * SrcB3[1] + SrcA2 * SrcB3[2] + SrcA3 * SrcB3[3];
		return Result;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> operator/(const mat<4, 4, T, Q>& m, const T& s)
	{
		return mat<4, 4, T, Q>(
			m[0] / s,
			m[1] / s,
			m[2] / s,
			m[3] / s);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> operator/(const T& s, const mat<4, 4, T, Q>& m)
	{
		return mat<4, 4, T, Q>(
			s / m[0],
			s / m[1],
			s / m[2],
			s / m[3]);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER typename mat<4, 4, T, Q>::col_type operator/(const mat<4, 4, T, Q>& m,
																	const typename mat<4, 4, T, Q>::row_type& v)
	{
		return inverse(m) * v;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER typename mat<4, 4, T, Q>::row_type operator/(const typename mat<4, 4, T, Q>::col_type& v,
																	const mat<4, 4, T, Q>& m)
	{
		return v * inverse(m);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> operator/(const mat<4, 4, T, Q>& m1, const mat<4, 4, T, Q>& m2)
	{
		mat<4, 4, T, Q> m1_copy(m1);
		return m1_copy /= m2;
	}

	// -- Boolean operators --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER bool operator==(const mat<4, 4, T, Q>& m1, const mat<4, 4, T, Q>& m2)
	{
		return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER bool operator!=(const mat<4, 4, T, Q>& m1, const mat<4, 4, T, Q>& m2)
	{
		return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]) || (m1[3] != m2[3]);
	}
} //namespace glm

#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "type_mat4x4_simd.inl"
#endif

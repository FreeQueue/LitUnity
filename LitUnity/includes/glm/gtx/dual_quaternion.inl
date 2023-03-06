/// @ref gtx_dual_quaternion

#include "../geometric.hpp"
#include <limits>

namespace glm
{
	// -- Component accesses --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER typename tdualquat<T, Q>::part_type& tdualquat<T, Q>::operator[](length_type i)
	{
		assert(i >= 0 && i < this->length());
		return (&real)[i];
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER const typename tdualquat<T, Q>::part_type& tdualquat<T, Q>::operator[](length_type i) const
	{
		assert(i >= 0 && i < this->length());
		return (&real)[i];
	}

	// -- Implicit basic constructors --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T, qualifier Q>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T, Q>::tdualquat()
#			if GLM_CONFIG_DEFAULTED_FUNCTIONS != GLM_DISABLE
			: real(qua<T, Q>())
			, dual(qua<T, Q>(0, 0, 0, 0))
#			endif
		{}

		template<typename T, qualifier Q>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T, Q>::tdualquat(tdualquat<T, Q> const& d)
			: real(d.real)
			, dual(d.dual)
		{}
#	endif

	template <typename T, qualifier Q>
	template <qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T, Q>::tdualquat(const tdualquat<T, P>& d)
		: real(d.real)
		, dual(d.dual)
	{
	}

	// -- Explicit basic constructors --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T, Q>::tdualquat(const qua<T, Q>& r)
		: real(r), dual(qua<T, Q>(0, 0, 0, 0))
	{
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T, Q>::tdualquat(const qua<T, Q>& q, const vec<3, T, Q>& p)
		: real(q), dual(
			T(-0.5) * (p.x * q.x + p.y * q.y + p.z * q.z),
			T(+0.5) * (p.x * q.w + p.y * q.z - p.z * q.y),
			T(+0.5) * (-p.x * q.z + p.y * q.w + p.z * q.x),
			T(+0.5) * (p.x * q.y - p.y * q.x + p.z * q.w))
	{
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T, Q>::tdualquat(const qua<T, Q>& r, const qua<T, Q>& d)
		: real(r), dual(d)
	{
	}

	// -- Conversion constructors --

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T, Q>::tdualquat(const tdualquat<U, P>& q)
		: real(q.real)
		, dual(q.dual)
	{
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T, Q>::tdualquat(const mat<2, 4, T, Q>& m)
	{
		*this = dualquat_cast(m);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T, Q>::tdualquat(const mat<3, 4, T, Q>& m)
	{
		*this = dualquat_cast(m);
	}

	// -- Unary arithmetic operators --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T, qualifier Q>
		GLM_FUNC_QUALIFIER tdualquat<T, Q> & tdualquat<T, Q>::operator=(tdualquat<T, Q> const& q)
		{
			this->real = q.real;
			this->dual = q.dual;
			return *this;
		}
#	endif

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER tdualquat<T, Q>& tdualquat<T, Q>::operator=(const tdualquat<U, Q>& q)
	{
		this->real = q.real;
		this->dual = q.dual;
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER tdualquat<T, Q>& tdualquat<T, Q>::operator*=(U s)
	{
		this->real *= static_cast<T>(s);
		this->dual *= static_cast<T>(s);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER tdualquat<T, Q>& tdualquat<T, Q>::operator/=(U s)
	{
		this->real /= static_cast<T>(s);
		this->dual /= static_cast<T>(s);
		return *this;
	}

	// -- Unary bit operators --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tdualquat<T, Q> operator+(const tdualquat<T, Q>& q)
	{
		return q;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tdualquat<T, Q> operator-(const tdualquat<T, Q>& q)
	{
		return tdualquat<T, Q>(-q.real, -q.dual);
	}

	// -- Binary operators --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tdualquat<T, Q> operator+(const tdualquat<T, Q>& q, const tdualquat<T, Q>& p)
	{
		return tdualquat<T, Q>(q.real + p.real, q.dual + p.dual);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tdualquat<T, Q> operator*(const tdualquat<T, Q>& p, const tdualquat<T, Q>& o)
	{
		return tdualquat<T, Q>(p.real * o.real, p.real * o.dual + p.dual * o.real);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> operator*(const tdualquat<T, Q>& q, const vec<3, T, Q>& v)
	{
		const vec<3, T, Q> real_v3(q.real.x, q.real.y, q.real.z);
		const vec<3, T, Q> dual_v3(q.dual.x, q.dual.y, q.dual.z);
		return (cross(real_v3, cross(real_v3, v) + v * q.real.w + dual_v3) + dual_v3 * q.real.w - real_v3 * q.dual.w) *
			T(2) + v;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> operator*(const vec<3, T, Q>& v, const tdualquat<T, Q>& q)
	{
		return glm::inverse(q) * v;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, T, Q> operator*(const tdualquat<T, Q>& q, const vec<4, T, Q>& v)
	{
		return vec<4, T, Q>(q * vec<3, T, Q>(v), v.w);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, T, Q> operator*(const vec<4, T, Q>& v, const tdualquat<T, Q>& q)
	{
		return glm::inverse(q) * v;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tdualquat<T, Q> operator*(const tdualquat<T, Q>& q, const T& s)
	{
		return tdualquat<T, Q>(q.real * s, q.dual * s);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tdualquat<T, Q> operator*(const T& s, const tdualquat<T, Q>& q)
	{
		return q * s;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tdualquat<T, Q> operator/(const tdualquat<T, Q>& q, const T& s)
	{
		return tdualquat<T, Q>(q.real / s, q.dual / s);
	}

	// -- Boolean operators --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER bool operator==(const tdualquat<T, Q>& q1, const tdualquat<T, Q>& q2)
	{
		return (q1.real == q2.real) && (q1.dual == q2.dual);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER bool operator!=(const tdualquat<T, Q>& q1, const tdualquat<T, Q>& q2)
	{
		return (q1.real != q2.real) || (q1.dual != q2.dual);
	}

	// -- Operations --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tdualquat<T, Q> dual_quat_identity()
	{
		return tdualquat<T, Q>(
			qua<T, Q>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)),
			qua<T, Q>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)));
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tdualquat<T, Q> normalize(const tdualquat<T, Q>& q)
	{
		return q / length(q.real);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tdualquat<T, Q> lerp(const tdualquat<T, Q>& x, const tdualquat<T, Q>& y, const T& a)
	{
		// Dual Quaternion Linear blend aka DLB:
		// Lerp is only defined in [0, 1]
		assert(a >= static_cast<T>(0));
		assert(a <= static_cast<T>(1));
		const T k = dot(x.real, y.real) < static_cast<T>(0) ? -a : a;
		const T one(1);
		return tdualquat<T, Q>(x * (one - a) + y * k);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tdualquat<T, Q> inverse(const tdualquat<T, Q>& q)
	{
		const qua<T, Q> real = conjugate(q.real);
		const qua<T, Q> dual = conjugate(q.dual);
		return tdualquat<T, Q>(real, dual + (real * (-2.0f * dot(real, dual))));
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<2, 4, T, Q> mat2x4_cast(const tdualquat<T, Q>& x)
	{
		return mat<2, 4, T, Q>(x[0].x, x[0].y, x[0].z, x[0].w, x[1].x, x[1].y, x[1].z, x[1].w);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<3, 4, T, Q> mat3x4_cast(const tdualquat<T, Q>& x)
	{
		qua<T, Q> r = x.real / length2(x.real);

		const qua<T, Q> rr(r.w * x.real.w, r.x * x.real.x, r.y * x.real.y, r.z * x.real.z);
		r *= static_cast<T>(2);

		const T xy = r.x * x.real.y;
		const T xz = r.x * x.real.z;
		const T yz = r.y * x.real.z;
		const T wx = r.w * x.real.x;
		const T wy = r.w * x.real.y;
		const T wz = r.w * x.real.z;

		const vec<4, T, Q> a(
			rr.w + rr.x - rr.y - rr.z,
			xy - wz,
			xz + wy,
			-(x.dual.w * r.x - x.dual.x * r.w + x.dual.y * r.z - x.dual.z * r.y));

		const vec<4, T, Q> b(
			xy + wz,
			rr.w + rr.y - rr.x - rr.z,
			yz - wx,
			-(x.dual.w * r.y - x.dual.x * r.z - x.dual.y * r.w + x.dual.z * r.x));

		const vec<4, T, Q> c(
			xz - wy,
			yz + wx,
			rr.w + rr.z - rr.x - rr.y,
			-(x.dual.w * r.z + x.dual.x * r.y - x.dual.y * r.x - x.dual.z * r.w));

		return mat<3, 4, T, Q>(a, b, c);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tdualquat<T, Q> dualquat_cast(const mat<2, 4, T, Q>& x)
	{
		return tdualquat<T, Q>(
			qua<T, Q>(x[0].w, x[0].x, x[0].y, x[0].z),
			qua<T, Q>(x[1].w, x[1].x, x[1].y, x[1].z));
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tdualquat<T, Q> dualquat_cast(const mat<3, 4, T, Q>& x)
	{
		qua<T, Q> real;

		const T trace = x[0].x + x[1].y + x[2].z;
		if (trace > static_cast<T>(0))
		{
			const T r = sqrt(T(1) + trace);
			const T invr = static_cast<T>(0.5) / r;
			real.w = static_cast<T>(0.5) * r;
			real.x = (x[2].y - x[1].z) * invr;
			real.y = (x[0].z - x[2].x) * invr;
			real.z = (x[1].x - x[0].y) * invr;
		}
		else if (x[0].x > x[1].y && x[0].x > x[2].z)
		{
			const T r = sqrt(T(1) + x[0].x - x[1].y - x[2].z);
			const T invr = static_cast<T>(0.5) / r;
			real.x = static_cast<T>(0.5) * r;
			real.y = (x[1].x + x[0].y) * invr;
			real.z = (x[0].z + x[2].x) * invr;
			real.w = (x[2].y - x[1].z) * invr;
		}
		else if (x[1].y > x[2].z)
		{
			const T r = sqrt(T(1) + x[1].y - x[0].x - x[2].z);
			const T invr = static_cast<T>(0.5) / r;
			real.x = (x[1].x + x[0].y) * invr;
			real.y = static_cast<T>(0.5) * r;
			real.z = (x[2].y + x[1].z) * invr;
			real.w = (x[0].z - x[2].x) * invr;
		}
		else
		{
			const T r = sqrt(T(1) + x[2].z - x[0].x - x[1].y);
			const T invr = static_cast<T>(0.5) / r;
			real.x = (x[0].z + x[2].x) * invr;
			real.y = (x[2].y + x[1].z) * invr;
			real.z = static_cast<T>(0.5) * r;
			real.w = (x[1].x - x[0].y) * invr;
		}

		qua<T, Q> dual;
		dual.x = static_cast<T>(0.5) * (x[0].w * real.w + x[1].w * real.z - x[2].w * real.y);
		dual.y = static_cast<T>(0.5) * (-x[0].w * real.z + x[1].w * real.w + x[2].w * real.x);
		dual.z = static_cast<T>(0.5) * (x[0].w * real.y - x[1].w * real.x + x[2].w * real.w);
		dual.w = -static_cast<T>(0.5) * (x[0].w * real.x + x[1].w * real.y + x[2].w * real.z);
		return tdualquat<T, Q>(real, dual);
	}
} //namespace glm

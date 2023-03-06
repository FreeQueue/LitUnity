#include "../trigonometric.hpp"
#include "../exponential.hpp"
#include "../ext/quaternion_geometric.hpp"
#include <limits>

namespace glm
{
	namespace detail
	{
		template <typename T>
		struct genTypeTrait<qua<T>>
		{
			static const genTypeEnum GENTYPE = GENTYPE_QUAT;
		};

		template <typename T, qualifier Q, bool Aligned>
		struct compute_dot<qua<T, Q>, T, Aligned>
		{
			GLM_FUNC_QUALIFIER GLM_CONSTEXPR static T call(const qua<T, Q>& a, const qua<T, Q>& b)
			{
				vec<4, T, Q> tmp(a.w * b.w, a.x * b.x, a.y * b.y, a.z * b.z);
				return (tmp.x + tmp.y) + (tmp.z + tmp.w);
			}
		};

		template <typename T, qualifier Q, bool Aligned>
		struct compute_quat_add
		{
			GLM_FUNC_QUALIFIER GLM_CONSTEXPR static qua<T, Q> call(const qua<T, Q>& q, const qua<T, Q>& p)
			{
				return qua<T, Q>(q.w + p.w, q.x + p.x, q.y + p.y, q.z + p.z);
			}
		};

		template <typename T, qualifier Q, bool Aligned>
		struct compute_quat_sub
		{
			GLM_FUNC_QUALIFIER GLM_CONSTEXPR static qua<T, Q> call(const qua<T, Q>& q, const qua<T, Q>& p)
			{
				return qua<T, Q>(q.w - p.w, q.x - p.x, q.y - p.y, q.z - p.z);
			}
		};

		template <typename T, qualifier Q, bool Aligned>
		struct compute_quat_mul_scalar
		{
			GLM_FUNC_QUALIFIER GLM_CONSTEXPR static qua<T, Q> call(const qua<T, Q>& q, T s)
			{
				return qua<T, Q>(q.w * s, q.x * s, q.y * s, q.z * s);
			}
		};

		template <typename T, qualifier Q, bool Aligned>
		struct compute_quat_div_scalar
		{
			GLM_FUNC_QUALIFIER GLM_CONSTEXPR static qua<T, Q> call(const qua<T, Q>& q, T s)
			{
				return qua<T, Q>(q.w / s, q.x / s, q.y / s, q.z / s);
			}
		};

		template <typename T, qualifier Q, bool Aligned>
		struct compute_quat_mul_vec4
		{
			GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T, Q> call(const qua<T, Q>& q, const vec<4, T, Q>& v)
			{
				return vec<4, T, Q>(q * vec<3, T, Q>(v), v.w);
			}
		};
	} //namespace detail

	// -- Component accesses --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T& qua<T, Q>::operator[](length_type i)
	{
		assert(i >= 0 && i < this->length());
#		ifdef GLM_FORCE_QUAT_DATA_WXYZ
			return (&w)[i];
#		else
		return (&x)[i];
#		endif
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR const T& qua<T, Q>::operator[](length_type i) const
	{
		assert(i >= 0 && i < this->length());
#		ifdef GLM_FORCE_QUAT_DATA_WXYZ
			return (&w)[i];
#		else
		return (&x)[i];
#		endif
	}

	// -- Implicit basic constructors --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T, qualifier Q>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q>::qua()
#			if GLM_CONFIG_CTOR_INIT != GLM_CTOR_INIT_DISABLE
#				ifdef GLM_FORCE_QUAT_DATA_WXYZ
					: w(1), x(0), y(0), z(0)
#				else
					: x(0), y(0), z(0), w(1)
#				endif
#			endif
		{}

		template<typename T, qualifier Q>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q>::qua(qua<T, Q> const& q)
#			ifdef GLM_FORCE_QUAT_DATA_WXYZ
				: w(q.w), x(q.x), y(q.y), z(q.z)
#			else
				: x(q.x), y(q.y), z(q.z), w(q.w)
#			endif
		{}
#	endif

	template <typename T, qualifier Q>
	template <qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q>::qua(const qua<T, P>& q)
#		ifdef GLM_FORCE_QUAT_DATA_WXYZ
			: w(q.w), x(q.x), y(q.y), z(q.z)
#		else
		: x(q.x), y(q.y), z(q.z), w(q.w)
#		endif
	{
	}

	// -- Explicit basic constructors --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q>::qua(T s, const vec<3, T, Q>& v)
#		ifdef GLM_FORCE_QUAT_DATA_WXYZ
			: w(s), x(v.x), y(v.y), z(v.z)
#		else
		: x(v.x), y(v.y), z(v.z), w(s)
#		endif
	{
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q>::qua(T _w, T _x, T _y, T _z)
#		ifdef GLM_FORCE_QUAT_DATA_WXYZ
			: w(_w), x(_x), y(_y), z(_z)
#		else
		: x(_x), y(_y), z(_z), w(_w)
#		endif
	{
	}

	// -- Conversion constructors --

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q>::qua(const qua<U, P>& q)
#		ifdef GLM_FORCE_QUAT_DATA_WXYZ
			: w(static_cast<T>(q.w)), x(static_cast<T>(q.x)), y(static_cast<T>(q.y)), z(static_cast<T>(q.z))
#		else
		: x(static_cast<T>(q.x)), y(static_cast<T>(q.y)), z(static_cast<T>(q.z)), w(static_cast<T>(q.w))
#		endif
	{
	}

	//template<typename valType>
	//GLM_FUNC_QUALIFIER qua<valType>::qua
	//(
	//	valType const& pitch,
	//	valType const& yaw,
	//	valType const& roll
	//)
	//{
	//	vec<3, valType> eulerAngle(pitch * valType(0.5), yaw * valType(0.5), roll * valType(0.5));
	//	vec<3, valType> c = glm::cos(eulerAngle * valType(0.5));
	//	vec<3, valType> s = glm::sin(eulerAngle * valType(0.5));
	//
	//	this->w = c.x * c.y * c.z + s.x * s.y * s.z;
	//	this->x = s.x * c.y * c.z - c.x * s.y * s.z;
	//	this->y = c.x * s.y * c.z + s.x * c.y * s.z;
	//	this->z = c.x * c.y * s.z - s.x * s.y * c.z;
	//}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER qua<T, Q>::qua(const vec<3, T, Q>& u, const vec<3, T, Q>& v)
	{
		T norm_u_norm_v = sqrt(dot(u, u) * dot(v, v));
		T real_part = norm_u_norm_v + dot(u, v);
		vec<3, T, Q> t;

		if (real_part < static_cast<T>(1.e-6f) * norm_u_norm_v)
		{
			// If u and v are exactly opposite, rotate 180 degrees
			// around an arbitrary orthogonal axis. Axis normalisation
			// can happen later, when we normalise the quaternion.
			real_part = static_cast<T>(0);
			t = abs(u.x) > abs(u.z)
					? vec<3, T, Q>(-u.y, u.x, static_cast<T>(0))
					: vec<3, T, Q>(static_cast<T>(0), -u.z, u.y);
		}
		else
		{
			// Otherwise, build quaternion the standard way.
			t = cross(u, v);
		}

		*this = normalize(qua<T, Q>(real_part, t.x, t.y, t.z));
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q>::qua(const vec<3, T, Q>& eulerAngle)
	{
		vec<3, T, Q> c = glm::cos(eulerAngle * T(0.5));
		vec<3, T, Q> s = glm::sin(eulerAngle * T(0.5));

		this->w = c.x * c.y * c.z + s.x * s.y * s.z;
		this->x = s.x * c.y * c.z - c.x * s.y * s.z;
		this->y = c.x * s.y * c.z + s.x * c.y * s.z;
		this->z = c.x * c.y * s.z - s.x * s.y * c.z;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER qua<T, Q>::qua(const mat<3, 3, T, Q>& m)
	{
		*this = quat_cast(m);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER qua<T, Q>::qua(const mat<4, 4, T, Q>& m)
	{
		*this = quat_cast(m);
	}

#	if GLM_HAS_EXPLICIT_CONVERSION_OPERATORS
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER qua<T, Q>::operator mat<3, 3, T, Q>() const
	{
		return mat3_cast(*this);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER qua<T, Q>::operator mat<4, 4, T, Q>() const
	{
		return mat4_cast(*this);
	}
#	endif//GLM_HAS_EXPLICIT_CONVERSION_OPERATORS

	// -- Unary arithmetic operators --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T, qualifier Q>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q> & qua<T, Q>::operator=(qua<T, Q> const& q)
		{
			this->w = q.w;
			this->x = q.x;
			this->y = q.y;
			this->z = q.z;
			return *this;
		}
#	endif

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q>& qua<T, Q>::operator=(const qua<U, Q>& q)
	{
		this->w = static_cast<T>(q.w);
		this->x = static_cast<T>(q.x);
		this->y = static_cast<T>(q.y);
		this->z = static_cast<T>(q.z);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q>& qua<T, Q>::operator+=(const qua<U, Q>& q)
	{
		return (*this = detail::compute_quat_add<T, Q, detail::is_aligned<Q>::value>::call(*this, qua<T, Q>(q)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q>& qua<T, Q>::operator-=(const qua<U, Q>& q)
	{
		return (*this = detail::compute_quat_sub<T, Q, detail::is_aligned<Q>::value>::call(*this, qua<T, Q>(q)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q>& qua<T, Q>::operator*=(const qua<U, Q>& r)
	{
		const qua<T, Q> p(*this);
		const qua<T, Q> q(r);

		this->w = p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z;
		this->x = p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y;
		this->y = p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z;
		this->z = p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x;
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q>& qua<T, Q>::operator*=(U s)
	{
		return (*this = detail::compute_quat_mul_scalar<T, Q, detail::is_aligned<Q>::value>::call(
			*this, static_cast<U>(s)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q>& qua<T, Q>::operator/=(U s)
	{
		return (*this = detail::compute_quat_div_scalar<T, Q, detail::is_aligned<Q>::value>::call(
			*this, static_cast<U>(s)));
	}

	// -- Unary bit operators --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q> operator+(const qua<T, Q>& q)
	{
		return q;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q> operator-(const qua<T, Q>& q)
	{
		return qua<T, Q>(-q.w, -q.x, -q.y, -q.z);
	}

	// -- Binary operators --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q> operator+(const qua<T, Q>& q, const qua<T, Q>& p)
	{
		return qua<T, Q>(q) += p;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q> operator-(const qua<T, Q>& q, const qua<T, Q>& p)
	{
		return qua<T, Q>(q) -= p;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q> operator*(const qua<T, Q>& q, const qua<T, Q>& p)
	{
		return qua<T, Q>(q) *= p;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> operator*(const qua<T, Q>& q, const vec<3, T, Q>& v)
	{
		const vec<3, T, Q> QuatVector(q.x, q.y, q.z);
		const vec<3, T, Q> uv(glm::cross(QuatVector, v));
		const vec<3, T, Q> uuv(glm::cross(QuatVector, uv));

		return v + ((uv * q.w) + uuv) * static_cast<T>(2);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> operator*(const vec<3, T, Q>& v, const qua<T, Q>& q)
	{
		return glm::inverse(q) * v;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> operator*(const qua<T, Q>& q, const vec<4, T, Q>& v)
	{
		return detail::compute_quat_mul_vec4<T, Q, detail::is_aligned<Q>::value>::call(q, v);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> operator*(const vec<4, T, Q>& v, const qua<T, Q>& q)
	{
		return glm::inverse(q) * v;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q> operator*(const qua<T, Q>& q, const T& s)
	{
		return qua<T, Q>(
			q.w * s, q.x * s, q.y * s, q.z * s);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q> operator*(const T& s, const qua<T, Q>& q)
	{
		return q * s;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q> operator/(const qua<T, Q>& q, const T& s)
	{
		return qua<T, Q>(
			q.w / s, q.x / s, q.y / s, q.z / s);
	}

	// -- Boolean operators --

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator==(const qua<T, Q>& q1, const qua<T, Q>& q2)
	{
		return q1.x == q2.x && q1.y == q2.y && q1.z == q2.z && q1.w == q2.w;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(const qua<T, Q>& q1, const qua<T, Q>& q2)
	{
		return q1.x != q2.x || q1.y != q2.y || q1.z != q2.z || q1.w != q2.w;
	}
} //namespace glm

#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "type_quat_simd.inl"
#endif

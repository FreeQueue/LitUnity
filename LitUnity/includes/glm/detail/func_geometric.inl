#include "../exponential.hpp"
#include "../common.hpp"

namespace glm
{
	namespace detail
	{
		template <length_t L, typename T, qualifier Q, bool Aligned>
		struct compute_length
		{
			GLM_FUNC_QUALIFIER static T call(const vec<L, T, Q>& v)
			{
				return sqrt(dot(v, v));
			}
		};

		template <length_t L, typename T, qualifier Q, bool Aligned>
		struct compute_distance
		{
			GLM_FUNC_QUALIFIER static T call(const vec<L, T, Q>& p0, const vec<L, T, Q>& p1)
			{
				return length(p1 - p0);
			}
		};

		template <typename V, typename T, bool Aligned>
		struct compute_dot
		{
		};

		template <typename T, qualifier Q, bool Aligned>
		struct compute_dot<vec<1, T, Q>, T, Aligned>
		{
			GLM_FUNC_QUALIFIER static T call(const vec<1, T, Q>& a, const vec<1, T, Q>& b)
			{
				return a.x * b.x;
			}
		};

		template <typename T, qualifier Q, bool Aligned>
		struct compute_dot<vec<2, T, Q>, T, Aligned>
		{
			GLM_FUNC_QUALIFIER static T call(const vec<2, T, Q>& a, const vec<2, T, Q>& b)
			{
				vec<2, T, Q> tmp(a * b);
				return tmp.x + tmp.y;
			}
		};

		template <typename T, qualifier Q, bool Aligned>
		struct compute_dot<vec<3, T, Q>, T, Aligned>
		{
			GLM_FUNC_QUALIFIER static T call(const vec<3, T, Q>& a, const vec<3, T, Q>& b)
			{
				vec<3, T, Q> tmp(a * b);
				return tmp.x + tmp.y + tmp.z;
			}
		};

		template <typename T, qualifier Q, bool Aligned>
		struct compute_dot<vec<4, T, Q>, T, Aligned>
		{
			GLM_FUNC_QUALIFIER static T call(const vec<4, T, Q>& a, const vec<4, T, Q>& b)
			{
				vec<4, T, Q> tmp(a * b);
				return (tmp.x + tmp.y) + (tmp.z + tmp.w);
			}
		};

		template <typename T, qualifier Q, bool Aligned>
		struct compute_cross
		{
			GLM_FUNC_QUALIFIER static vec<3, T, Q> call(const vec<3, T, Q>& x, const vec<3, T, Q>& y)
			{
				GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'cross' accepts only floating-point inputs");

				return vec<3, T, Q>(
					x.y * y.z - y.y * x.z,
					x.z * y.x - y.z * x.x,
					x.x * y.y - y.x * x.y);
			}
		};

		template <length_t L, typename T, qualifier Q, bool Aligned>
		struct compute_normalize
		{
			GLM_FUNC_QUALIFIER static vec<L, T, Q> call(const vec<L, T, Q>& v)
			{
				GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'normalize' accepts only floating-point inputs");

				return v * inversesqrt(dot(v, v));
			}
		};

		template <length_t L, typename T, qualifier Q, bool Aligned>
		struct compute_faceforward
		{
			GLM_FUNC_QUALIFIER static vec<L, T, Q> call(const vec<L, T, Q>& N, const vec<L, T, Q>& I,
														const vec<L, T, Q>& Nref)
			{
				GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'normalize' accepts only floating-point inputs");

				return dot(Nref, I) < static_cast<T>(0) ? N : -N;
			}
		};

		template <length_t L, typename T, qualifier Q, bool Aligned>
		struct compute_reflect
		{
			GLM_FUNC_QUALIFIER static vec<L, T, Q> call(const vec<L, T, Q>& I, const vec<L, T, Q>& N)
			{
				return I - N * dot(N, I) * static_cast<T>(2);
			}
		};

		template <length_t L, typename T, qualifier Q, bool Aligned>
		struct compute_refract
		{
			GLM_FUNC_QUALIFIER static vec<L, T, Q> call(const vec<L, T, Q>& I, const vec<L, T, Q>& N, T eta)
			{
				const T dotValue(dot(N, I));
				const T k(static_cast<T>(1) - eta * eta * (static_cast<T>(1) - dotValue * dotValue));
				const vec<L, T, Q> Result =
					(k >= static_cast<T>(0)) ? (eta * I - (eta * dotValue + std::sqrt(k)) * N) : vec<L, T, Q>(0);
				return Result;
			}
		};
	} //namespace detail

	// length
	template <typename genType>
	GLM_FUNC_QUALIFIER genType length(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'length' accepts only floating-point inputs");

		return abs(x);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T length(const vec<L, T, Q>& v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'length' accepts only floating-point inputs");

		return detail::compute_length<L, T, Q, detail::is_aligned<Q>::value>::call(v);
	}

	// distance
	template <typename genType>
	GLM_FUNC_QUALIFIER genType distance(const genType& p0, const genType& p1)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'distance' accepts only floating-point inputs");

		return length(p1 - p0);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T distance(const vec<L, T, Q>& p0, const vec<L, T, Q>& p1)
	{
		return detail::compute_distance<L, T, Q, detail::is_aligned<Q>::value>::call(p0, p1);
	}

	// dot
	template <typename T>
	GLM_FUNC_QUALIFIER T dot(T x, T y)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'dot' accepts only floating-point inputs");
		return x * y;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T dot(const vec<L, T, Q>& x, const vec<L, T, Q>& y)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'dot' accepts only floating-point inputs");
		return detail::compute_dot<vec<L, T, Q>, T, detail::is_aligned<Q>::value>::call(x, y);
	}

	// cross
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> cross(const vec<3, T, Q>& x, const vec<3, T, Q>& y)
	{
		return detail::compute_cross<T, Q, detail::is_aligned<Q>::value>::call(x, y);
	}

	/*
		// normalize
		template<typename genType>
		GLM_FUNC_QUALIFIER genType normalize(genType const& x)
		{
			GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'normalize' accepts only floating-point inputs");
	
			return x < genType(0) ? genType(-1) : genType(1);
		}
	*/
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> normalize(const vec<L, T, Q>& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'normalize' accepts only floating-point inputs");

		return detail::compute_normalize<L, T, Q, detail::is_aligned<Q>::value>::call(x);
	}

	// faceforward
	template <typename genType>
	GLM_FUNC_QUALIFIER genType faceforward(const genType& N, const genType& I, const genType& Nref)
	{
		return dot(Nref, I) < static_cast<genType>(0) ? N : -N;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> faceforward(const vec<L, T, Q>& N, const vec<L, T, Q>& I, const vec<L, T, Q>& Nref)
	{
		return detail::compute_faceforward<L, T, Q, detail::is_aligned<Q>::value>::call(N, I, Nref);
	}

	// reflect
	template <typename genType>
	GLM_FUNC_QUALIFIER genType reflect(const genType& I, const genType& N)
	{
		return I - N * dot(N, I) * genType(2);
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> reflect(const vec<L, T, Q>& I, const vec<L, T, Q>& N)
	{
		return detail::compute_reflect<L, T, Q, detail::is_aligned<Q>::value>::call(I, N);
	}

	// refract
	template <typename genType>
	GLM_FUNC_QUALIFIER genType refract(const genType& I, const genType& N, genType eta)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'refract' accepts only floating-point inputs");
		const genType dotValue(dot(N, I));
		const genType k(static_cast<genType>(1) - eta * eta * (static_cast<genType>(1) - dotValue * dotValue));
		return (eta * I - (eta * dotValue + sqrt(k)) * N) * static_cast<genType>(k >= static_cast<genType>(0));
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> refract(const vec<L, T, Q>& I, const vec<L, T, Q>& N, T eta)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'refract' accepts only floating-point inputs");
		return detail::compute_refract<L, T, Q, detail::is_aligned<Q>::value>::call(I, N, eta);
	}
} //namespace glm

#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "func_geometric_simd.inl"
#endif

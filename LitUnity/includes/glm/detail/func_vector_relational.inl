namespace glm
{
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> lessThan(const vec<L, T, Q>& x, const vec<L, T, Q>& y)
	{
		vec<L, bool, Q> Result(true);
		for (length_t i = 0; i < L; ++i)
			Result[i] = x[i] < y[i];
		return Result;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> lessThanEqual(const vec<L, T, Q>& x, const vec<L, T, Q>& y)
	{
		vec<L, bool, Q> Result(true);
		for (length_t i = 0; i < L; ++i)
			Result[i] = x[i] <= y[i];
		return Result;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> greaterThan(const vec<L, T, Q>& x, const vec<L, T, Q>& y)
	{
		vec<L, bool, Q> Result(true);
		for (length_t i = 0; i < L; ++i)
			Result[i] = x[i] > y[i];
		return Result;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> greaterThanEqual(const vec<L, T, Q>& x, const vec<L, T, Q>& y)
	{
		vec<L, bool, Q> Result(true);
		for (length_t i = 0; i < L; ++i)
			Result[i] = x[i] >= y[i];
		return Result;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> equal(const vec<L, T, Q>& x, const vec<L, T, Q>& y)
	{
		vec<L, bool, Q> Result(true);
		for (length_t i = 0; i < L; ++i)
			Result[i] = x[i] == y[i];
		return Result;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> notEqual(const vec<L, T, Q>& x, const vec<L, T, Q>& y)
	{
		vec<L, bool, Q> Result(true);
		for (length_t i = 0; i < L; ++i)
			Result[i] = x[i] != y[i];
		return Result;
	}

	template <length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool any(const vec<L, bool, Q>& v)
	{
		bool Result = false;
		for (length_t i = 0; i < L; ++i)
			Result = Result || v[i];
		return Result;
	}

	template <length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool all(const vec<L, bool, Q>& v)
	{
		bool Result = true;
		for (length_t i = 0; i < L; ++i)
			Result = Result && v[i];
		return Result;
	}

	template <length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool, Q> not_(const vec<L, bool, Q>& v)
	{
		vec<L, bool, Q> Result(true);
		for (length_t i = 0; i < L; ++i)
			Result[i] = !v[i];
		return Result;
	}
} //namespace glm

#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "func_vector_relational_simd.inl"
#endif

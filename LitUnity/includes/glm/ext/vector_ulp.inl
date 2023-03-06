namespace glm
{
	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> nextFloat(const vec<L, T, Q>& x)
	{
		vec<L, T, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = nextFloat(x[i]);
		return Result;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> nextFloat(const vec<L, T, Q>& x, int ULPs)
	{
		vec<L, T, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = nextFloat(x[i], ULPs);
		return Result;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> nextFloat(const vec<L, T, Q>& x, const vec<L, int, Q>& ULPs)
	{
		vec<L, T, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = nextFloat(x[i], ULPs[i]);
		return Result;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> prevFloat(const vec<L, T, Q>& x)
	{
		vec<L, T, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = prevFloat(x[i]);
		return Result;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> prevFloat(const vec<L, T, Q>& x, int ULPs)
	{
		vec<L, T, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = prevFloat(x[i], ULPs);
		return Result;
	}

	template <length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> prevFloat(const vec<L, T, Q>& x, const vec<L, int, Q>& ULPs)
	{
		vec<L, T, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = prevFloat(x[i], ULPs[i]);
		return Result;
	}

	template <length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, int, Q> floatDistance(const vec<L, float, Q>& x, const vec<L, float, Q>& y)
	{
		vec<L, int, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = floatDistance(x[i], y[i]);
		return Result;
	}

	template <length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, int64, Q> floatDistance(const vec<L, double, Q>& x, const vec<L, double, Q>& y)
	{
		vec<L, int64, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = floatDistance(x[i], y[i]);
		return Result;
	}
} //namespace glm

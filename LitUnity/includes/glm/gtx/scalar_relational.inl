/// @ref gtx_scalar_relational

namespace glm
{
	template <typename T>
	GLM_FUNC_QUALIFIER bool lessThan
	(
		const T& x,
		const T& y
	)
	{
		return x < y;
	}

	template <typename T>
	GLM_FUNC_QUALIFIER bool lessThanEqual
	(
		const T& x,
		const T& y
	)
	{
		return x <= y;
	}

	template <typename T>
	GLM_FUNC_QUALIFIER bool greaterThan
	(
		const T& x,
		const T& y
	)
	{
		return x > y;
	}

	template <typename T>
	GLM_FUNC_QUALIFIER bool greaterThanEqual
	(
		const T& x,
		const T& y
	)
	{
		return x >= y;
	}

	template <typename T>
	GLM_FUNC_QUALIFIER bool equal
	(
		const T& x,
		const T& y
	)
	{
		return detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(x, y);
	}

	template <typename T>
	GLM_FUNC_QUALIFIER bool notEqual
	(
		const T& x,
		const T& y
	)
	{
		return !detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(x, y);
	}

	GLM_FUNC_QUALIFIER bool any
	(
		const bool& x
	)
	{
		return x;
	}

	GLM_FUNC_QUALIFIER bool all
	(
		const bool& x
	)
	{
		return x;
	}

	GLM_FUNC_QUALIFIER bool not_
	(
		const bool& x
	)
	{
		return !x;
	}
} //namespace glm

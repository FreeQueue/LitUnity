#include "../common.hpp"
#include "../ext/scalar_int_sized.hpp"
#include "../ext/scalar_uint_sized.hpp"
#include "../detail/type_float.hpp"

namespace glm
{
	template <typename genType>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool equal(const genType& x, const genType& y, const genType& epsilon)
	{
		return abs(x - y) <= epsilon;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool notEqual(const genType& x, const genType& y, const genType& epsilon)
	{
		return abs(x - y) > epsilon;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool equal(const genType& x, const genType& y, int MaxULPs)
	{
		const detail::float_t<genType> a(x);
		const detail::float_t<genType> b(y);

		// Different signs means they do not match.
		if (a.negative() != b.negative())
			return false;

		// Find the difference in ULPs.
		const typename detail::float_t<genType>::int_type DiffULPs = abs(a.i - b.i);
		return DiffULPs <= MaxULPs;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool notEqual(const genType& x, const genType& y, int ULPs)
	{
		return !equal(x, y, ULPs);
	}
} //namespace glm

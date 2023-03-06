/// @ref gtx_functions

#include "../exponential.hpp"

namespace glm
{
	template <typename T>
	GLM_FUNC_QUALIFIER T gauss
	(
		T x,
		T ExpectedValue,
		T StandardDeviation
	)
	{
		return exp(
				-((x - ExpectedValue) * (x - ExpectedValue)) / (static_cast<T>(2) * StandardDeviation *
					StandardDeviation))
			/ (StandardDeviation * sqrt(static_cast<T>(6.28318530717958647692528676655900576)));
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T gauss
	(
		const vec<2, T, Q>& Coord,
		const vec<2, T, Q>& ExpectedValue,
		const vec<2, T, Q>& StandardDeviation
	)
	{
		const vec<2, T, Q> Squared = ((Coord - ExpectedValue) * (Coord - ExpectedValue)) / (static_cast<T>(2) *
			StandardDeviation * StandardDeviation);
		return exp(-(Squared.x + Squared.y));
	}
} //namespace glm

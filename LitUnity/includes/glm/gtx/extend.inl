/// @ref gtx_extend

namespace glm
{
	template <typename genType>
	GLM_FUNC_QUALIFIER genType extend
	(
		const genType& Origin,
		const genType& Source,
		const genType& Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<2, T, Q> extend
	(
		const vec<2, T, Q>& Origin,
		const vec<2, T, Q>& Source,
		const T& Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> extend
	(
		const vec<3, T, Q>& Origin,
		const vec<3, T, Q>& Source,
		const T& Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, T, Q> extend
	(
		const vec<4, T, Q>& Origin,
		const vec<4, T, Q>& Source,
		const T& Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}
} //namespace glm

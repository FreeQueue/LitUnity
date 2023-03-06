/// @ref gtx_optimum_pow

namespace glm
{
	template <typename genType>
	GLM_FUNC_QUALIFIER genType pow2(const genType& x)
	{
		return x * x;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER genType pow3(const genType& x)
	{
		return x * x * x;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER genType pow4(const genType& x)
	{
		return (x * x) * (x * x);
	}
} //namespace glm

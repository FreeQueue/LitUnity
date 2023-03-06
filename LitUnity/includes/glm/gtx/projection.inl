/// @ref gtx_projection

namespace glm
{
	template <typename genType>
	GLM_FUNC_QUALIFIER genType proj(const genType& x, const genType& Normal)
	{
		return glm::dot(x, Normal) / glm::dot(Normal, Normal) * Normal;
	}
} //namespace glm

/// @ref gtx_perpendicular

namespace glm
{
	template <typename genType>
	GLM_FUNC_QUALIFIER genType perp(const genType& x, const genType& Normal)
	{
		return x - proj(x, Normal);
	}
} //namespace glm

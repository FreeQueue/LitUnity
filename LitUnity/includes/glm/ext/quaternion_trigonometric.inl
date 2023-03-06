#include "scalar_constants.hpp"

namespace glm
{
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T angle(const qua<T, Q>& x)
	{
		if (abs(x.w) > cos_one_over_two<T>())
		{
			return asin(sqrt(x.x * x.x + x.y * x.y + x.z * x.z)) * static_cast<T>(2);
		}

		return acos(x.w) * static_cast<T>(2);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> axis(const qua<T, Q>& x)
	{
		const T tmp1 = static_cast<T>(1) - x.w * x.w;
		if (tmp1 <= static_cast<T>(0))
			return vec<3, T, Q>(0, 0, 1);
		const T tmp2 = static_cast<T>(1) / sqrt(tmp1);
		return vec<3, T, Q>(x.x * tmp2, x.y * tmp2, x.z * tmp2);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER qua<T, Q> angleAxis(const T& angle, const vec<3, T, Q>& v)
	{
		const T a(angle);
		const T s = glm::sin(a * static_cast<T>(0.5));

		return qua<T, Q>(glm::cos(a * static_cast<T>(0.5)), v * s);
	}
} //namespace glm

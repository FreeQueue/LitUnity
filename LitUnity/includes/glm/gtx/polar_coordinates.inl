/// @ref gtx_polar_coordinates

namespace glm
{
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> polar
	(
		const vec<3, T, Q>& euclidean
	)
	{
		const T Length(length(euclidean));
		const vec<3, T, Q> tmp(euclidean / Length);
		const T xz_dist(sqrt(tmp.x * tmp.x + tmp.z * tmp.z));

		return vec<3, T, Q>(
			asin(tmp.y), // latitude
			atan(tmp.x, tmp.z), // longitude
			xz_dist); // xz distance
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> euclidean
	(
		const vec<2, T, Q>& polar
	)
	{
		const T latitude(polar.x);
		const T longitude(polar.y);

		return vec<3, T, Q>(
			cos(latitude) * sin(longitude),
			sin(latitude),
			cos(latitude) * cos(longitude));
	}
} //namespace glm

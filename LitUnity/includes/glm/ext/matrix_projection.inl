namespace glm
{
	template <typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> projectZO(const vec<3, T, Q>& obj, const mat<4, 4, T, Q>& model,
											const mat<4, 4, T, Q>& proj, const vec<4, U, Q>& viewport)
	{
		vec<4, T, Q> tmp = vec<4, T, Q>(obj, static_cast<T>(1));
		tmp = model * tmp;
		tmp = proj * tmp;

		tmp /= tmp.w;
		tmp.x = tmp.x * static_cast<T>(0.5) + static_cast<T>(0.5);
		tmp.y = tmp.y * static_cast<T>(0.5) + static_cast<T>(0.5);

		tmp[0] = tmp[0] * T(viewport[2]) + T(viewport[0]);
		tmp[1] = tmp[1] * T(viewport[3]) + T(viewport[1]);

		return vec<3, T, Q>(tmp);
	}

	template <typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> projectNO(const vec<3, T, Q>& obj, const mat<4, 4, T, Q>& model,
											const mat<4, 4, T, Q>& proj, const vec<4, U, Q>& viewport)
	{
		vec<4, T, Q> tmp = vec<4, T, Q>(obj, static_cast<T>(1));
		tmp = model * tmp;
		tmp = proj * tmp;

		tmp /= tmp.w;
		tmp = tmp * static_cast<T>(0.5) + static_cast<T>(0.5);
		tmp[0] = tmp[0] * T(viewport[2]) + T(viewport[0]);
		tmp[1] = tmp[1] * T(viewport[3]) + T(viewport[1]);

		return vec<3, T, Q>(tmp);
	}

	template <typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> project(const vec<3, T, Q>& obj, const mat<4, 4, T, Q>& model,
											const mat<4, 4, T, Q>& proj, const vec<4, U, Q>& viewport)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_ZO_BIT
			return projectZO(obj, model, proj, viewport);
#		else
		return projectNO(obj, model, proj, viewport);
#		endif
	}

	template <typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> unProjectZO(const vec<3, T, Q>& win, const mat<4, 4, T, Q>& model,
												const mat<4, 4, T, Q>& proj, const vec<4, U, Q>& viewport)
	{
		mat<4, 4, T, Q> Inverse = inverse(proj * model);

		vec<4, T, Q> tmp = vec<4, T, Q>(win, T(1));
		tmp.x = (tmp.x - T(viewport[0])) / T(viewport[2]);
		tmp.y = (tmp.y - T(viewport[1])) / T(viewport[3]);
		tmp.x = tmp.x * static_cast<T>(2) - static_cast<T>(1);
		tmp.y = tmp.y * static_cast<T>(2) - static_cast<T>(1);

		vec<4, T, Q> obj = Inverse * tmp;
		obj /= obj.w;

		return vec<3, T, Q>(obj);
	}

	template <typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> unProjectNO(const vec<3, T, Q>& win, const mat<4, 4, T, Q>& model,
												const mat<4, 4, T, Q>& proj, const vec<4, U, Q>& viewport)
	{
		mat<4, 4, T, Q> Inverse = inverse(proj * model);

		vec<4, T, Q> tmp = vec<4, T, Q>(win, T(1));
		tmp.x = (tmp.x - T(viewport[0])) / T(viewport[2]);
		tmp.y = (tmp.y - T(viewport[1])) / T(viewport[3]);
		tmp = tmp * static_cast<T>(2) - static_cast<T>(1);

		vec<4, T, Q> obj = Inverse * tmp;
		obj /= obj.w;

		return vec<3, T, Q>(obj);
	}

	template <typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> unProject(const vec<3, T, Q>& win, const mat<4, 4, T, Q>& model,
											const mat<4, 4, T, Q>& proj, const vec<4, U, Q>& viewport)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_ZO_BIT
			return unProjectZO(win, model, proj, viewport);
#		else
		return unProjectNO(win, model, proj, viewport);
#		endif
	}

	template <typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> pickMatrix(const vec<2, T, Q>& center, const vec<2, T, Q>& delta,
												const vec<4, U, Q>& viewport)
	{
		assert(delta.x > static_cast<T>(0) && delta.y > static_cast<T>(0));
		mat<4, 4, T, Q> Result(static_cast<T>(1));

		if (!(delta.x > static_cast<T>(0) && delta.y > static_cast<T>(0)))
			return Result; // Error

		vec<3, T, Q> Temp(
			(static_cast<T>(viewport[2]) - static_cast<T>(2) * (center.x - static_cast<T>(viewport[0]))) / delta.x,
			(static_cast<T>(viewport[3]) - static_cast<T>(2) * (center.y - static_cast<T>(viewport[1]))) / delta.y,
			static_cast<T>(0));

		// Translate and scale the picked region to the entire window
		Result = translate(Result, Temp);
		return scale(Result, vec<3, T, Q>(static_cast<T>(viewport[2]) / delta.x, static_cast<T>(viewport[3]) / delta.y,
										static_cast<T>(1)));
	}
} //namespace glm

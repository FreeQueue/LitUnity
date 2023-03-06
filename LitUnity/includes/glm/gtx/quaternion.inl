/// @ref gtx_quaternion

#include <limits>
#include "../gtc/constants.hpp"

namespace glm
{
	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T, Q> quat_identity()
	{
		return qua<T, Q>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> cross(const vec<3, T, Q>& v, const qua<T, Q>& q)
	{
		return inverse(q) * v;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> cross(const qua<T, Q>& q, const vec<3, T, Q>& v)
	{
		return q * v;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER qua<T, Q> squad
	(
		const qua<T, Q>& q1,
		const qua<T, Q>& q2,
		const qua<T, Q>& s1,
		const qua<T, Q>& s2,
		const T& h)
	{
		return mix(mix(q1, q2, h), mix(s1, s2, h), static_cast<T>(2) * (static_cast<T>(1) - h) * h);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER qua<T, Q> intermediate
	(
		const qua<T, Q>& prev,
		const qua<T, Q>& curr,
		const qua<T, Q>& next
	)
	{
		qua<T, Q> invQuat = inverse(curr);
		return exp((log(next * invQuat) + log(prev * invQuat)) / static_cast<T>(-4)) * curr;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> rotate(const qua<T, Q>& q, const vec<3, T, Q>& v)
	{
		return q * v;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, T, Q> rotate(const qua<T, Q>& q, const vec<4, T, Q>& v)
	{
		return q * v;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T extractRealComponent(const qua<T, Q>& q)
	{
		T w = static_cast<T>(1) - q.x * q.x - q.y * q.y - q.z * q.z;
		if (w < T(0))
			return T(0);
		return -sqrt(w);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T length2(const qua<T, Q>& q)
	{
		return q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER qua<T, Q> shortMix(const qua<T, Q>& x, const qua<T, Q>& y, const T& a)
	{
		if (a <= static_cast<T>(0)) return x;
		if (a >= static_cast<T>(1)) return y;

		T fCos = dot(x, y);
		qua<T, Q> y2(y); //BUG!!! qua<T> y2;
		if (fCos < static_cast<T>(0))
		{
			y2 = -y;
			fCos = -fCos;
		}

		//if(fCos > 1.0f) // problem
		T k0, k1;
		if (fCos > (static_cast<T>(1) - epsilon<T>()))
		{
			k0 = static_cast<T>(1) - a;
			k1 = static_cast<T>(0) + a; //BUG!!! 1.0f + a;
		}
		else
		{
			T fSin = sqrt(T(1) - fCos * fCos);
			T fAngle = atan(fSin, fCos);
			T fOneOverSin = static_cast<T>(1) / fSin;
			k0 = sin((static_cast<T>(1) - a) * fAngle) * fOneOverSin;
			k1 = sin((static_cast<T>(0) + a) * fAngle) * fOneOverSin;
		}

		return qua<T, Q>(
			k0 * x.w + k1 * y2.w,
			k0 * x.x + k1 * y2.x,
			k0 * x.y + k1 * y2.y,
			k0 * x.z + k1 * y2.z);
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER qua<T, Q> fastMix(const qua<T, Q>& x, const qua<T, Q>& y, const T& a)
	{
		return glm::normalize(x * (static_cast<T>(1) - a) + (y * a));
	}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER qua<T, Q> rotation(const vec<3, T, Q>& orig, const vec<3, T, Q>& dest)
	{
		T cosTheta = dot(orig, dest);
		vec<3, T, Q> rotationAxis;

		if (cosTheta >= static_cast<T>(1) - epsilon<T>())
		{
			// orig and dest point in the same direction
			return quat_identity<T, Q>();
		}

		if (cosTheta < static_cast<T>(-1) + epsilon<T>())
		{
			// special case when vectors in opposite directions :
			// there is no "ideal" rotation axis
			// So guess one; any will do as long as it's perpendicular to start
			// This implementation favors a rotation around the Up axis (Y),
			// since it's often what you want to do.
			rotationAxis = cross(vec<3, T, Q>(0, 0, 1), orig);
			if (length2(rotationAxis) < epsilon<T>()) // bad luck, they were parallel, try again!
				rotationAxis = cross(vec<3, T, Q>(1, 0, 0), orig);

			rotationAxis = normalize(rotationAxis);
			return angleAxis(pi<T>(), rotationAxis);
		}

		// Implementation from Stan Melax's Game Programming Gems 1 article
		rotationAxis = cross(orig, dest);

		T s = sqrt((T(1) + cosTheta) * static_cast<T>(2));
		T invs = static_cast<T>(1) / s;

		return qua<T, Q>(
			s * static_cast<T>(0.5f),
			rotationAxis.x * invs,
			rotationAxis.y * invs,
			rotationAxis.z * invs);
	}
} //namespace glm

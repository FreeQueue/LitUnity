/// @ref gtx_string_cast

#include <cstdarg>
#include <cstdio>

namespace glm
{
	namespace detail
	{
		template <typename T>
		struct cast
		{
			using value_type = T;
		};

		template <>
		struct cast<float>
		{
			using value_type = double;
		};

		GLM_FUNC_QUALIFIER std::string format(const char* msg, ...)
		{
			const std::size_t STRING_BUFFER(4096);
			char text[STRING_BUFFER];
			va_list list;

			if (msg == GLM_NULLPTR)
				return std::string();

			va_start(list, msg);
#		if (GLM_COMPILER & GLM_COMPILER_VC)
			vsprintf_s(text, STRING_BUFFER, msg, list);
#		else//
			std::vsprintf(text, msg, list);
#		endif//
			va_end(list);

			return std::string(text);
		}

		static const char* LabelTrue = "true";
		static const char* LabelFalse = "false";

		template <typename T, bool isFloat = false>
		struct literal
		{
			GLM_FUNC_QUALIFIER static const char* value() { return "%d"; }
		};

		template <typename T>
		struct literal<T, true>
		{
			GLM_FUNC_QUALIFIER static const char* value() { return "%f"; }
		};

#	if GLM_MODEL == GLM_MODEL_32 && GLM_COMPILER && GLM_COMPILER_VC
	template<>
	struct literal<uint64_t, false>
	{
		GLM_FUNC_QUALIFIER static char const * value() {return "%lld";}
	};

	template<>
	struct literal<int64_t, false>
	{
		GLM_FUNC_QUALIFIER static char const * value() {return "%lld";}
	};
#	endif//GLM_MODEL == GLM_MODEL_32 && GLM_COMPILER && GLM_COMPILER_VC

		template <typename T>
		struct prefix
		{
		};

		template <>
		struct prefix<float>
		{
			GLM_FUNC_QUALIFIER static const char* value() { return ""; }
		};

		template <>
		struct prefix<double>
		{
			GLM_FUNC_QUALIFIER static const char* value() { return "d"; }
		};

		template <>
		struct prefix<bool>
		{
			GLM_FUNC_QUALIFIER static const char* value() { return "b"; }
		};

		template <>
		struct prefix<uint8_t>
		{
			GLM_FUNC_QUALIFIER static const char* value() { return "u8"; }
		};

		template <>
		struct prefix<int8_t>
		{
			GLM_FUNC_QUALIFIER static const char* value() { return "i8"; }
		};

		template <>
		struct prefix<uint16_t>
		{
			GLM_FUNC_QUALIFIER static const char* value() { return "u16"; }
		};

		template <>
		struct prefix<int16_t>
		{
			GLM_FUNC_QUALIFIER static const char* value() { return "i16"; }
		};

		template <>
		struct prefix<uint32_t>
		{
			GLM_FUNC_QUALIFIER static const char* value() { return "u"; }
		};

		template <>
		struct prefix<int32_t>
		{
			GLM_FUNC_QUALIFIER static const char* value() { return "i"; }
		};

		template <>
		struct prefix<uint64_t>
		{
			GLM_FUNC_QUALIFIER static const char* value() { return "u64"; }
		};

		template <>
		struct prefix<int64_t>
		{
			GLM_FUNC_QUALIFIER static const char* value() { return "i64"; }
		};

		template <typename matType>
		struct compute_to_string
		{
		};

		template <qualifier Q>
		struct compute_to_string<vec<1, bool, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const vec<1, bool, Q>& x)
			{
				return detail::format("bvec1(%s)",
									x[0] ? LabelTrue : LabelFalse);
			}
		};

		template <qualifier Q>
		struct compute_to_string<vec<2, bool, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const vec<2, bool, Q>& x)
			{
				return detail::format("bvec2(%s, %s)",
									x[0] ? LabelTrue : LabelFalse,
									x[1] ? LabelTrue : LabelFalse);
			}
		};

		template <qualifier Q>
		struct compute_to_string<vec<3, bool, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const vec<3, bool, Q>& x)
			{
				return detail::format("bvec3(%s, %s, %s)",
									x[0] ? LabelTrue : LabelFalse,
									x[1] ? LabelTrue : LabelFalse,
									x[2] ? LabelTrue : LabelFalse);
			}
		};

		template <qualifier Q>
		struct compute_to_string<vec<4, bool, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const vec<4, bool, Q>& x)
			{
				return detail::format("bvec4(%s, %s, %s, %s)",
									x[0] ? LabelTrue : LabelFalse,
									x[1] ? LabelTrue : LabelFalse,
									x[2] ? LabelTrue : LabelFalse,
									x[3] ? LabelTrue : LabelFalse);
			}
		};

		template <typename T, qualifier Q>
		struct compute_to_string<vec<1, T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const vec<1, T, Q>& x)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format("%svec1(%s)",
											PrefixStr,
											LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(x[0]));
			}
		};

		template <typename T, qualifier Q>
		struct compute_to_string<vec<2, T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const vec<2, T, Q>& x)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format("%svec2(%s, %s)",
											PrefixStr,
											LiteralStr, LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(x[0]),
									static_cast<typename cast<T>::value_type>(x[1]));
			}
		};

		template <typename T, qualifier Q>
		struct compute_to_string<vec<3, T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const vec<3, T, Q>& x)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format("%svec3(%s, %s, %s)",
											PrefixStr,
											LiteralStr, LiteralStr, LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(x[0]),
									static_cast<typename cast<T>::value_type>(x[1]),
									static_cast<typename cast<T>::value_type>(x[2]));
			}
		};

		template <typename T, qualifier Q>
		struct compute_to_string<vec<4, T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const vec<4, T, Q>& x)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format("%svec4(%s, %s, %s, %s)",
											PrefixStr,
											LiteralStr, LiteralStr, LiteralStr, LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(x[0]),
									static_cast<typename cast<T>::value_type>(x[1]),
									static_cast<typename cast<T>::value_type>(x[2]),
									static_cast<typename cast<T>::value_type>(x[3]));
			}
		};


		template <typename T, qualifier Q>
		struct compute_to_string<mat<2, 2, T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const mat<2, 2, T, Q>& x)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format("%smat2x2((%s, %s), (%s, %s))",
											PrefixStr,
											LiteralStr, LiteralStr,
											LiteralStr, LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(x[0][0]),
									static_cast<typename cast<T>::value_type>(x[0][1]),
									static_cast<typename cast<T>::value_type>(x[1][0]),
									static_cast<typename cast<T>::value_type>(x[1][1]));
			}
		};

		template <typename T, qualifier Q>
		struct compute_to_string<mat<2, 3, T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const mat<2, 3, T, Q>& x)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format("%smat2x3((%s, %s, %s), (%s, %s, %s))",
											PrefixStr,
											LiteralStr, LiteralStr, LiteralStr,
											LiteralStr, LiteralStr, LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(x[0][0]),
									static_cast<typename cast<T>::value_type>(x[0][1]),
									static_cast<typename cast<T>::value_type>(x[0][2]),
									static_cast<typename cast<T>::value_type>(x[1][0]),
									static_cast<typename cast<T>::value_type>(x[1][1]),
									static_cast<typename cast<T>::value_type>(x[1][2]));
			}
		};

		template <typename T, qualifier Q>
		struct compute_to_string<mat<2, 4, T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const mat<2, 4, T, Q>& x)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format("%smat2x4((%s, %s, %s, %s), (%s, %s, %s, %s))",
											PrefixStr,
											LiteralStr, LiteralStr, LiteralStr, LiteralStr,
											LiteralStr, LiteralStr, LiteralStr, LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(x[0][0]),
									static_cast<typename cast<T>::value_type>(x[0][1]),
									static_cast<typename cast<T>::value_type>(x[0][2]),
									static_cast<typename cast<T>::value_type>(x[0][3]),
									static_cast<typename cast<T>::value_type>(x[1][0]),
									static_cast<typename cast<T>::value_type>(x[1][1]),
									static_cast<typename cast<T>::value_type>(x[1][2]),
									static_cast<typename cast<T>::value_type>(x[1][3]));
			}
		};

		template <typename T, qualifier Q>
		struct compute_to_string<mat<3, 2, T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const mat<3, 2, T, Q>& x)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format("%smat3x2((%s, %s), (%s, %s), (%s, %s))",
											PrefixStr,
											LiteralStr, LiteralStr,
											LiteralStr, LiteralStr,
											LiteralStr, LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(x[0][0]),
									static_cast<typename cast<T>::value_type>(x[0][1]),
									static_cast<typename cast<T>::value_type>(x[1][0]),
									static_cast<typename cast<T>::value_type>(x[1][1]),
									static_cast<typename cast<T>::value_type>(x[2][0]),
									static_cast<typename cast<T>::value_type>(x[2][1]));
			}
		};

		template <typename T, qualifier Q>
		struct compute_to_string<mat<3, 3, T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const mat<3, 3, T, Q>& x)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format("%smat3x3((%s, %s, %s), (%s, %s, %s), (%s, %s, %s))",
											PrefixStr,
											LiteralStr, LiteralStr, LiteralStr,
											LiteralStr, LiteralStr, LiteralStr,
											LiteralStr, LiteralStr, LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(x[0][0]),
									static_cast<typename cast<T>::value_type>(x[0][1]),
									static_cast<typename cast<T>::value_type>(x[0][2]),
									static_cast<typename cast<T>::value_type>(x[1][0]),
									static_cast<typename cast<T>::value_type>(x[1][1]),
									static_cast<typename cast<T>::value_type>(x[1][2]),
									static_cast<typename cast<T>::value_type>(x[2][0]),
									static_cast<typename cast<T>::value_type>(x[2][1]),
									static_cast<typename cast<T>::value_type>(x[2][2]));
			}
		};

		template <typename T, qualifier Q>
		struct compute_to_string<mat<3, 4, T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const mat<3, 4, T, Q>& x)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format("%smat3x4((%s, %s, %s, %s), (%s, %s, %s, %s), (%s, %s, %s, %s))",
											PrefixStr,
											LiteralStr, LiteralStr, LiteralStr, LiteralStr,
											LiteralStr, LiteralStr, LiteralStr, LiteralStr,
											LiteralStr, LiteralStr, LiteralStr, LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(x[0][0]),
									static_cast<typename cast<T>::value_type>(x[0][1]),
									static_cast<typename cast<T>::value_type>(x[0][2]),
									static_cast<typename cast<T>::value_type>(x[0][3]),
									static_cast<typename cast<T>::value_type>(x[1][0]),
									static_cast<typename cast<T>::value_type>(x[1][1]),
									static_cast<typename cast<T>::value_type>(x[1][2]),
									static_cast<typename cast<T>::value_type>(x[1][3]),
									static_cast<typename cast<T>::value_type>(x[2][0]),
									static_cast<typename cast<T>::value_type>(x[2][1]),
									static_cast<typename cast<T>::value_type>(x[2][2]),
									static_cast<typename cast<T>::value_type>(x[2][3]));
			}
		};

		template <typename T, qualifier Q>
		struct compute_to_string<mat<4, 2, T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const mat<4, 2, T, Q>& x)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format("%smat4x2((%s, %s), (%s, %s), (%s, %s), (%s, %s))",
											PrefixStr,
											LiteralStr, LiteralStr,
											LiteralStr, LiteralStr,
											LiteralStr, LiteralStr,
											LiteralStr, LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(x[0][0]),
									static_cast<typename cast<T>::value_type>(x[0][1]),
									static_cast<typename cast<T>::value_type>(x[1][0]),
									static_cast<typename cast<T>::value_type>(x[1][1]),
									static_cast<typename cast<T>::value_type>(x[2][0]),
									static_cast<typename cast<T>::value_type>(x[2][1]),
									static_cast<typename cast<T>::value_type>(x[3][0]),
									static_cast<typename cast<T>::value_type>(x[3][1]));
			}
		};

		template <typename T, qualifier Q>
		struct compute_to_string<mat<4, 3, T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const mat<4, 3, T, Q>& x)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format("%smat4x3((%s, %s, %s), (%s, %s, %s), (%s, %s, %s), (%s, %s, %s))",
											PrefixStr,
											LiteralStr, LiteralStr, LiteralStr,
											LiteralStr, LiteralStr, LiteralStr,
											LiteralStr, LiteralStr, LiteralStr,
											LiteralStr, LiteralStr, LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(x[0][0]),
									static_cast<typename cast<T>::value_type>(x[0][1]),
									static_cast<typename cast<T>::value_type>(x[0][2]),
									static_cast<typename cast<T>::value_type>(x[1][0]),
									static_cast<typename cast<T>::value_type>(x[1][1]),
									static_cast<typename cast<T>::value_type>(x[1][2]),
									static_cast<typename cast<T>::value_type>(x[2][0]),
									static_cast<typename cast<T>::value_type>(x[2][1]),
									static_cast<typename cast<T>::value_type>(x[2][2]),
									static_cast<typename cast<T>::value_type>(x[3][0]),
									static_cast<typename cast<T>::value_type>(x[3][1]),
									static_cast<typename cast<T>::value_type>(x[3][2]));
			}
		};

		template <typename T, qualifier Q>
		struct compute_to_string<mat<4, 4, T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const mat<4, 4, T, Q>& x)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format(
					"%smat4x4((%s, %s, %s, %s), (%s, %s, %s, %s), (%s, %s, %s, %s), (%s, %s, %s, %s))",
					PrefixStr,
					LiteralStr, LiteralStr, LiteralStr, LiteralStr,
					LiteralStr, LiteralStr, LiteralStr, LiteralStr,
					LiteralStr, LiteralStr, LiteralStr, LiteralStr,
					LiteralStr, LiteralStr, LiteralStr, LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(x[0][0]),
									static_cast<typename cast<T>::value_type>(x[0][1]),
									static_cast<typename cast<T>::value_type>(x[0][2]),
									static_cast<typename cast<T>::value_type>(x[0][3]),
									static_cast<typename cast<T>::value_type>(x[1][0]),
									static_cast<typename cast<T>::value_type>(x[1][1]),
									static_cast<typename cast<T>::value_type>(x[1][2]),
									static_cast<typename cast<T>::value_type>(x[1][3]),
									static_cast<typename cast<T>::value_type>(x[2][0]),
									static_cast<typename cast<T>::value_type>(x[2][1]),
									static_cast<typename cast<T>::value_type>(x[2][2]),
									static_cast<typename cast<T>::value_type>(x[2][3]),
									static_cast<typename cast<T>::value_type>(x[3][0]),
									static_cast<typename cast<T>::value_type>(x[3][1]),
									static_cast<typename cast<T>::value_type>(x[3][2]),
									static_cast<typename cast<T>::value_type>(x[3][3]));
			}
		};


		template <typename T, qualifier Q>
		struct compute_to_string<qua<T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const qua<T, Q>& q)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format("%squat(%s, {%s, %s, %s})",
											PrefixStr,
											LiteralStr, LiteralStr, LiteralStr, LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(q.w),
									static_cast<typename cast<T>::value_type>(q.x),
									static_cast<typename cast<T>::value_type>(q.y),
									static_cast<typename cast<T>::value_type>(q.z));
			}
		};

		template <typename T, qualifier Q>
		struct compute_to_string<tdualquat<T, Q>>
		{
			GLM_FUNC_QUALIFIER static std::string call(const tdualquat<T, Q>& x)
			{
				const char* PrefixStr = prefix<T>::value();
				const char* LiteralStr = literal<T, std::numeric_limits<T>::is_iec559>::value();
				std::string FormatStr(format("%sdualquat((%s, {%s, %s, %s}), (%s, {%s, %s, %s}))",
											PrefixStr,
											LiteralStr, LiteralStr, LiteralStr, LiteralStr,
											LiteralStr, LiteralStr, LiteralStr, LiteralStr));

				return detail::format(FormatStr.c_str(),
									static_cast<typename cast<T>::value_type>(x.real.w),
									static_cast<typename cast<T>::value_type>(x.real.x),
									static_cast<typename cast<T>::value_type>(x.real.y),
									static_cast<typename cast<T>::value_type>(x.real.z),
									static_cast<typename cast<T>::value_type>(x.dual.w),
									static_cast<typename cast<T>::value_type>(x.dual.x),
									static_cast<typename cast<T>::value_type>(x.dual.y),
									static_cast<typename cast<T>::value_type>(x.dual.z));
			}
		};
	} //namespace detail

	template <class matType>
	GLM_FUNC_QUALIFIER std::string to_string(const matType& x)
	{
		return detail::compute_to_string<matType>::call(x);
	}
} //namespace glm

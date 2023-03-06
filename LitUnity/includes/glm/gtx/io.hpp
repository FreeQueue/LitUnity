/// @ref gtx_io
/// @file glm/gtx/io.hpp
/// @author Jan P Springer (regnirpsj@gmail.com)
///
/// @see core (dependence)
/// @see gtc_matrix_access (dependence)
/// @see gtc_quaternion (dependence)
///
/// @defgroup gtx_io GLM_GTX_io
/// @ingroup gtx
///
/// Include <glm/gtx/io.hpp> to use the features of this extension.
///
/// std::[w]ostream support for glm types
///
/// std::[w]ostream support for glm types + qualifier/width/etc. manipulators
/// based on howard hinnant's std::chrono io proposal
/// [http://home.roadrunner.com/~hinnant/bloomington/chrono_io.html]

#pragma once

// Dependency:
#include "../glm.hpp"
#include "../gtx/quaternion.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_io is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_io extension included")
#	endif
#endif

#include <iosfwd>  // std::basic_ostream<> (fwd)
#include <locale>  // std::locale, std::locale::facet, std::locale::id
#include <utility> // std::pair<>

namespace glm
{
	/// @addtogroup gtx_io
	/// @{

	namespace io
	{
		enum order_type { column_major, row_major };

		template <typename CTy>
		class format_punct : public std::locale::facet
		{
			using char_type = CTy;

		public:
			static std::locale::id id;

			bool formatted;
			unsigned precision;
			unsigned width;
			char_type separator;
			char_type delim_left;
			char_type delim_right;
			char_type space;
			char_type newline;
			order_type order;

			GLM_FUNC_DECL explicit format_punct(size_t a = 0);
			GLM_FUNC_DECL explicit format_punct(const format_punct&);
		};

		template <typename CTy, typename CTr = std::char_traits<CTy>>
		class basic_state_saver
		{
		public:
			GLM_FUNC_DECL explicit basic_state_saver(std::basic_ios<CTy, CTr>&);
			GLM_FUNC_DECL ~basic_state_saver();

		private:
			using state_type = std::basic_ios<CTy, CTr>;
			using char_type = typename state_type::char_type;
			using flags_type = std::ios_base::fmtflags;
			using streamsize_type = std::streamsize;
			using locale_type = const std::locale;

			state_type& state_;
			flags_type flags_;
			streamsize_type precision_;
			streamsize_type width_;
			char_type fill_;
			locale_type locale_;

			GLM_FUNC_DECL basic_state_saver& operator=(const basic_state_saver&);
		};

		using state_saver = basic_state_saver<char>;
		using wstate_saver = basic_state_saver<wchar_t>;

		template <typename CTy, typename CTr = std::char_traits<CTy>>
		class basic_format_saver
		{
		public:
			GLM_FUNC_DECL explicit basic_format_saver(std::basic_ios<CTy, CTr>&);
			GLM_FUNC_DECL ~basic_format_saver();

		private:
			const basic_state_saver<CTy> bss_;

			GLM_FUNC_DECL basic_format_saver& operator=(const basic_format_saver&);
		};

		using format_saver = basic_format_saver<char>;
		using wformat_saver = basic_format_saver<wchar_t>;

		struct precision
		{
			unsigned value;

			GLM_FUNC_DECL explicit precision(unsigned);
		};

		struct width
		{
			unsigned value;

			GLM_FUNC_DECL explicit width(unsigned);
		};

		template <typename CTy>
		struct delimeter
		{
			CTy value[3];

			GLM_FUNC_DECL explicit delimeter(CTy /* left */, CTy /* right */, CTy /* separator */  = ',');
		};

		struct order
		{
			order_type value;

			GLM_FUNC_DECL explicit order(order_type);
		};

		// functions, inlined (inline)

		template <typename FTy, typename CTy, typename CTr>
		const FTy& get_facet(std::basic_ios<CTy, CTr>&);
		template <typename FTy, typename CTy, typename CTr>
		std::basic_ios<CTy, CTr>& formatted(std::basic_ios<CTy, CTr>&);
		template <typename FTy, typename CTy, typename CTr>
		std::basic_ios<CTy, CTr>& unformattet(std::basic_ios<CTy, CTr>&);

		template <typename CTy, typename CTr>
		std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const precision&);
		template <typename CTy, typename CTr>
		std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const width&);
		template <typename CTy, typename CTr>
		std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const delimeter<CTy>&);
		template <typename CTy, typename CTr>
		std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const order&);
	} //namespace io

	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const qua<T, Q>&);
	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const vec<1, T, Q>&);
	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const vec<2, T, Q>&);
	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const vec<3, T, Q>&);
	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const vec<4, T, Q>&);
	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const mat<2, 2, T, Q>&);
	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const mat<2, 3, T, Q>&);
	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const mat<2, 4, T, Q>&);
	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const mat<3, 2, T, Q>&);
	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const mat<3, 3, T, Q>&);
	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const mat<3, 4, T, Q>&);
	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const mat<4, 2, T, Q>&);
	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const mat<4, 3, T, Q>&);
	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&, const mat<4, 4, T, Q>&);

	template <typename CTy, typename CTr, typename T, qualifier Q>
	GLM_FUNC_DECL std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>&,
															const std::pair<
																const mat<4, 4, T, Q>, const mat<4, 4, T, Q>>&);

	/// @}
} //namespace glm

#include "io.inl"

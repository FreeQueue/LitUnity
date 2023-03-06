/// @ref gtc_matrix_access

namespace glm
{
	template <typename genType>
	GLM_FUNC_QUALIFIER genType row
	(
		const genType& m,
		length_t index,
		const typename genType::row_type& x
	)
	{
		assert(index >= 0 && index < m[0].length());

		genType Result = m;
		for (length_t i = 0; i < m.length(); ++i)
			Result[i][index] = x[i];
		return Result;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER typename genType::row_type row
	(
		const genType& m,
		length_t index
	)
	{
		assert(index >= 0 && index < m[0].length());

		typename genType::row_type Result(0);
		for (length_t i = 0; i < m.length(); ++i)
			Result[i] = m[i][index];
		return Result;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER genType column
	(
		const genType& m,
		length_t index,
		const typename genType::col_type& x
	)
	{
		assert(index >= 0 && index < m.length());

		genType Result = m;
		Result[index] = x;
		return Result;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER typename genType::col_type column
	(
		const genType& m,
		length_t index
	)
	{
		assert(index >= 0 && index < m.length());

		return m[index];
	}
} //namespace glm

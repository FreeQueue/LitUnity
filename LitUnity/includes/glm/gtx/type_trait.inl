/// @ref gtx_type_trait

namespace glm
{
	template <typename T>
	const bool type<T>::is_vec;
	template <typename T>
	const bool type<T>::is_mat;
	template <typename T>
	const bool type<T>::is_quat;
	template <typename T>
	const length_t type<T>::components;
	template <typename T>
	const length_t type<T>::cols;
	template <typename T>
	const length_t type<T>::rows;

	// vec
	template <length_t L, typename T, qualifier Q>
	const bool type<vec<L, T, Q>>::is_vec;
	template <length_t L, typename T, qualifier Q>
	const bool type<vec<L, T, Q>>::is_mat;
	template <length_t L, typename T, qualifier Q>
	const bool type<vec<L, T, Q>>::is_quat;
	template <length_t L, typename T, qualifier Q>
	const length_t type<vec<L, T, Q>>::components;

	// mat
	template <length_t C, length_t R, typename T, qualifier Q>
	const bool type<mat<C, R, T, Q>>::is_vec;
	template <length_t C, length_t R, typename T, qualifier Q>
	const bool type<mat<C, R, T, Q>>::is_mat;
	template <length_t C, length_t R, typename T, qualifier Q>
	const bool type<mat<C, R, T, Q>>::is_quat;
	template <length_t C, length_t R, typename T, qualifier Q>
	const length_t type<mat<C, R, T, Q>>::components;
	template <length_t C, length_t R, typename T, qualifier Q>
	const length_t type<mat<C, R, T, Q>>::cols;
	template <length_t C, length_t R, typename T, qualifier Q>
	const length_t type<mat<C, R, T, Q>>::rows;

	// tquat
	template <typename T, qualifier Q>
	const bool type<qua<T, Q>>::is_vec;
	template <typename T, qualifier Q>
	const bool type<qua<T, Q>>::is_mat;
	template <typename T, qualifier Q>
	const bool type<qua<T, Q>>::is_quat;
	template <typename T, qualifier Q>
	const length_t type<qua<T, Q>>::components;

	// tdualquat
	template <typename T, qualifier Q>
	const bool type<tdualquat<T, Q>>::is_vec;
	template <typename T, qualifier Q>
	const bool type<tdualquat<T, Q>>::is_mat;
	template <typename T, qualifier Q>
	const bool type<tdualquat<T, Q>>::is_quat;
	template <typename T, qualifier Q>
	const length_t type<tdualquat<T, Q>>::components;
} //namespace glm

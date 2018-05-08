#pragma once
#ifndef FMT_EXT_META_RE_H_
#define FMT_EXT_META_RE_H_
//=================================================================================================
//  fmt_ext_meta.h
//  #include "fmt_ext_meta.h"
//  Created: 05.06.2018
//  Remotion (C) 2018 - All Rights Reserved
//=================================================================================================


#include "fmt_ext.h"
#include "preprocessor.h"


namespace fmt_ext {
namespace meta {

struct wildcard {
	template <typename T, typename = std::enable_if_t<!std::is_lvalue_reference<T>::value>>
	operator T && () const; // NOLINT

	template <typename T, typename = std::enable_if_t<std::is_copy_constructible<T>::value>>
	operator T&() const; // NOLINT
};
template <size_t N = 0>
static constexpr const wildcard any_t_{};



template <typename T, typename ... V>
constexpr auto is_brace_constructible_any_(T*) 
	-> decltype(T{ std::declval<V>()... }, std::true_type{}) { return {}; }

template <typename T, typename ... V>
constexpr std::false_type is_brace_constructible_any_(...) { return {}; }

template <typename T, typename ... V>
constexpr auto is_brace_constructible_any()
-> decltype(is_brace_constructible_any_<T, V...>(nullptr)) { return {}; }



template <typename T, size_t ... I>
constexpr auto
is_brace_constructible_(std::index_sequence<I...>, T *)
-> decltype(T{ any_t_<I>... }, std::true_type{}) { return {}; }

template <size_t ... I>
constexpr std::false_type
is_brace_constructible_(std::index_sequence<I...>, ...) { return {}; }


template <typename T, size_t N>
constexpr auto
is_brace_constructible()
-> decltype(is_brace_constructible_(std::make_index_sequence<N>{},
	static_cast<T *>(nullptr))) { return {}; }


template <typename T, typename U>
struct is_paren_constructible_;

template <typename T, size_t ... I>
struct is_paren_constructible_<T, std::index_sequence<I...>>
	: std::is_constructible<T, decltype(any_t_<I>)...>  {};

template <typename T, size_t N>
constexpr auto is_paren_constructible() 
	-> is_paren_constructible_<T, std::make_index_sequence<N>> { return {}; }



struct filler_ {
	template <typename T>
	operator T && ();
};

template<size_t I>
struct filler_i_ {
	template <typename T>
	operator T && ();
};

#ifdef __GNUC__
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif


template <typename Aggregate, typename index_sequence = std::index_sequence<>, typename = void>
struct aggregate_arity : index_sequence { };

#if 1 // Remo: 05.05.2018
template <typename Aggregate, std::size_t... Indices>
struct aggregate_arity < 
	Aggregate, 
	std::index_sequence<Indices...>,
	std::void_t<decltype(Aggregate{ (std::declval<filler_i_<Indices>>())..., std::declval<wildcard>() }) >>
	: aggregate_arity<Aggregate, std::index_sequence<Indices..., sizeof...(Indices)>> { };
#else
template <typename Aggregate, std::size_t... Indices>
struct aggregate_arity < Aggregate, std::index_sequence<Indices...>,
	std::void_t<decltype(Aggregate{ (Indices, std::declval<wildcard/*filler_*/>())..., std::declval<wildcard/*filler_*/>() }) >>
	: aggregate_arity<Aggregate, std::index_sequence<Indices..., sizeof...(Indices)>> { };
#endif

template <typename T>
constexpr auto arity() {
	return aggregate_arity< std::remove_cv_t< T > >::size(); 
}

template <typename T>
constexpr size_t arity_v = aggregate_arity< std::remove_cv_t< T > >::size();

#ifdef __GNUC__
# pragma GCC diagnostic pop
#endif

} // namespace meta

template <std::size_t Index>
using size_t_t = std::integral_constant<std::size_t, Index >;

template <class T>
struct type_tag {
	using type = T;
};
template <class...Ts>
struct types_tag {};

//=--------------------------------------------------------------------------------------------------------------------
template <class Aggregate, class T>
constexpr auto fwd(T&& val, type_tag<Aggregate>) {
	if constexpr (std::is_reference_v<Aggregate>) {
		return val;
	}
	else {
		return std::forward<T>(val);
	}
}

#define PP_ID(V)	V
#define PP_FWD(V)  fwd(V, tag)
#define ARGS_I(I, O) PP_ARGS_##I(O)

/// as_tuple  Makes a tuple of references on the given aggregate.
template <class Aggregate>
constexpr auto as_tuple_impl(Aggregate& aggregate, size_t_t<0>) noexcept {
	return std::forward_as_tuple();
}
/// to_tuple  Copies the given aggregate as a tuple.
template <class Aggregate>
constexpr auto to_tuple_impl(Aggregate&& aggregate, size_t_t<0>) noexcept {
	return std::make_tuple();
}



#define PP_TUPLE_IMPL(I)											\
template <class Agg>												\
constexpr auto as_tuple_impl(Agg& agg, size_t_t<I>) noexcept {		\
	auto&[ARGS_I(I, PP_ID)] = agg;									\
	return std::forward_as_tuple(ARGS_I(I, PP_ID));					\
}																	\
template <class Agg>												\
constexpr auto to_tuple_impl(Agg&& agg, size_t_t<I>) noexcept {		\
	constexpr auto tag = type_tag<Agg>{};							\
	auto&&[ARGS_I(I, PP_ID)] = agg;									\
	return std::make_tuple(ARGS_I(I,PP_FWD));						\
}


PP_TUPLE_IMPL(1)
PP_TUPLE_IMPL(2)
PP_TUPLE_IMPL(3)
PP_TUPLE_IMPL(4)
PP_TUPLE_IMPL(5)
PP_TUPLE_IMPL(6)
PP_TUPLE_IMPL(7)
PP_TUPLE_IMPL(8)
PP_TUPLE_IMPL(9)
PP_TUPLE_IMPL(10)
PP_TUPLE_IMPL(11)
PP_TUPLE_IMPL(12)
PP_TUPLE_IMPL(13)
PP_TUPLE_IMPL(14)
PP_TUPLE_IMPL(15)
PP_TUPLE_IMPL(16)
PP_TUPLE_IMPL(17)
PP_TUPLE_IMPL(18)
PP_TUPLE_IMPL(19)
PP_TUPLE_IMPL(20)
PP_TUPLE_IMPL(21)
PP_TUPLE_IMPL(22)
PP_TUPLE_IMPL(23)
PP_TUPLE_IMPL(24)
PP_TUPLE_IMPL(25)
PP_TUPLE_IMPL(26)
PP_TUPLE_IMPL(27)
PP_TUPLE_IMPL(28)
PP_TUPLE_IMPL(29)
PP_TUPLE_IMPL(30)
PP_TUPLE_IMPL(31)
PP_TUPLE_IMPL(32)
PP_TUPLE_IMPL(33)
PP_TUPLE_IMPL(34)
PP_TUPLE_IMPL(35)
PP_TUPLE_IMPL(36)
PP_TUPLE_IMPL(37)
PP_TUPLE_IMPL(38)
PP_TUPLE_IMPL(39)
PP_TUPLE_IMPL(40)
PP_TUPLE_IMPL(41)
PP_TUPLE_IMPL(42)
PP_TUPLE_IMPL(43)
PP_TUPLE_IMPL(44)
PP_TUPLE_IMPL(45)
PP_TUPLE_IMPL(46)
PP_TUPLE_IMPL(47)
PP_TUPLE_IMPL(48)
PP_TUPLE_IMPL(49)
PP_TUPLE_IMPL(50)
PP_TUPLE_IMPL(51)
PP_TUPLE_IMPL(52)
PP_TUPLE_IMPL(53)
PP_TUPLE_IMPL(54)
PP_TUPLE_IMPL(55)
PP_TUPLE_IMPL(56)
PP_TUPLE_IMPL(57)
PP_TUPLE_IMPL(58)
PP_TUPLE_IMPL(59)
PP_TUPLE_IMPL(60)
PP_TUPLE_IMPL(61)
PP_TUPLE_IMPL(62)
PP_TUPLE_IMPL(63)
PP_TUPLE_IMPL(64)
PP_TUPLE_IMPL(65)
PP_TUPLE_IMPL(66)
PP_TUPLE_IMPL(67)
PP_TUPLE_IMPL(68)
PP_TUPLE_IMPL(69)
PP_TUPLE_IMPL(70)
PP_TUPLE_IMPL(71)
PP_TUPLE_IMPL(72)
PP_TUPLE_IMPL(73)
PP_TUPLE_IMPL(74)
PP_TUPLE_IMPL(75)
PP_TUPLE_IMPL(76)
PP_TUPLE_IMPL(77)
PP_TUPLE_IMPL(78)
PP_TUPLE_IMPL(79)
PP_TUPLE_IMPL(80)
PP_TUPLE_IMPL(81)
PP_TUPLE_IMPL(82)
PP_TUPLE_IMPL(83)
PP_TUPLE_IMPL(84)
PP_TUPLE_IMPL(85)
PP_TUPLE_IMPL(86)
PP_TUPLE_IMPL(87)
PP_TUPLE_IMPL(88)
PP_TUPLE_IMPL(89)
PP_TUPLE_IMPL(90)
PP_TUPLE_IMPL(91)
PP_TUPLE_IMPL(92)
PP_TUPLE_IMPL(93)
PP_TUPLE_IMPL(94)


#undef PP_TUPLE_IMPL


/// to_tuple
template <class Aggregate>
constexpr auto as_tuple(Aggregate& aggregate) noexcept {
	return as_tuple_impl(aggregate, size_t_t< meta::arity<Aggregate>()>{});
}

/// to_tuple
template <class Aggregate>
constexpr auto to_tuple(Aggregate& aggregate) noexcept {
	return to_tuple_impl(std::forward<Aggregate>(aggregate), size_t_t< meta::arity<Aggregate>()>{});
}


} // namespace fmt_ext


namespace fmt {

template<typename T>
constexpr bool is_struct_v = std::is_standard_layout_v<T>; // TODO(Remo 06.05.18):  proper detection !

// =====================================================================================================================
template<typename StructT, typename Char>
struct formatter< StructT, Char
	, std::enable_if_t< !fmt_ext::meta::is_tuple_like_v<StructT> && is_struct_v<StructT> >
>
{
	fmt_ext::formatting_tuple<Char> formating;

	template <typename ParseContext>
	FMT_CONSTEXPR auto parse(ParseContext &ctx) -> decltype(ctx.begin()) {
		return formating.parse(ctx);
	}

	template <typename FormatContext = format_context>
	auto format(const StructT &values, FormatContext &ctx) -> decltype(ctx.out()) {
		auto out = ctx.out();
		const auto tuple = fmt_ext::as_tuple(values);
		std::ptrdiff_t i = 0;
		fmt_ext::copy(formating.prefix, out);
		fmt_ext::meta::for_each(tuple, [&](const auto &v) {
			if (i++ > 0) { fmt_ext::copy(formating.delimiter, out); }
			if (formating.add_spaces) { format_to(out, " {}", v); }
			else { format_to(out, "{}", v); }
		});
		if (formating.add_spaces) { *out++ = ' '; }
		fmt_ext::copy(formating.postfix, out);

		return ctx.out();
	}
};

} // namespace fmt

#endif // FMT_EXT_META_RE_H_
#pragma once
#ifndef FMT_EXT_RE_H_
#define FMT_EXT_RE_H_
// =================================================================================================
//  fmt_ext.h
//  #include "fmt_ext.h"
//  Created: 04.8.2018
//  
//  BSD 2-Clause License
//  Remotion (C) 2018 - All Rights Reserved
//  {fmt} support for ranges, containers and types tuple interface.
// =================================================================================================

#include <type_traits>

#ifndef FMT_RANGE_OUTPUT_LENGTH_LIMIT
#define FMT_RANGE_OUTPUT_LENGTH_LIMIT 256
#endif

namespace fmt_ext {
namespace meta {

/// Return true value if T has std::string interface, like std::string_view.
template<typename T>
class is_like_std_string {
	template<typename U> static auto check(U* p) -> decltype(
		  p->find('a')
		, p->length()
		, p->data()
		, int());
	template<typename  > static void check(...);
public:
	static const bool value = !std::is_void< decltype(check<T>(nullptr)) >::value;
};

template<typename T>
constexpr bool is_like_std_string_v = is_like_std_string<T>::value;

template<typename... Ts>
struct conditional_helper {};

template<typename T, typename _ = void>
struct is_range_ : std::false_type {};

template<typename T>
struct is_range_<T,
	std::conditional_t< false,
	conditional_helper<
	decltype(std::declval<T>().begin()),
	decltype(std::declval<T>().end())
	>, void>
> : std::true_type{};

template<typename T>
constexpr bool is_range_v = is_range_<T>::value && !is_like_std_string<T>::value;


/// tuple_size and tuple_element check.
template<typename T>
class is_tuple_like_ {
	template<typename U> static auto check(U* p) -> decltype(
		std::tuple_size< U >::value, 
		typename std::tuple_element<0, U>::type(),
		int());
	template<typename  > static void check(...);
public:
	static constexpr bool value = !std::is_void_v< decltype(check<T>(nullptr)) >;
};

template<typename T>
constexpr bool is_tuple_like_v = is_tuple_like_<T>::value && !is_range_<T>::value;


//=--------------------------------------------------------------------------------------------------------------------
template<size_t... Is, class Tuple, class F>
void for_each(std::index_sequence<Is...>, Tuple&& tup, F&& f) noexcept {
	using std::get;
	// using free function get<I>(T) now.
	const int _[] = { 0,
		((void)f(get<Is>(tup)),
		0)... };
	(void)_; // blocks warnings
}
//=--------------------------------------------------------------------------------------------------------------------
template<class T>
constexpr std::make_index_sequence<std::tuple_size<T>::value>
get_indexes(T const&) {	return {}; }

//=--------------------------------------------------------------------------------------------------------------------
template<class Tuple, class F>
void for_each(Tuple&& tup, F&& f) {
	const auto indexes = get_indexes(tup);
	for_each(indexes, std::forward<Tuple>(tup), std::forward<F>(f));
}

} // namespace meta
} // namespace fmt_ext

namespace fmt {

// =====================================================================================================================
template<typename StructuredBindingsT>
struct formatter< StructuredBindingsT, char
	, std::enable_if_t<fmt_ext::meta::is_tuple_like_v<StructuredBindingsT>> >
{
	template <typename ParseContext>
	FMT_CONSTEXPR static auto parse(ParseContext &ctx) -> decltype(ctx.begin()) { return ctx.begin(); }

	template <typename FormatContext = format_context>
	auto format(const StructuredBindingsT &values, FormatContext &ctx) -> decltype(ctx.out()) {
		auto out = ctx.out();
		*out++ = '[';
		std::ptrdiff_t i = 0;
		fmt_ext::meta::for_each(values, [&](const auto &v) {
			if (i++ > 0) { *out++ = ','; }
			format_to(out, " {}", v);
		});
		*out++ = ' ';
		*out++ = ']';

		return ctx.out();
	}
};

} // namespace fmt



namespace fmt {


template<typename ContainerT, typename Char>
struct formatter <ContainerT, Char, std::enable_if_t<fmt_ext::meta::is_range_v<ContainerT>> > 
{
	static constexpr std::ptrdiff_t range_length_limit = FMT_RANGE_OUTPUT_LENGTH_LIMIT; // show only up to N items from the range.

	template <typename ParseContext>
	static FMT_CONSTEXPR auto parse(ParseContext &ctx) -> decltype(ctx.begin()) {
		return ctx.begin();
	}

	template <typename FormatContext>
	auto format(const ContainerT &values, FormatContext &ctx) -> decltype(ctx.out()) {
		auto out = ctx.out();
		*out++ = '{';
		std::ptrdiff_t i = 0;
		for (const auto& it : values) {
			if (i > 0) { *out++ = ','; }
			format_to(out, " {}", it);
			if (++i > range_length_limit) {
				format_to(out, " ... <other elements>");
				break;
			}
		}
		*out++ = ' '; 
		*out++ = '}';
		return ctx.out();
	}
};

} // namespace fmt

#endif // FMT_EXT_RE_H_

#include <vector>
#include <array>
#include <map>

#include <gsl/gsl>

#define FMT_HEADER_ONLY
#include <fmt/format.h>
static_assert(FMT_VERSION >= 50000,"Only {fmt} 5.0 or higher is supported.");

#include "fmt_ext.h"


static_assert( fmt_ext::meta::is_range_v<std::vector<int32_t>>);
static_assert( fmt_ext::meta::is_range_v<std::array<int32_t,7>>);

static_assert( fmt_ext::meta::is_tuple_like_v<std::tuple<int32_t,float,std::string>>);

#if 1 /// Configurable formatting. 

namespace fmt_ext {

template <typename Char>
struct formatting_range<Char, void> : formatting_base<Char> {
    const Char *prefix		= "{"; // use c strings for delimiters.
    Char delimiter			= ','; // use single char for delimiters.
    std::string postfix		= "}"; // use std::string for delimiters.
    bool add_spaces = true;
};

template <typename Char>
struct formatting_tuple<Char, void> : formatting_base<Char> {
    Char prefix		= '[';
    Char delimiter	= ',';
    Char postfix    = ']';
    bool add_spaces = true;
};

} // namespace fmt_ext

#endif


struct my_struct {
  int32_t i;
  std::string str; // can throw 

  template <std::size_t N>
  decltype(auto) get() const noexcept {
      if      constexpr (N == 0) return i;
      else if constexpr (N == 1) return std::string_view{ str };
  }
};


template <std::size_t N>
decltype(auto) get(const my_struct& s) noexcept { return s.get<N>(); }

namespace std {

template<>
struct tuple_size<my_struct> : std::integral_constant<std::size_t, 2> {};

template<std::size_t N>
struct tuple_element<N, my_struct> {
    using type = decltype(std::declval<my_struct>().get<N>());
};

} // namespace std

static_assert( fmt_ext::meta::is_tuple_like_v<my_struct>);



int main() {
    fmt::print_colored(fmt::green, " {{fmt}} {} \n",FMT_VERSION);

    std::vector<int32_t> iv{1,2,3,5,7,11};
    auto ivf = fmt::format("{}", iv);
    fmt::print(" vector {} = {} \n", iv, ivf);

    std::vector<std::vector<int32_t>> ivv{ {1,2},{3,5},{7,11} };
    fmt::print(" vector {} \n", ivv);


    std::vector<std::tuple<int32_t, int32_t>> ivt{ {1,2},{3,5},{7,11} };
    fmt::print(" vector {} \n", ivt);

    std::map<std::string, int32_t>  simap{ {"one",1}, {"two",2} };
    fmt::print(" map<std::string, int32_t> {} \n", simap);

    std::pair<int64_t, float> pa1{42, 3.14159265358979f};
    fmt::print(" pair {} \n", pa1);

    std::tuple<int64_t, float, std::string> tu1{42, 3.14159265358979f, "this is tuple"};
    fmt::print(" tuple {} \n", tu1);

    fmt::print(" make_tuple {} \n", std::make_tuple(1, 2, 3));
    fmt::print(" make_tuple {} \n", std::make_tuple(1, std::string("str"), 3));

    my_struct mst{13,"my struct"};
    fmt::print(" my_struct {} \n", mst);

    std::string sarr[] = { "1","2" };
    gsl::span<std::string> sp{sarr};

    fmt::print(" span {} \n", sp);

    return 0;
}
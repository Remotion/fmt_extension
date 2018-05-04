
#include <vector>
#include <array>
#include <map>

#include <gsl/gsl>

#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include "fmt_ext.h"

static_assert( fmt_ext::meta::is_range_v<std::vector<int>>);
static_assert( fmt_ext::meta::is_range_v<std::array<int,7>>);

static_assert( fmt_ext::meta::is_tuple_like_v<std::tuple<int,float,std::string>>);

struct my_struct {
  int i;
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

    std::vector<int32_t> iv{1,2,3,5,7,11};
    auto ivf = fmt::format("{}", iv);
    assert(ivf == "{ 1, 2, 3, 5, 7, 11 }");
    fmt::print(" vector {} \n", iv);

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
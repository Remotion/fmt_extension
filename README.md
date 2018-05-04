# [{fmt}](https://github.com/fmtlib/fmt) extension

[{fmt}](https://github.com/fmtlib/fmt) 5.0 support for ranges, containers and types with tuple interface.

This header allow to directly format ranges, containers, spans and all the types with get, std::tuple_size, std::tuple_element interface.

**Example:**

```cpp
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

std::string sarr[] = { "1","2" };
gsl::span<std::string> sp{sarr};

fmt::print(" span {} \n", sp);
```

**output:**

```cmd
 vector { 1, 2, 3, 5, 7, 11 }
 pair [ 42, 3.14159 ]
 tuple [ 42, 3.14159, this is tuple ]
 make_tuple [ 1, 2, 3 ]
 make_tuple [ 1, str, 3 ]
 my_struct [ 13, my struct ]
 span { 1, 2 }
```

Ranges output is limited by FMT_RANGE_OUTPUT_LENGTH_LIMIT macro. This way infinite ranges are supported too.

Tested with Visual Studio 2017, GCC 7.3.0, Clang 6.0 in C++17 mode.

## Possible improvements

* add full structured binding support.
* make it work with C+14.
* add [meson](https://github.com/mesonbuild/meson), [premake](https://github.com/premake/premake-core), [cmake](https://cmake.org/) build support.
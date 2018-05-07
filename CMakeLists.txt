message(STATUS "CMake version: ${CMAKE_VERSION}")
cmake_minimum_required(VERSION 3.11)

project(fmt_extension)


include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY "https://github.com/catchorg/Catch2"
  GIT_TAG        "v2.2.2"
)

FetchContent_GetProperties(Catch2) 
if(NOT Catch2_POPULATED)
  FetchContent_Populate(Catch2)
  # message(STATUS "Catch source dir: ${catch2_SOURCE_DIR}")
  # message(STATUS "Catch binary dir: ${catch2_BINARY_DIR}")
  add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
endif()

FetchContent_Declare(
  fmt5
  GIT_REPOSITORY "https://github.com/Remotion/fmt"
  GIT_TAG        "5.0.0a"
)

FetchContent_GetProperties(fmt5) 
if(NOT Catch2_POPULATED)
  FetchContent_Populate(fmt5)
  # message(STATUS "fmt source dir: ${fmt5_SOURCE_DIR}")
  # message(STATUS "fmt binary dir: ${fmt5_BINARY_DIR}")
  add_subdirectory(${fmt5_SOURCE_DIR} ${fmt5_BINARY_DIR})
endif()


add_executable(fmt_extension
  fmt_ext_test.cpp
)

set_property(TARGET fmt_extension PROPERTY CXX_STANDARD 17)
set_property(TARGET fmt_extension PROPERTY CXX_STANDARD_REQUIRED ON)

if (MSVC)
    target_compile_options( fmt_extension PRIVATE "/W4" )
endif()

if (CMAKE_COMPILER_IS_GNUCXX OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
  target_compile_options(fmt_extension "-pipe -Wall -Wextra -Wshadow")
endif ()


target_link_libraries(fmt_extension Catch fmt)
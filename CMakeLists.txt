cmake_minimum_required(VERSION 3.11)

project(fmt_extension)

include(FetchContent)

####################################################################################################
# Catch2
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY "https://github.com/catchorg/Catch2"
  GIT_TAG        "v2.2.2"
)

FetchContent_GetProperties(Catch2) 
if(NOT Catch2_POPULATED)
  FetchContent_Populate(Catch2)
  message(STATUS "Catch2 source dir: ${catch2_SOURCE_DIR}")
  add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
endif()

####################################################################################################
# {fmt}
FetchContent_Declare(
  fmt5
  GIT_REPOSITORY "https://github.com/fmtlib/fmt"
  GIT_TAG        "7d3de4971500e50f32e212b8956b3cde1f2620b3"
)

FetchContent_GetProperties(fmt5) 
if(NOT fmt5_POPULATED)
  FetchContent_Populate(fmt5)
  message(STATUS "{fmt} source dir: ${fmt5_SOURCE_DIR}")
  add_subdirectory(${fmt5_SOURCE_DIR} ${fmt5_BINARY_DIR})
endif()

####################################################################################################
# gsl
FetchContent_Declare(
  gsl
  GIT_REPOSITORY "https://github.com/Microsoft/GSL"
  GIT_TAG "5cbde3008aa43a9c5f6c219ee15b8388336d4433"
)

FetchContent_GetProperties(gsl) 
if(NOT gsl_POPULATED)
  FetchContent_Populate(gsl)
  message(STATUS "gsl source dir: ${gsl_SOURCE_DIR}")
  # message(STATUS "gsl binary dir: ${gsl_BINARY_DIR}")
  add_subdirectory(${gsl_SOURCE_DIR} ${gsl_BINARY_DIR})
endif()

####################################################################################################
add_executable(fmt_extension
  fmt_ext_test.cpp
)
target_include_directories(fmt_extension PUBLIC ./include)

target_link_libraries(fmt_extension Catch fmt GSL)

####################################################################################################
set_property(TARGET fmt_extension PROPERTY CXX_STANDARD 17)
set_property(TARGET fmt_extension PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET fmt_extension PROPERTY CXX_EXTENSIONS OFF)

if (CMAKE_COMPILER_IS_GNUCXX OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
  target_compile_options(fmt_extension PRIVATE -pipe -Wall -Wextra -Wshadow)
  
elseif(MSVC)
  target_compile_options(fmt_extension PRIVATE /W4 /MP /permissive- /Zc:__cplusplus /GR- )
  set_target_properties(fmt_extension PROPERTIES LINK_FLAGS "/DEBUG:FASTLINK")
  
endif ()




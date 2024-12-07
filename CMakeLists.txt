cmake_minimum_required (VERSION 3.23)
project ("test"  VERSION 0.0.1 LANGUAGES CXX)

if(MSVC)
  add_compile_options(/W4 /WX /permissive-)
else()
  add_compile_options(-Werror -Wall -Wextra -pedantic-errors)
endif(MSVC)

add_executable (test "main.cpp")

target_compile_features(test PRIVATE cxx_std_23)
target_include_directories(test PRIVATE "./include")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
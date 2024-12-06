cmake_minimum_required (VERSION 3.23)
project ("test")

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

if(MSVC)
  add_compile_options(/W4 /WX /permissive- /Od)
else()
  add_compile_options(-Werror -Wall -Wextra -pedantic-errors)
endif(MSVC)

add_executable (test "main.cpp" "include/utils.h")

target_include_directories(test PRIVATE "./include")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_compile_features(test PRIVATE cxx_std_20)

cmake_minimum_required(VERSION 3.2)
set(EXECUTABLE_OUTPUT_PATH "../bin")



project(MyApp)

add_executable(calc calc_bugg08_2.cpp)
add_library(calculate "calculate.cpp")
add_library("grammar.h" "grammar.cpp")
add_library("token_tokenstream.h" "token_tokenstream.cpp")
add_library("variable.h" "variable.cpp")

include_directories("/home/iven/Documents/mipt/cpp_semi/lib")
include_directories("./")
#enable_testing()
#add_test(test1 "../tests/tests.sh")

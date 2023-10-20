cmake_minimum_required(VERSION 3.2)
set(EXECUTABLE_OUTPUT_PATH "../bin")



project(MyApp)

add_executable(calc calc_bugg08_2.cpp)
add_library(calculate "calculate.h" "calculate.cpp")
add_library(grammar "grammar.h" "grammar.cpp")
add_library(token_tokenstream "token_tokenstream.h" "token_tokenstream.cpp")
add_library(variable "variable.h" "variable.cpp")

include_directories("/home/iven/Documents/mipt/cpp_semi/lib")
include_directories("./")

#target_link_libraries(grammar token_tokenstream)
target_link_libraries(variable token_tokenstream grammar)
target_link_libraries(calc calculate grammar token_tokenstream variable)



#enable_testing()
#add_test(test1 "../tests/tests.sh")

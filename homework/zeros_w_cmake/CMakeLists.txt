cmake_minimum_required(VERSION 3.2)
set(EXECUTABLE_OUTPUT_PATH "../bin")



project(MyApp)

add_executable(zeroes.exe zeros.cpp)
enable_testing()
add_test(test1 "../tests/tests.sh")

cmake_minimum_required(VERSION 3.0.0)
project(ENUM VERSION 0.1.0)
add_compile_options(-std=c++11)
include(CTest)
enable_testing()

add_executable(ENUM main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

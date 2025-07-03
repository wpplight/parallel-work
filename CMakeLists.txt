# c++ 20 需要更高版本
cmake_minimum_required(VERSION 3.12)

# 设置项目名称和使用的语言
project(MyProject LANGUAGES CXX)

# 设置 C++ 标准为 C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#  添加编译器警告标志
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# 可执行目标
add_executable(main main.cpp)


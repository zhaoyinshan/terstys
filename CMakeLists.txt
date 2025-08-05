cmake_minimum_required(VERSION 3.10)
project(use_terstys C CXX)

set(CMAKE_PREFIX_PATH "$ENV{HOME}/.local")

add_subdirectory(terstys)

add_executable(c-example main.c)
add_executable(cpp-example main.cpp)

# 链接静态库或动态库
target_link_libraries(c-example PRIVATE terstys_shared)
# 或者
target_link_libraries(cpp-example PRIVATE terstys_shared)


# if you install terstys to your system, you can use it directly
# find_package(terstys REQUIRED)

# add_executable(c-example main.c)
# add_executable(cpp-example main.cpp)

# target_link_libraries(c-example PRIVATE terstys::terstys_shared)
# target_link_libraries(cpp-example PRIVATE terstys::terstys_shared)
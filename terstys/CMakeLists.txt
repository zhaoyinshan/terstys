# terstys/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(terstys_lib C CXX)

# 设置构建输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 头文件也复制一份到 build/include（可选）
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/include)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/terstys.h ${CMAKE_BINARY_DIR}/include/terstys.h COPYONLY)


# 创建库（静态库）
add_library(terstys_static STATIC
    terstys.c
)
set_target_properties(terstys_static PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
    PUBLIC_HEADER terstys.h
    OUTPUT_NAME terstys
)

# 创建库（动态库）
add_library(terstys_shared SHARED
    terstys.c
)
set_target_properties(terstys_shared PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
    PUBLIC_HEADER terstys.h
    OUTPUT_NAME terstys
)

# 头文件路径（供 install 和其他模块使用）
target_include_directories(terstys_shared PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)
target_include_directories(terstys_static PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# 安装
install(TARGETS terstys_shared terstys_static
    EXPORT terstysTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include
)

# 导出 cmake 配置（让别人 find_package ）
install(EXPORT terstysTargets
    FILE terstysTargets.cmake
    NAMESPACE terstys::
    DESTINATION lib/cmake/terstys
)

# 生成 terstysConfig.cmake
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/terstysConfigVersion.cmake"
    VERSION 1.0
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/terstysConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/terstysConfigVersion.cmake"
    DESTINATION lib/cmake/terstys
)

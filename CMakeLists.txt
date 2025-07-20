cmake_minimum_required(VERSION 3.20)

project(folly_template
    VERSION 1.0.0
    DESCRIPTION "A template project using Facebook Folly library"
    LANGUAGES CXX
)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 查找 vcpkg 包
find_package(Folly CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)

# 创建可执行文件
add_executable(${PROJECT_NAME}
    src/main.cpp
)

# 链接库
target_link_libraries(${PROJECT_NAME} PRIVATE
    Folly::folly
)

# 设置包含目录
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 设置输出目录
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

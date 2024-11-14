cmake_minimum_required(VERSION 3.29.8)
project(fnata)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(ExternalProject)
set(THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/third_party)

ExternalProject_Add(
    CLI11
    PREFIX ${THIRD_PARTY_DIR}
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.4.2
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    CMAKE_ARGS -DCLI11_BUILD_TESTS=OFF
    -DCLI11_SANITIZERS=OFF
    -DCLI11_BUILD_DOCS=OFF
    -DCLI11_BUILD_TESTS=OFF
    -DCLI11_BUILD_EXAMPLES=OFF
    -DCLI11_BUILD_EXAMPLES_JSON=OFF
    -DCLI11_SINGLE_FILE_TESTS=OFF
    -DCLI11_INSTALL=OFF
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(CLI11 source_dir)
add_executable(fnata src/main.cpp)
add_dependencies(fnata CLI11)

target_include_directories(fnata PRIVATE ${source_dir}/include)

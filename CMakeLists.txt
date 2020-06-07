# Copyright(c) 2019 spdlog authors Distributed under the MIT License (http://opensource.org/licenses/MIT)

cmake_minimum_required(VERSION 3.2)
project(spdlog_examples CXX)

##to find Findspdlog.cmake
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(CMAKE_VERBOSE_MAKEFILE ON)

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()
###need  spdlogConfig.cmake spdlog-config.cmake
#find_package(spdlog CONFIG REQUIRED)



# ---------------------------------------------------------------------------------------
# Example of using pre-compiled library
# ---------------------------------------------------------------------------------------

link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/../../thirdparty/spdlog/build
)
message(STATUS "libspdlog.a:  ${CMAKE_CURRENT_SOURCE_DIR}/../../thirdparty/spdlog/build/")

include_directories(
        ${spdlog_INCLUDE_DIR}
)

## first linkdir and incdir ,then exe could use them
add_executable(example example.cpp)

target_link_libraries(example PRIVATE spdlog pthread)



# ---------------------------------------------------------------------------------------
# Example of using header-only library
# ---------------------------------------------------------------------------------------
if(SPDLOG_BUILD_EXAMPLE_HO)
    add_executable(example_header_only example.cpp)
    target_link_libraries(example_header_only PRIVATE spdlog::spdlog_header_only)
endif()

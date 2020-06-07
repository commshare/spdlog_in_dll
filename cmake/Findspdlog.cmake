# ---------------------------------------------------------------------------------------
# SPDLOG
#
# References: https://gitlab.openbrain.sk/salsa-legacy/SALSA/-/blob/edc03fa203fe6169b204f741fe2bc9599d32eb06/cmake/modules/Findspdlog.cmake
# ---------------------------------------------------------------------------------------
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")


if(NOT EXISTS "${spdlog_INCLUDE_DIR}")
    find_path(spdlog_INCLUDE_DIR
        NAMES spdlog/spdlog.h
        PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../thirdparty/spdlog/include
        DOC "spdlog library header files")
endif()

if(EXISTS "${spdlog_INCLUDE_DIR}")
    message(STATUS "Found headers: spdlog")
    list(APPEND VENDOR_HEADERS ${spdlog_INCLUDE_DIR})
    include(FindPackageHandleStandardArgs)
    mark_as_advanced(spdlog_INCLUDE_DIR)
else()
    message(STATUS "The spdlog package not found, will be obtained from Github")
    include(ExternalProject)
    ExternalProject_Add(spdlog
        PREFIX external
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.6.0
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        UPDATE_COMMAND "")

    ExternalProject_Get_Property(spdlog source_dir)
    set(spdlog_INCLUDE_DIR "${source_dir}/include")
    list(APPEND VENDOR_HEADERS ${spdlog_INCLUDE_DIR})
    list(APPEND VENDOR_DEPENDENCIES spdlog)
    set(NEED_ADD_DEPS ON)
endif()

if(EXISTS "${spdlog_INCLUDE_DIR}")
    set(spdlog_FOUND 1)
else()
    set(spdlog_FOUND 0)
endif()

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../thirdparty/spdlog)

#add_library(thirdparty::spdlog ALIAS spdlog)
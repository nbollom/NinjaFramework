cmake_minimum_required(VERSION 3.8)
project(ninjaframework)

option(BUILD_LOG "Build the log project" ON)
option(BUILD_JSON "Build the json project" ON)
option(BUILD_PACK "Build the pack file handler project" ON)
option(BUILD_FILE "Build the file loader project" ON)
option(BUILD_ALL_TESTS "Build all the tests" OFF)

configure_file(ninjaframework.h.in ninjaframework.h)

enable_testing()

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_SOURCE_DIR}/../)

if(BUILD_LOG)
    add_subdirectory(ninjalog)
endif()
if(BUILD_JSON)
    add_subdirectory(ninjajson)
endif()
if(BUILD_PACK)
    add_subdirectory(ninjapack)
endif()
if(BUILD_FILE)
    add_subdirectory(ninjafile)
endif()

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/ninjaframework.h DESTINATION include/ninjaframework)

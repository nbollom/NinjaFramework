cmake_minimum_required(VERSION 3.8)
project(ninjalog)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        log.h
        )

set(SOURCE_FILES
        log.cpp
        )

add_library(ninjalog SHARED ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(ninjalog PROPERTIES
        VERSION 1.0
        SOVERSION 1)

option(LOG_BUILD_TESTS "Build and run the tests for the JSON library" OFF)

if(LOG_BUILD_TESTS OR BUILD_ALL_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

install(FILES ${HEADER_FILES} DESTINATION include/ninjaframework/ninjalog)
install(TARGETS ninjalog
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

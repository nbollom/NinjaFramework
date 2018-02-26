cmake_minimum_required(VERSION 3.8)
project(ninja2d)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        2d.h
        image.h
        )

set(SOURCE_FILES
        2d.cpp
        image.cpp
        glimage.h
        glimage.cpp
        )

find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
find_package(GLEW REQUIRED)
find_package(DevIL REQUIRED)

add_library(ninja2d SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(ninja2d PUBLIC ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} ${IL_INCLUDE_DIR})
target_link_libraries(ninja2d ${OPENGL_gl_LIBRARY} ${GLEW_LIBRARIES} glm ${IL_LIBRARIES} ${ILU_LIBRARIES})
set_target_properties(ninja2d PROPERTIES
        VERSION 1.0
        SOVERSION 1)

option(2D_BUILD_TESTS "Build and run the tests for the file loader library" OFF)

if(2D_BUILD_TESTS OR BUILD_MANUAL_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

install(FILES ${HEADER_FILES} DESTINATION include/ninjaframework/ninja2d)
install(TARGETS ninja2d
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

cmake_minimum_required(VERSION 3.28)

project(http-server)

set(TARGET_NAME "http-server")

set(LIBHV_INCLUDE ${PROJECT_BINARY_DIR}/_contrib/libhv/include/hv)

add_subdirectory(${PROJECT_SOURCE_DIR}/_contrib)

file(GLOB_RECURSE SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h )

include_directories(${LIBHV_INCLUDE})

add_executable(${TARGET_NAME} ${SOURCES}
        src/Server.hpp
        src/Server.cpp
        src/Router.hpp
        src/Router.cpp
        src/Storage.hpp
        src/User.hpp
        src/User.cpp
        src/Storage.cpp)
target_link_libraries(${TARGET_NAME} hv_static)

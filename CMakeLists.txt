cmake_minimum_required(VERSION 3.28)

project(http-server)

set(TARGET_NAME "http-server")

set(LIBHV_INCLUDE ${PROJECT_BINARY_DIR}/_contrib/libhv/include/hv)

set(TEST_FILES
        tests/test.cpp
        tests/requests/request.cpp
        src/auth/base64.cpp
        )

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
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

add_executable(AllTests ${TEST_FILES})
target_link_libraries(AllTests ${GTEST_LIBRARIES} ${HV_LIBRARIES} pthread)

enable_testing()
add_test(NAME AllTests COMMAND AllTests)
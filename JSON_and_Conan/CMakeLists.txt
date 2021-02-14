cmake_minimum_required(VERSION 2.8.12)
project(Project)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
    cmake_minimum_required(VERSION 2.8.12)
    project(Project)

    add_definitions("-std=c++11")

    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()

    add_executable(try_json try_json.cpp)
    target_link_libraries(try_json ${CONAN_LIBS})
else()
    SET(CMAKE_CXX_STANDARD 11)
    SET(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(try_json try_json.cpp)
target_link_libraries(try_json ${CONAN_LIBS})

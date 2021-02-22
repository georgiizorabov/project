cmake_minimum_required(VERSION 2.8.12)
project(dear-imgui-conan)
set(CMAKE_CXX_STANDARD 17)

#include_directories(~/.conan/data/imgui/1.80/_/_/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/include/)
#include_directories(~/.conan/data/glfw/3.3.2/_/_/package/751cb22e3ee3d822a8b7af83813b032dc3867205/include/)
#include_directories(~/.conan/data/nlohmann_json/3.9.1/_/_/package/d1091b2ed420e6d287293709a907ae824d5de508/include/)
#include_directories(~/project/try_imgui/)
#include_directories(~/.conan/data/cpr/1.5.0/_/_/package/c8ea4d03c1757db53fac4466c802c68e695f1aaa/include/)
#include_directories(~/.conan/data/libcurl/7.69.1/_/_/package/539b44da7a736f055c2112b92bba7f29d6d3c644/include/)

include(build/conanbuildinfo_multi.cmake)
#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(dear-imgui-conan
        main.cpp
        try_json.h
        server.h
        bindings/imgui_impl_glfw.cpp
        bindings/imgui_impl_opengl2.cpp
        bindings/imgui_impl_glfw.h
        bindings/imgui_impl_opengl2.h
        )

conan_target_link_libraries(dear-imgui-conan)
#target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
target_link_libraries(${PROJECT_NAME} CONAN_PKG::cpr)

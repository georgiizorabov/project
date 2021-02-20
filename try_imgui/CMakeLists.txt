cmake_minimum_required(VERSION 2.8.12)
project(dear-imgui-conan)


include_directories(/home/slawa4s/.conan/data/imgui/1.80/_/_/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/include/)
include_directories(/home/slawa4s/.conan/data/glfw/3.3.2/_/_/package/751cb22e3ee3d822a8b7af83813b032dc3867205/include/)
include_directories(/home/slawa4s/.conan/data/nlohmann_json/3.9.1/_/_/package/d1091b2ed420e6d287293709a907ae824d5de508/include/)

include(build/conanbuildinfo_multi.cmake)
conan_basic_setup()

add_executable(dear-imgui-conan
    main.cpp
        try_json.h
    bindings/imgui_impl_glfw.cpp
    bindings/imgui_impl_opengl2.cpp
    bindings/imgui_impl_glfw.h
    bindings/imgui_impl_opengl2.h
)

conan_target_link_libraries(dear-imgui-conan)

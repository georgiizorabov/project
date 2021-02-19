cd dear-imgui-conan-example
mkdir build
cd build
conan install .. -s build_type=Release
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
./dear-imgui-conan

cd dear-imgui-conan-example
mkdir build
cd build
conan install .. -s compiler=gcc -s compiler.libcxx=libstdc++11 --build=missing
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
./dear-imgui-conan

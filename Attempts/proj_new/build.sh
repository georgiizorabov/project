#!/bin/bash

set -x

mkdir -p build
cd build
rm -f proj_new
if [ "$(uname)" != "Darwin" ]; then
    # if it's not Mac
    # https://stackoverflow.com/a/17072017
    CONAN_COMPILER_ARGS="-s compiler=gcc -s compiler.libcxx=libstdc++11"
fi
conan install .. $CONAN_COMPILER_ARGS --build=missing
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
./proj_new

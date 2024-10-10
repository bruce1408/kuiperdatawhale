#!/bin/bash

workdir="$(cd "$(dirname "$0")" || exit; pwd)"

cd "${workdir}" || exit

rm -rf build/

mkdir -p build && cd build || exit

cmake .. 

# cmake -DUSE_CPM=ON ..

make -j16

./kuiper_datawhale_course1

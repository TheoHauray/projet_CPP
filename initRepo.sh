#!/bin/sh

mkdir -p build 

cd build

cmake ..

make

cd ..

rm -r ../build

mv build ../build
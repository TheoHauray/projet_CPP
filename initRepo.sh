#!/bin/sh

mkdir -p build 

cd build

cmake ..

make

rm -r ../build

mv build ../build
#!/bin/sh

rm -rf build-clang
mkdir build-clang && cd build-clang

CXX=clang++
CC=clang
scan-build -k qmake-qt5 ..
scan-build -k -o results make

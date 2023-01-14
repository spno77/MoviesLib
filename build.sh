#!/bin/bash

CC=g++
LD=g++
BUILD_PATH="build/Release"
BIN_PATH="bin"
LIB_PATH="lib"
CFLAGS="-O2 -std=c++17"

mkdir -p build
mkdir -p $BIN_PATH
mkdir -p $BIN_PATH/assets
mkdir -p $BUILD_PATH


$CC $CFLAGS -L$LIB_PATH -I. project/main.cpp project/button.cpp project/movie.cpp project/interface.cpp project/rectWidget.cpp project/image.cpp -o $BIN_PATH/main -lsgg -lGL -lGLEW -lSDL2 -lSDL2_mixer -lfreetype -lstdc++fs


#!/bin/bash

CC=g++
LD=g++
BUILD_PATH="build/Release"
BUILD_PATH_DEBUG="build/Debug"
BIN_PATH="bin"
LIB_PATH="lib"
CFLAGS="-O2 -std=c++17"
CFLAGS_DEBUG="-Og -g -std=c++17"

mkdir -p build
mkdir -p $BIN_PATH
mkdir -p $BIN_PATH/assets
mkdir -p $BUILD_PATH
mkdir -p $BUILD_PATH_DEBUG

$CC $CFLAGS -L$LIB_PATH -I. project/main.cpp project/button.cpp project/movie.cpp -o $BIN_PATH/main -lsgg -lGL -lGLEW -lSDL2 -lSDL2_mixer -lfreetype -lstdc++fs

$CC $CFLAGS_DEBUG -L$LIB_PATH -I. project/main.cpp project/button.cpp project/movie.cpp -o $BIN_PATH/maind -lsggd -lGL -lGLEW -lSDL2 -lSDL2_mixer -lfreetype -lstdc++fs


#!/usr/bin/env bash

mkdir cmake-build-debug -p
cd cmake-build-debug
cmake -G"Unix Makefiles" ..
make
cd ..
mkdir tmp -p
test_file_gen.py

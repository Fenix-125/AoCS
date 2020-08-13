#!/usr/bin/env bash

mkdir -p build

pushd build
cmake -G"Unix Makefiles" ../
make
popd

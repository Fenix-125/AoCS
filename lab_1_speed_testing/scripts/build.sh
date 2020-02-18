#!/usr/bin/env bash

mkdir cmake-build-debug -p
cd cmake-build-debug
cmake -G"Unix Makefiles" ..
make
cd ..
mkdir tmp -p
if [[ -f tmp/doubles_1MB.txt ]]; then rm tmp/doubles_1MB.txt; fi
python3.8 scripts/test_file_gen.py

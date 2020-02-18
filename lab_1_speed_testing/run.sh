#!/usr/bin/env bash
if [! -d tmp]; then
    scripts/build.sh
fi

scripts/test_double_cast_performance.py 1000 tmp/doubles_1MB.txt tmp/resul.txt

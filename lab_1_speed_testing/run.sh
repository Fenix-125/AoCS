#!/usr/bin/env bash
if [[ ! -d tmp ]]; then
    bash scripts/build.sh
fi

python3.8 scripts/test_double_cast_performance.py 6 tmp/doubles_1MB.txt tmp/resul.txt

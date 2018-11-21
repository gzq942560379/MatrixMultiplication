#!/usr/bin/env bash

valgrind --tool=cachegrind --cachegrind-out-file=simple_1000_1000_1000 ../cmake-build-debug/bin/simple 1000 1000 1000
valgrind --tool=cachegrind --cachegrind-out-file=pre_transpose_1000_1000_1000 ../cmake-build-debug/bin/pre_transpose 1000 1000 1000



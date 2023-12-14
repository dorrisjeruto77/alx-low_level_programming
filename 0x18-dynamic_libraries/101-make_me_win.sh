#!/bin/bash
wget -P .. https://raw.githubusercontent.com/dorrisjeruto77/alx-low_level_programming/master/0x18-dynamic_libraries/libtesting.so
export LD_PRELOAD="$PWD/ ../lbtesting.so"

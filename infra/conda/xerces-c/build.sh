#!/bin/bash

./configure --prefix=$PREFIX --without-icu
make -j $CPU_COUNT
make install -j $CPU_COUNT

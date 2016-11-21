#!/bin/bash

./configure --prefix=$PREFIX --without-icu
make
make install

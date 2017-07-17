#!/bin/bash

set -x -e

INCLUDE_PATH="${PREFIX}/include"
LIBRARY_PATH="${PREFIX}/lib"

if [ "$(uname)" == "Linux" ]; then
    ./bootstrap.sh \
        --prefix="${PREFIX}" \
        --without-icu \
        --with-libraries=system,filesystem,serialization,program_options \
        | tee bootstrap.log 2>&1

    ./b2 -q \
        variant=release \
        address-model="${ARCH}" \
        architecture=x86 \
        debug-symbols=off \
        threading=multi \
        runtime-link=shared \
        link=shared \
        toolset=gcc \
        cxxflags=-std=c++11 \
        include="${INCLUDE_PATH}" \
        linkflags="-L${LIBRARY_PATH}" \
        --layout=system \
        -j"${CPU_COUNT}" \
        -s NO_BZIP2=1 \
        install | tee b2.log 2>&1
fi

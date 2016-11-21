#!/bin/bash

mkdir build
cd build

cmake .. \
    -DBUILD_SHARED_LIBS:BOOL=ON \
    -DBUILD_EXAMPLES:BOOL=off \
    -DITK_WRAP_PYTHON:BOOL=ON \
    -DCMAKE_BUILD_TYPE:STRING=Release \
    -DITK_USE_FLAT_DIRECTORY_INSTALL:BOOL=ON \
    -DITK_USE_REVIEW:BOOL=ON \
    -DModule_ITKReview:BOOL=ON \
    -DVTK_DIR:PATH=${PREFIX} \
    -DBUILD_TESTING:BOOL=OFF \
    -DModule_ITKVtkGlue:BOOL=ON \
    -DCMAKE_INSTALL_PREFIX:PATH="${PREFIX}"

make -j${CPU_COUNT}
make install

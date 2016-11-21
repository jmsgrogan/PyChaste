#!/bin/bash

mkdir build
cd build

cmake .. \
    -DBUILD_SHARED_LIBS:BOOL=ON \
    -DUSE_SYSTEM_ITK:BOOL=ON \
    -DUSE_SYSTEM_VTK:BOOL=ON \
    -DITK_DIR:PATH=${PREFIX} \
    -DVTK_DIR:PATH=${PREFIX}

make -j${CPU_COUNT}
cd ../..
cp -R vmtk-1.3/build/Install/* ${PREFIX}

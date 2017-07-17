#!/bin/bash

export PETSC_DIR=$SRC_DIR
export PETSC_ARCH=arch-conda-c-opt

if [[ $(uname) == Darwin ]]; then
    SO=dylib
else
    SO=so
fi

export MPICH=https://www.mpich.org/static/downloads/3.2/mpich-3.2.tar.gz
export HDF5=https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-1.8/hdf5-1.8.16/src/hdf5-1.8.16.tar.bz2

$PYTHON ./configure \
  --with-debugging=0 \
  --download-mpich \
  --download-hdf5=$HDF5 \
  --COPTFLAGS=-O3 \
  --CXXOPTFLAGS=-O3 \
  --LIBS=-Wl,-rpath,$PREFIX/lib \
  --with-hwloc=0 \
  --with-ssl=0 \
  --with-x=0 \
  --download-hypre \
  --download-f2cblaslapack \
  --download-hdf5 \
  --download-parmetis \
  --download-metis \
  --download-sundials \
  --with-shared-libraries \
  --with-clanguage=cxx \
  --prefix=$PREFIX

sedinplace() { [[ $(uname) == Darwin ]] && sed -i "" $@ || sed -i"" $@; }
for path in $PETSC_DIR $PREFIX; do
    sedinplace s%$path%\${PETSC_DIR}%g $PETSC_ARCH/include/petsc*.h
done

make
make install



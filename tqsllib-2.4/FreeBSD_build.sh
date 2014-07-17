#!/bin/sh
cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    -DBUILD_ALL_EXTRAPROGS=ON \
    -DTQSLLIB_STATIC=ON \
    .
make

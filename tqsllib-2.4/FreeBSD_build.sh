#!/bin/sh
TARGET_DIR=/home/kenji/bin/tqsllib/bin/
#
cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    -DBUILD_ALL_EXTRAPROGS=ON \
    -DTQSLLIB_STATIC=ON \
    .
make -j8
#
install -c -m 0755 gen_crq ${TARGET_DIR}
install -c -m 0755 dumptqsldata ${TARGET_DIR}
install -c -m 0755 converter ${TARGET_DIR}
install -c -m 0755 station_loc ${TARGET_DIR}
install -c -m 0755 load_cert ${TARGET_DIR}

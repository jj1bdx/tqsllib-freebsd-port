#!/bin/sh
TARGET=/home/kenji/bin/tqsllib/bin

cp -f converter gen_crq station_loc load_cert $TARGET
mkdir $TARGET/.libs
cp -fpr .libs/* $TARGET/.libs/
mkdir $TARGET/.deps
cp -fpr .deps/* $TARGET/.deps/

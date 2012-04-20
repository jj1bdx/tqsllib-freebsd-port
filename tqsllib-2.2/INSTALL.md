# local procedure

    make distclean
    ./configure --prefix=/home/kenji/bin/tqsllib --with-openssl=/usr/local
    make
    ./make-and-copy-tools

## for using g++46

    env CC="gcc46" CXX="g++46" LIBS="/usr/local/lib/gcc46/libstdc++.so" \
        ./configure --with-openssl=/usr/local

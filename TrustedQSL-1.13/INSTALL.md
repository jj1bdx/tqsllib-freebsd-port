# local procedure

    ./configure --prefix=$HOME/bin/trustedqsl --with-tqsllib=$HOME/bin/tqsllib --with-wxwindows=/usr/local --with-openssl=/usr/local
    make
    make install

## for using g++46

    env CC="gcc46" CXX="g++46" LIBS="/usr/local/lib/gcc46/libstdc++.so" \
        ./configure --prefix=$HOME/bin/trustedqsl --with-tqsllib=$HOME/bin/tqsllib --with-wxwindows=/usr/local --with-openssl=/usr/local

# to run the code

    # (this is dirty but enough for testing)
    env LD_LIBRARY_PATH="/home/kenji/bin/tqsllib/lib:$LD_LIBRARY_PATH" /home/kenji/bin/trustedqsl/bin/tqslcert

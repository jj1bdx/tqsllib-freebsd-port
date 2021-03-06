/***************************************************************************
                          load_cert.cpp  -  description
                             -------------------
    begin                : Sat Dec 14 2002
    copyright            : (C) 2002 by ARRL
    author               : Jon Bloom
    email                : jbloom@arrl.org
    revision             : $Id: load_cert.cpp,v 1.7 2005/02/18 20:21:01 ke3z Exp $
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
#include "sysconfig.h"
#endif

#include <cstdlib>
#include <iostream>
#include "tqsllib.h"

using namespace std;

int
cb(int, const char *msg, void *) {
	cout << msg << endl;
	return 0;
}

int
main(int argc, char *argv[]) {
	if (tqsl_init()) {
		cerr << tqsl_getErrorString() << endl;
		return EXIT_FAILURE;
	}
	for (int i = 1; i < argc; i++) {
		if (tqsl_importTQSLFile(argv[i], cb, 0)) {
			cerr << tqsl_getErrorString() << endl;
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}

/***************************************************************************
                          tqslapp.h  -  description
                             -------------------
    begin                : Sun Jun 16 2002
    copyright            : (C) 2002 by ARRL
    author               : Jon Bloom
    email                : jbloom@arrl.org
    revision             : $Id: tqslapp.h,v 1.5 2005/02/18 16:38:58 ke3z Exp $
 ***************************************************************************/

#ifndef __tqslapp_h
#define __tqslapp_h

#define TQSL_CRQ_FILE_EXT "tq5"
#define TQSL_CERT_FILE_EXT "tq6"

#ifdef __WXMSW__
	#define ALLFILESWILD "*.*"
#else
	#define ALLFILESWILD "*"
#endif

#endif // __tqslapp_h
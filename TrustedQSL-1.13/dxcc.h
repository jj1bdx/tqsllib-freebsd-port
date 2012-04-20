/***************************************************************************
                          dxcc.h  -  description
                             -------------------
    begin                : Tue Jun 18 2002
    copyright            : (C) 2002 by ARRL
    author               : Jon Bloom
    email                : jbloom@arrl.org
    revision             : $Id: dxcc.h,v 1.6 2010/03/09 01:31:06 k1mu Exp $
 ***************************************************************************/

#ifndef __dxcc_h
#define __dxcc_h

#ifdef HAVE_CONFIG_H
#include "sysconfig.h"
#endif

class DXCC {
public:
	DXCC() {};
	int number() const { return _number; }
	const char * name() const { return _name; }
	const char * zonemap() const { return _zonemap; }
	bool getFirst();
	bool getNext();
	bool getByEntity(int e);
	static bool init();
private:
	static bool _init;
	int _number, _index;
	const char *_name;
	const char *_zonemap;
};

#endif // __dxcc_h

/***************************************************************************
                          tqslexcept.h  -  description
                             -------------------
    begin                : Fri Nov 15 2002
    copyright            : (C) 2002 by ARRL
    author               : Jon Bloom
    email                : jbloom@arrl.org
    revision             : $Id: tqslexcept.h,v 1.3 2005/02/18 20:28:30 ke3z Exp $
 ***************************************************************************/

#ifndef __tqslexcept_h
#define __tqslexcept_h

#ifdef HAVE_CONFIG_H
#include "sysconfig.h"
#endif

#include <exception>
#include <string>

class TQSLException : public std::exception {
public:
	TQSLException(const char *msg);
	~TQSLException() throw () {}
	virtual const char *what() throw () { return _msg.c_str(); }
private:
	std::string _msg;
};

inline TQSLException::TQSLException(const char *msg) : exception() {
	_msg = msg;
}

#endif	// __tqslexcept_h
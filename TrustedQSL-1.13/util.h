/***************************************************************************
                          util.h  -  description
                             -------------------
    begin                : Sun Jun 23 2002
    copyright            : (C) 2002 by ARRL
    author               : Jon Bloom
    email                : jbloom@arrl.org
    revision             : $Id: util.h,v 1.3 2005/02/18 20:28:30 ke3z Exp $
 ***************************************************************************/

#ifndef __util_h
#define __util_h

#ifdef HAVE_CONFIG_H
#include "sysconfig.h"
#endif

void displayCertProperties(CertTreeItemData *item, wxWindow *parent = 0);
int getPassword(char *buf, int bufsiz, void *);
void displayTQSLError(const char *pre);
wxMenu *makeCertificateMenu(bool enable, bool keyonly = false);

#endif	// __util_h

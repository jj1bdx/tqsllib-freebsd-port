/***************************************************************************
                          cabrillo.h  -  description
                             -------------------
    begin                : Thu Dec 5 2002
    copyright            : (C) 2002 by ARRL
    author               : Jon Bloom
    email                : jbloom@arrl.org
    revision             : $Id: cabrillo.h,v 1.6 2005/02/23 18:09:23 ke3z Exp $
 ***************************************************************************/

#ifndef __CABRILLO_H
#define __CABRILLO_H

#include "tqsllib.h"

#undef CLIENT_STATIC
#ifndef LOTW_SERVER
#define CLIENT_STATIC static
#else
#define CLIENT_STATIC
#endif

/** \defgroup Cabrillo Cabrillo API
  *
  * These functions and data structures provide a means of parsing a Cabrillo
  * file into its component fields.
  *
  * For convenience, the returned fields are identified using field names
  * from the \link ADIF ADIF \endlink specification.
  */
/** @{ */

#define TQSL_CABRILLO_FIELD_NAME_LENGTH_MAX 64
#define TQSL_CABRILLO_FIELD_VALUE_LENGTH_MAX 40

/// Cabrillo status values
typedef enum {
	TQSL_CABRILLO_NO_ERROR,
	TQSL_CABRILLO_EOF,
	TQSL_CABRILLO_NO_START_RECORD,
	TQSL_CABRILLO_NO_CONTEST_RECORD,
	TQSL_CABRILLO_UNKNOWN_CONTEST,
	TQSL_CABRILLO_BAD_FIELD_DATA,
	TQSL_CABRILLO_EOR,
} TQSL_CABRILLO_ERROR_TYPE;

typedef enum {
	TQSL_CABRILLO_HF,
	TQSL_CABRILLO_VHF,
} TQSL_CABRILLO_FREQ_TYPE;

#define TQSL_MIN_CABRILLO_MAP_FIELD 5

/** Cabrillo field data:
  *
  * \li \c name - ADIF field name
  * \li \c value - Field content
  */
typedef struct {
	char name[TQSL_CABRILLO_FIELD_NAME_LENGTH_MAX +1];
	char value[TQSL_CABRILLO_FIELD_VALUE_LENGTH_MAX +1];
} tqsl_cabrilloField;

typedef void * tQSL_Cabrillo;

#ifdef __cplusplus
extern "C" {
#endif

/** Get the Cabrillo error message that corresponds to a particular error value */
DLLEXPORT const char *tqsl_cabrilloGetError(TQSL_CABRILLO_ERROR_TYPE err);

/** Initialize a Cabrillo file for reading */
DLLEXPORT int tqsl_beginCabrillo(tQSL_Cabrillo *cabp, const char *filename);

/** Get the Contest name as specified in the Cabrillo CONTEST line */
DLLEXPORT int tqsl_getCabrilloContest(tQSL_Cabrillo cab, char *buf, int bufsiz);

/** Get the Frequency type (HF or VHF) as determined by the contest */
DLLEXPORT int tqsl_getCabrilloFreqType(tQSL_Cabrillo cab, TQSL_CABRILLO_FREQ_TYPE *type);

/** Get the current line number (starting from 1) of the input file */
DLLEXPORT int tqsl_getCabrilloLine(tQSL_Cabrillo cab, int *lineno);

/** Get the text of the current Cabrillo record */
DLLEXPORT const char * tqsl_getCabrilloRecordText(tQSL_Cabrillo cab);

/** Get the next field of the Cabrillo record
  *
  * \c err is set to \c TQSL_CABRILLO_NO_ERROR or \c TQSL_CABRILLO_EOR (end-of-record)
  * if \c field was populated with data. If \c err == \c TQSL_CABRILLO_EOR, this
  * is the last field of the record.
  *
  * \c err == \c TQSL_CABRILLO_EOF when there is no more data available.
  */
DLLEXPORT int tqsl_getCabrilloField(tQSL_Cabrillo cab, tqsl_cabrilloField *field, TQSL_CABRILLO_ERROR_TYPE *err);

/** Finish reading a Cabrillo file and release its resources */
DLLEXPORT int tqsl_endCabrillo(tQSL_Cabrillo *cabp);

#ifdef __cplusplus
}
#endif

/** @} */

#endif // __CABRILLO_H

/* $Id: icu_I18N.h,v 1.6 2007-05-07 12:18:34 marc Exp $
   Copyright (c) 2006-2007, Index Data.

This file is part of Pazpar2.

Pazpar2 is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

Pazpar2 is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with Pazpar2; see the file LICENSE.  If not, write to the
Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.
 */

#ifndef ICU_I18NL_H
#define ICU_I18NL_H

#ifdef HAVE_ICU

#include <yaz/nmem.h>


#include <unicode/utypes.h>   /* Basic ICU data types */
#include <unicode/uchar.h>    /* char names           */

//#include <unicode/ustdio.h>
#include <unicode/ucol.h> 
//#include <unicode/ucnv.h>     /* C   Converter API    */
//#include <unicode/ustring.h>  /* some more string fcns*/
//#include <unicode/uloc.h>
//#include <unicode/ubrk.h>
//#include <unicode/unistr.h>


int icu_check_status (UErrorCode status);

struct icu_buf_utf16
{
  UChar * utf16;
  int32_t utf16_len;
  int32_t utf16_cap;
};

struct icu_buf_utf16 * icu_buf_utf16_create(size_t capacity);
struct icu_buf_utf16 * icu_buf_utf16_resize(struct icu_buf_utf16 * buf16,
                                            size_t capacity);
void icu_buf_utf16_destroy(struct icu_buf_utf16 * buf16);



struct icu_buf_utf8
{
  uint8_t * utf8;
  int32_t utf8_len;
  int32_t utf8_cap;
};

struct icu_buf_utf8 * icu_buf_utf8_create(size_t capacity);
struct icu_buf_utf8 * icu_buf_utf8_resize(struct icu_buf_utf8 * buf8,
                                          size_t capacity);
void icu_buf_utf8_destroy(struct icu_buf_utf8 * buf8);


UErrorCode icu_utf16_from_utf8(struct icu_buf_utf16 * dest16,
                               struct icu_buf_utf8 * src8,
                               UErrorCode * status);

UErrorCode icu_utf16_from_utf8_cstr(struct icu_buf_utf16 * dest16,
                                    const char * src8cstr,
                                    UErrorCode * status);


UErrorCode icu_utf16_to_utf8(struct icu_buf_utf8 * dest8,
                             struct icu_buf_utf16 * src16,
                             UErrorCode * status);


UErrorCode icu_sortkey8_from_utf16(UCollator *coll,
                                   struct icu_buf_utf8 * dest8, 
                                   struct icu_buf_utf16 * src16,
                                   UErrorCode * status);









// CRAP to Follow here ...

#if 0
struct icu_termmap
{
    char * sort_key;   // standard C string '\0' terminated 
    char * norm_term;  // standard C utf-8 string
    char * disp_term;  // standard C utf-8 string
};

struct icu_termmap * icu_termmap_create(NMEM nmem);

int icu_termmap_cmp(const void *vp1, const void *vp2);

char * icu_casemap(NMEM nmem, char *buf, size_t buf_cap, 
                   size_t *dest8_len,  const char *src8,
                   const char *locale, char action);

char * icu_sortmap(NMEM nmem, char *buf, size_t buf_cap, 
                   size_t *dest8_len,  const char *src8,
                   const char *locale);

#endif // 0


#endif // HAVE_ICU
#endif // ICU_I18NL_H

/*
  The oSIP library implements the Session Initiation Protocol (SIP -rfc3261-)
  Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Aymeric MOIZARD jack@atosc.org
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/


#ifndef _OSIP_PORT_H_
#define _OSIP_PORT_H_

/* Include necessary headers for osip */

#include <stdio.h>
#include <stdlib.h>
#if defined(__arc__)
#include "includes_api.h"
#include "os_cfg_pub.h"
#include <posix_time_pub.h>
#endif

#if defined(__PALMOS__) && (__PALMOS__ >= 0x06000000)
#	define STDC_HEADERS 1
#	define HAVE_CTYPE_H 1
#	define HAVE_STRING_H 1
#	define HAVE_SYS_TYPES_H 1
#	define HAVE_TIME_H 1
#	define HAVE_STDARG_H 1

#elif defined _WIN32_WCE

#define STDC_HEADERS 1
#define HAVE_CTYPE_H 1
#define HAVE_STRING_H 1
#define HAVE_TIME_H 1
#define HAVE_STDARG_H 1

#define snprintf  _snprintf
#define EBUSY           16

#elif defined(WIN32)

#define STDC_HEADERS 1
#define HAVE_CTYPE_H 1
#define HAVE_STRING_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_TIME_H 1
#define HAVE_STDARG_H 1

#define snprintf _snprintf

/* use win32 crypto routines for random number generation */
/* only use for vs .net (compiler v. 1300) or greater */
#if _MSC_VER >= 1300
#define WIN32_USE_CRYPTO 1
#endif

#endif

#if defined(__VXWORKS_OS__) || defined(__rtems__)
#include <string.h>
#include <time.h>
#include <sys/times.h>
#include <stdarg.h>
#include <sys/types.h>
#include <stdlib.h>
#define VA_START(a, f)  va_start(a, f)

#if defined(__VXWORKS_OS__)
/* VxWorks lacks support for snprintf */
int osip_vsnprintf(char *buf, int max, const char *fmt, va_list ap);
int osip_snprintf(char *buf, int max, const char *fmt, ...);

#define snprintf  osip_snprintf
#define vsnprintf osip_vsnprintf
#endif

#else							/* end of __VXWORKS_OS__ */

#if defined (HAVE_CONFIG_H)
#include <config.h>
#  if defined (HAVE_STRING_H)
#    include <string.h>
#  else
#    include <strings.h>
#  endif						/* HAVE_STRING_H */
#else
#  include <string.h>
#endif							/* !HAVE_CONFIG_H */

#if defined (HAVE_SYS_TYPES_H)
#  include <sys/types.h>
#endif

#ifdef STDC_HEADERS
#    include <stdlib.h>
#endif							/* !STDC_HEADERS */

#if defined(HAVE_STDARG_H) || defined(WIN32)
#  include <stdarg.h>
#  define VA_START(a, f)  va_start(a, f)
#else
#  if defined(HAVE_VARARGS_H)
#    include <varargs.h>
#    define VA_START(a, f) va_start(a)
#  else
#    include <stdarg.h>
#    define VA_START(a, f)  va_start(a, f)
#  endif
#endif

#ifdef HAVE_TIME_H
#  include <time.h>
#endif

#if defined (HAVE_SYS_TIME_H)
#  include <sys/time.h>
#endif

#endif							/* end of !__VXWORKS_OS__ */

#ifdef _WIN32_WCE
#define VA_START(a, f)  va_start(a, f)
#endif

#ifdef WIN32
#define VA_START(a, f)  va_start(a, f)
#endif

#ifdef __PSOS__
#define VA_START(a, f)  va_start(a, f)
#include "pna.h"
#include "stdlib.h"
#include "time.h"
#define timercmp(tvp, uvp, cmp) \
        ((tvp)->tv_sec cmp (uvp)->tv_sec || \
         (tvp)->tv_sec == (uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#define snprintf  osip_snprintf
#ifndef INT_MAX
#define INT_MAX 0x7FFFFFFF
#endif

#endif


#if __STDC__
#  ifndef NOPROTOS
#    define PARAMS(args)   args
#  endif
#endif

#ifndef PARAMS
#  define PARAMS(args)     ()
#endif

#include <osipparser2/osip_const.h>

#include <osipparser2/osip_list.h>

#define SIP_SYNTAX_ERROR    (-1)
#define SIP_NETWORK_ERROR   (-2)
#define SIP_ECONNREFUSED    (-3)
#define SIP_RESSOURCE_ERROR (-4)
#define SIP_GLOBAL_ERROR    (-5)

#ifdef __cplusplus
extern "C" {
#endif

/**************************/
/* MALLOC redirections    */
/**************************/

#if !defined(WIN32) && !defined(_WIN32_WCE)

#ifndef MINISIZE
	typedef void *osip_malloc_func_t(size_t size);
	typedef void osip_free_func_t(void *ptr);
	typedef void *osip_realloc_func_t(void *ptr, size_t size);

	extern osip_malloc_func_t *osip_malloc_func;
	extern osip_realloc_func_t *osip_realloc_func;
	extern osip_free_func_t *osip_free_func;

	void osip_set_allocators(osip_malloc_func_t * malloc_func,
							 osip_realloc_func_t * realloc_func,
							 osip_free_func_t * free_func);
#endif

#ifdef DEBUG_MEM

	void *_osip_malloc(size_t size, char *file, unsigned short line);
	void _osip_free(void *ptr);
	void *_osip_realloc(void *ptr, size_t size, char *file, unsigned short line);

#ifndef osip_malloc
#define osip_malloc(S) _osip_malloc(S,__FILE__,__LINE__)
#endif
#ifndef osip_realloc
#define osip_realloc(P,S) _osip_realloc(P,S,__FILE__,__LINE__)
#endif
#ifndef osip_free
#define osip_free(P) { if (P!=NULL) { _osip_free(P); } }
#endif

#else

#ifndef MINISIZE
#ifndef osip_malloc
#define osip_malloc(S) (osip_malloc_func?osip_malloc_func(S):malloc(S))
#endif
#ifndef osip_realloc
#define osip_realloc(P,S) (osip_realloc_func?osip_realloc_func(P,S):realloc(P,S))
#endif
#ifndef osip_free
void	 free(void *);
#define osip_free(P) { if (P!=NULL) { if (osip_free_func) osip_free_func(P); else free(P);} }
#endif

#else
	/* MINISIZE code */
#ifndef osip_malloc
#define osip_malloc(S) malloc(S)
#endif
#ifndef osip_realloc
#define osip_realloc(P,S) realloc(P,S)
#endif
#ifndef osip_free
#define osip_free(P) { if (P!=NULL) { free(P);} }
#endif

#endif

#endif

#else

	void *osip_malloc(size_t size);
	void *osip_realloc(void *, size_t size);
	void osip_free(void *);

#endif

#ifdef WIN32
#define alloca _alloca
#endif

/**************************/
/* RANDOM number support  */
/**************************/

	unsigned int osip_build_random_number(void);

/**************************/
/* TIMER support          */
/**************************/

#define SP   " \0"

	void osip_usleep(int useconds);

#ifndef MINISIZE
	int osip_atoi(const char *number);
	int osip_strcasecmp(const char *s1, const char *s2);
	int osip_strncasecmp(const char *s1, const char *s2, size_t len);
	char *osip_strcasestr(const char *haystack, const char *needle);
	
#else
#define osip_atoi  atoi
#define osip_strcasecmp  strcasecmp
#define osip_strncasecmp  strncasecmp
#define osip_strcasestr  strcasestr
#endif

/**************************/
/* STRING support         */
/**************************/

	char *osip_strncpy(char *dest, const char *src, size_t length);
	char *osip_strdup(const char *ch);
	char *osip_strdup_without_quote(const char *ch);
	int osip_tolower(char *word);
	int osip_clrspace(char *word);
	char *__osip_sdp_append_string(char *string, size_t size,
								   char *cur, char *string_osip_to_append);
	int __osip_set_next_token(char **dest, char *buf, int end_separator,
							  char **next);
	/* find the next unescaped quote and return its index. */
	char *__osip_quote_find(const char *qstring);
	char *osip_enquote(const char *s);
	void osip_dequote(char *s);

	unsigned long osip_hash(const char *str);
	char *osip_str_append(char *dst, const char *src);
	char *osip_strn_append(char *dst, const char *src, size_t len);
	char *osip_clrncpy(char *dst, const char *src, size_t len);

/**************************/
/* LOG&DEBUG support      */
/**************************/

#define LOG_TRUE  1
#define LOG_FALSE 0
/* levels */
	typedef enum _trace_level {
		TRACE_LEVEL0 = 0,
#define OSIP_FATAL    TRACE_LEVEL0
		TRACE_LEVEL1 = 1,
#define OSIP_BUG      TRACE_LEVEL1
		TRACE_LEVEL2 = 2,
#define OSIP_ERROR    TRACE_LEVEL2
		TRACE_LEVEL3 = 3,
#define OSIP_WARNING  TRACE_LEVEL3
		TRACE_LEVEL4 = 4,
#define OSIP_INFO1    TRACE_LEVEL4
		TRACE_LEVEL5 = 5,
#define OSIP_INFO2    TRACE_LEVEL5
		TRACE_LEVEL6 = 6,
#define OSIP_INFO3    TRACE_LEVEL6
		TRACE_LEVEL7 = 7,
#define OSIP_INFO4    TRACE_LEVEL7
		END_TRACE_LEVEL = 8
	} osip_trace_level_t;


	typedef void osip_trace_func_t(char *fi, int li, osip_trace_level_t level,
								   char *chfr, va_list ap);
	typedef void osip_message_hook_fun_t(int received,const char *host ,int port,const char *buf);
	void osip_set_message_hook_func( osip_message_hook_fun_t *func);
	void osip_message_hook(int received, const char *host, int port,const char *buf);

/* these are defined in all cases, but are empty when oSIP is compiled
   without trace */
	void osip_trace_initialize_func(osip_trace_level_t level,
									osip_trace_func_t * func);
	void osip_trace_initialize_syslog(osip_trace_level_t level, char *ident);
	void osip_trace_initialize(osip_trace_level_t level, FILE * file);
	void osip_trace_enable_until_level(osip_trace_level_t level);
	void osip_trace_enable_level(osip_trace_level_t level);
	void osip_trace_disable_level(osip_trace_level_t level);
	int osip_is_trace_level_activate(osip_trace_level_t level);

#ifndef ENABLE_TRACE

#define TRACE_INITIALIZE(level, file)  do { } while (0)
#define TRACE_ENABLE_LEVEL(level)      do { } while (0)
#define TRACE_DISABLE_LEVEL(level)     do { } while (0)
#define IS_TRACE_LEVEL_ACTIVATE(level) (-1)

#else

#define TRACE_INITIALIZE(level, file)  osip_trace_initialize(level, file)
#define TRACE_ENABLE_LEVEL(level)      osip_trace_enable_level ( level )
#define TRACE_DISABLE_LEVEL(level)     osip_trace_disable_level ( level )
#define IS_TRACE_LEVEL_ACTIVATE(level) osip_is_trace_level_activate( level )

#endif

/* log facility. */
/* if f is NULL, current default log file is used. */
/* INPUT: level | level of the trace               */
/* INPUT: f | use f instead of default log file    */
/* INPUT: chfr | format string for next args       */
	int osip_trace(char *fi, int li, osip_trace_level_t level, FILE * f,
				   char *chfr, ...);

#ifdef ENABLE_TRACE
#define OSIP_TRACE(P) P
#define OSIP_MESSAGE_HOOK(P) do{} while(0)
#else
#define OSIP_TRACE(P) do {} while (0)
#define OSIP_MESSAGE_HOOK(P) P;
#endif
#define OSIP_MESSAGE_HOOK_ALWAYS(P) P;

#define REMOVE_ELEMENT(first_element, element)   \
       if (element->parent==NULL)                \
	{ first_element = element->next;         \
          if (first_element!=NULL)               \
          first_element->parent = NULL; }        \
       else \
        { element->parent->next = element->next; \
          if (element->next!=NULL)               \
	element->next->parent = element->parent; \
	element->next = NULL;                    \
	element->parent = NULL; }

#define ADD_ELEMENT(first_element, element) \
   if (first_element==NULL)                 \
    {                                       \
      first_element   = element;            \
      element->next   = NULL;               \
      element->parent = NULL;               \
    }                                       \
  else                                      \
    {                                       \
      element->next   = first_element;      \
      element->parent = NULL;               \
      element->next->parent = element;      \
      first_element = element;              \
    }

#define APPEND_ELEMENT(type_of_element_t, first_element, element) \
  if (first_element==NULL)                            \
    { first_element = element;                        \
      element->next   = NULL; /* useless */           \
      element->parent = NULL; /* useless */ }         \
  else                                                \
    { type_of_element_t *f;                           \
      for (f=first_element; f->next!=NULL; f=f->next) \
         { }                                          \
      f->next    = element;                           \
      element->parent = f;                            \
      element->next   = NULL;                         \
    }

	const char *osip_strerror(int err);

#ifdef __cplusplus
}
#endif
#define OSIP_SUCCESS               0
#define OSIP_UNDEFINED_ERROR      -1
#define OSIP_BADPARAMETER         -2
#define OSIP_WRONG_STATE          -3
#define OSIP_NOMEM                -4
#define OSIP_SYNTAXERROR          -5
#define OSIP_NOTFOUND             -6
#define OSIP_API_NOT_INITIALIZED  -7
#define OSIP_NO_NETWORK           -10
#define OSIP_PORT_BUSY            -11
#define OSIP_UNKNOWN_HOST         -12
#define OSIP_DISK_FULL            -30
#define OSIP_NO_RIGHTS            -31
#define OSIP_FILE_NOT_EXIST       -32
#define OSIP_TIMEOUT              -50
#define OSIP_TOOMUCHCALL          -51
#define OSIP_WRONG_FORMAT         -52
#define OSIP_NOCOMMONCODEC        -53
#endif							/* _PORT_H_ */

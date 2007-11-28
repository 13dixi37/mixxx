/**********************************************
 * Cmetrics.h - Case Metrics Interface
 *  Copyright 2007 John Sully.
 *
 *  This file is part of Case Metrics.
 *
 *  Case Metrics is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as 
 *  published by the Free Software Foundation.
 *
 *  Case Metrics is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Case Metrics.  If not, see <http://www.gnu.org/licenses/>.
 *
 **********************************************/

#ifndef __UMETRICS_GLOBALDEFS__
#define __UMETRICS_GLOBALDEFS__

#define _CRT_SECURE_NO_DEPRECATE

#define LIB_NAME "CMETRICS"
#define LIB_VERSION "0.3 GPL"

/* ATTEMPT AUTO-DETECTION OF 64-bit */
#ifdef __X86__
#elif __X64__
#else
//#warning "No CPU Architecture set, attempting auto-detection."
#ifdef __LP64__
//#warning "Setting to X64"
#define __X64__ 1
#define LIB_ARCH "X64"
#else
//#warning "Setting to X86"
#define __X86__ 1
#define LIB_ARCH "X86"
#endif
#endif

/* Set LIB_OS String */
#ifdef LINUX
#define LIB_OS "LINUX"
#elif WIN32
#define LIB_OS "WIN32"
#else
#error "OS Not Supported"
#endif

/* Set LIB_CLIENT */
#ifndef LIB_CLIENT
#ifdef DEBUG
#define LIB_CLIENT "DEBUG"
#else
#error "You must define a client name."
#endif //DEBUG
#endif //LIB_CLIENT

/* SERVER SPECIFIC FIELDS */
#define SERVER_CGI_DIR "/transact.php"
#define SERVER_HTTP_PORT 80
#define SERVER_RETRY_T 2000    //msecs
#define MAX_CONNECT_ATTEMP 10
#define SERVER_MAX_RETRY_C 2

/* PLATFORM SPECIFIC */
#ifdef WIN32
#include <windows.h>	//So we don't accidentally define a type in already in here
#endif


#define LONG_LONG_MAX 9223372036854775807LL

#ifndef WIN32
#define int64 long long

#ifdef __X86__
typedef unsigned int WORD;
typedef unsigned char BYTE;
#elif __X64__
typedef unsigned int WORD;  //32-bits still
typedef unsigned char BYTE;
#endif

#else //WIN32
#define int64 __int64
typedef unsigned char BYTE;
#define _WIN32_WINNT 0x0500
#endif //WIN32

typedef unsigned short XCHAR;   //16-bit for UTF-16
#ifdef WIN32
#else
typedef unsigned int BOOL;
#endif

/* GENERIC DEFINES */
#define TRUE 1
#define FALSE 0


//String Representation Sizes (excludes NULL)
#define INT_DEC_SIZE 11 //Maximum size a string representation of a decimal int
#define UINT_DEC_SIZE 10
#define UINT_HEX_SIZE 8
#define ULONG_HEX_SIZE 16
#define MAX_PATH_SIZE 512

/* ERROR FLAGS */
#define OK 0
#define ERR_FATAL 0x040000000
#define ERR_TEMP 0x020000000 

/* MESSAGE SCOPES */
#define MSGSCOPE_STANDARD 0x01  //Default, sent always
#define MSGSCOPE_DEBUG    0x02  //only sent on error/request

/* ERROR STRINGS */
#define MODULE_ERROR_CSTRING "ERROR"

/* EXTERNAL INTERFACE */
#define LIBINIT cm_init
#define LIBCLOSE cm_close
#define WRITEMSG_ASCII cm_writemsg_ascii
#define WRITEMSG_UTF8 cm_writemsg_utf8
#define WRITEMSG_UTF16 cm_writemsg_utf16
#define WRITEMSG_BIN cm_writemsg_bin
#define WRITEMSG_DBG_UTF8 _cm_write_debugMsg_utf8

#endif //__UMETRICS_GLOBALDEFS__

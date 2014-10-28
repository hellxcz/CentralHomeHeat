/*
 * UtilityMacros.h
 *
 * Created: 1/12/2014 12:16:11 PM
 *  Author: zdene_000
 */


#ifndef UTILITY_MACROS_H_
#define UTILITY_MACROS_H_

#define DO_PRAGMA(x) _Pragma (#x)
#define TODO(x) DO_PRAGMA(message ("TODO - " #x))

#define XSTR(x) STR(x)
#define STR(x) #x

#endif /* UTILITY_MACROS_H_ */
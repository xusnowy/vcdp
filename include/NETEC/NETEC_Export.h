//NETEC_Export.h

#ifndef __NETEC_EXPORT_H__
#define __NETEC_EXPORT_H__

#ifdef WIN32

#ifdef NETEC_EXPORT
#define NETEC_API _declspec(dllexport)
#else
#define NETEC_API _declspec(dllimport)
#endif
#else
#define NETEC_API
#endif // WIN32

#endif
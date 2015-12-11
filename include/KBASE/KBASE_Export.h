//KBASE_Export.h

#ifndef __KBASE_EXPORT_H__
#define __KBASE_EXPORT_H__

#ifdef WIN32

#ifdef KBASE_EXPORTS
#define KBASE_API __declspec(dllexport)
#else
#define KBASE_API __declspec(dllimport)
#endif

#else
#define KBASE_API
#endif // WIN32

#endif

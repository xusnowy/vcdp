//NETEC.h
#ifndef __NETEC_H__
#define __NETEC_H__

#include "NETEC_Export.h"

class NETEC
{
public:
	typedef enum{
		BROTHER=0,
		PARENT,
		CHILD,
	}DOMAIN_TYPE;

	typedef enum{
		ERR_OK=0,
		ERR_DOMAIN_TYPE_UNMATCHED,
		ERR_DOMAIN_LEVEL_UNMATCHED,
	}ERR_CODE;
};

#endif

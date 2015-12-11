/* KAutoLock.h */

#pragma once

#include "CritSec.h"

#include "KBASE/KBASE_Export.h"

//---------------------------------------------------------------------------------------
class KBASE_API KAutoLock
{
public:
	KAutoLock(KCritSec &rCritSec);
	~KAutoLock();

protected:
    KCritSec& m_rCritSec;
};


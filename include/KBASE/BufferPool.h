/* KBufferPool.h */

#pragma once

#include "KBASE/KBASE_Export.h"

#include "Buffer.h"
#include "CritSec.h"
#include "List.h"

//---------------------------------------------------------------------------------------
class KBASE_API KBufferPool
{
public:
	KBufferPool(void);
	~KBufferPool(void);

	virtual void PushFront(KBuffer* pBuffer);
	virtual void PushFront(char* pData,int nLen);

	virtual void PushBack(char* pData,int nLen);
	virtual void PushBack(KBuffer* pBuffer);

	virtual KBuffer* PopFront(void);
	virtual int GetSize(void);

	virtual void Clear(void);

protected:
	KCritSec m_CritSec;
	KList	 m_listBuffer;
};


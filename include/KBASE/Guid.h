#pragma once

#include <string>

#include "KBASE/KBASE_Export.h"

//---------------------------------------------------------------------------------------
// Guid�ඨ��
// ����128λGUID(Generate 128-bit globally unique identifier).
class KBASE_API Guid
{
public:
	Guid();
	Guid(const std::string& strGuid);
	Guid(unsigned char* pBuffer);
	~Guid();

	std::string GetGuid(void);
	const unsigned char* GetBuffer(void);

private:
	Guid(const Guid& rGuid){};
	Guid& operator=(const Guid& rGuid){return *this;};
	unsigned char m_pBuffer[16];
};

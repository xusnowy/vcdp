#pragma once

#include <string>
#include "Utils.h"

#include "KBASE/KBASE_Export.h"

//=======================================================================================
// KUID定义
class KBASE_API KUID
{
public:
	KUID(const std::string& strUID);
	KUID(const std::string& strUserID,const std::string& strDomain);
	~KUID();

	std::string GetUserID(void);
	std::string GetDomain(void);
	std::string GetUID(void);

private:
	std::string m_strUserID;
	std::string m_strDomain;
	std::string m_strUID;
};

//=======================================================================================
// KDomain定义
class KBASE_API KDomain
{
public:
	KDomain(const std::string& strLocalDomain);
	~KDomain();

	std::string GetParentDomain(void);
	int GetParentDomainLevel(void);
	std::string GetLocalDomain(void);
	int GetLocalDomainLevel(void);
	STRING_MAP& GetFullDomain(void);

private:
	std::string m_strParentDomain;
	std::string m_strLocalDomain;
	int m_nParentDomainLevel;
	int m_nLocalDomainLevel;
	STRING_MAP m_mapFullDomain;
};

//=======================================================================================
KBASE_API std::string GetUserDomain(const std::string& strUserID);
KBASE_API std::string GetUserIDWithDomain(const std::string& strUserID,const std::string& strDomain);

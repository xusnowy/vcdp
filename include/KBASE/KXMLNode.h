#pragma once

#include "KBASE/KBASE_Export.h"

#include <string>

class KXMLAccumulator;

typedef enum XMLNODE_TYPE
{
	XMLNODE_TYPE_ELEMENT,
	XMLNODE_TYPE_CDATA,
};

//---------------------------------------------------------------------------------------
// KXMLNode¿‡∂®“Â
class KBASE_API KXMLNode
{
public:
	KXMLNode(const std::string& xns, XMLNODE_TYPE type);
	virtual ~KXMLNode();

public:
	void SetXNS(const std::string& xns);
	std::string GetXNS();
	XMLNODE_TYPE GetType();

	virtual std::string XMLString() = 0;
	virtual void Accumulate(KXMLAccumulator& acc)= 0;

protected:
	std::string m_xns;
	XMLNODE_TYPE m_type;    
};

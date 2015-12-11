#pragma once

#include "KBASE/KBASE_Export.h"

//#ifdef WIN32
//#pragma warning (disable:4786)
//#pragma warning(disable:4267)	// disable C4267
//#endif

#include "KXMLNode.h"
#include "KXMLAccumulator.h"

//---------------------------------------------------------------------------------------
// KXMLCDATA
class KBASE_API KXMLCData : public KXMLNode
{
public:
	KXMLCData(const char* text, unsigned int textsz, bool escaped = false);
	void SetText(const char* text, unsigned int textsz, bool escaped = false);
	void AppendText(const char* text, unsigned int textsz, bool escaped = false);
	const std::string& GetText();
	std::string XMLString();
	void Accumulate(KXMLAccumulator& acc);

private:
	std::string m_text;
};



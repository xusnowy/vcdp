#pragma once

#include "KBASE/KBASE_Export.h"

#include <string>

class KXMLNode;

//---------------------------------------------------------------------------------------
// KXMLAccumulator¿‡∂®“Â
class KBASE_API KXMLAccumulator
{
public:
	KXMLAccumulator(std::string& s);
	void operator()(KXMLNode* n);
	void operator()(std::pair<const std::string, std::string> p);
	template <class T>	KXMLAccumulator& operator<<(T data)
	{
		m_result += data; return *this;
	}
private:
	std::string& m_result;
};

//---------------------------------------------------------------------------------------
// Utility routines
KBASE_API void XMLUnEscape(const char* src, unsigned int srcLen, std::string& dest, bool append = false);  
KBASE_API std::string XMLEscape(const std::string& src);
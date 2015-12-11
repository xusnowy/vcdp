#pragma once

#include "KBASE/KBASE_Export.h"

#include "KXMLElement.h"

#ifdef WIN32
#include "expat/expat.h"
#else
#include "expat.h"
#endif

//---------------------------------------------------------------------------------------
// KXMLElementStreamEvent�¼��ඨ��
class KBASE_API KXMLElementStreamEvent
{
public:
	virtual ~KXMLElementStreamEvent(){};
	virtual void OnXMLDocumentStart(KXMLElement* e)=0;
	virtual void OnXMLDocumentElement(KXMLElement* e)=0;
	virtual void OnXMLDocumentEnd() = 0;
};

//---------------------------------------------------------------------------------------
// KXMLElementStream�ඨ��
class KBASE_API KXMLElementStream
{
public:
	KXMLElementStream(KXMLElementStreamEvent& rXMLElementStreamEvent);
	virtual ~KXMLElementStream();

    void Push(const std::string& data);
	void Push(const char* data, int datasz);
	void Reset(void);
	bool ParseFile(const char* filename);

private:
	XML_Parser				m_pXMLParser;
	std::list<KXMLElement*> m_listXMLElement;
	KXMLElementStreamEvent& m_rXMLElementStreamEvent;
	bool					m_bXMLDocumentStarted;
	bool					m_bXMLDocumentEnded;

	void Clear(void);

	//�ص�����
	static void OnStartElement(void *userdata,const char *name,const char **attribs);
	static void OnEndElement(void* userdata,const char* name);
	static void OnCDATA(void* userdata,const char* cdata, int cdatasz);
};

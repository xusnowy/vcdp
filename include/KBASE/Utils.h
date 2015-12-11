/**********************************************************
 * Name: KUtils.h
 * Author: zhouxiaochuan@gmail.com
 * Date: 2007-03-15
 **********************************************************/

#pragma once

#include <string>
#include <algorithm>
#include <map>
#include <list>

#include "KBASE/KBASE_Export.h"

#include "atlenc.h"/*base64*/

#ifdef WIN32
#include <process.h>
typedef long pid_t;
#define getpid	_getpid
#define unlink	_unlink
#else
#include <unistd.h>
#endif

/* ����ָ�����(����int)�����ַ��� */
typedef std::map<int,std::string> STRING_MAP;
typedef std::map<std::string,std::string> STRING_MAP_EX;

/* �����Ƚ��ȳ�˳�򱣴��ַ��� */
typedef std::list<std::string> STRING_LIST;

/* �����ʼ������,�ڻ�ȡ���������֮ǰ���ô˺������г�ʼ�� */
KBASE_API void InitRandom(void);

/* ��ȡ�����
 * nNumber: �������Χ���ֵ */
KBASE_API int Random(int nNumber);

/* ��ȡ��ǰʱ��(����millisecond) */
KBASE_API unsigned long GetTimeStamp(void);

/* ��ȡ��ǰʱ��(΢��microsecond) */
KBASE_API unsigned long GetMicroTimeStamp(void);

/* ��ͣ(����):���������� */
KBASE_API void Pause(unsigned long ulMS);

/* BASE64���� */
KBASE_API void Base64Encode(const std::string& InBuffer,std::string& OutBuffer);

/* BASE64���� */
KBASE_API void Base64Decode(const std::string& InBuffer,std::string& OutBuffer);

/* �������ļ�����BASE64���� */
KBASE_API size_t Base64EncodeFromFile(const std::string& filename,std::string& encodedstr);

/* ���ַ���BASE64���뱣�浽�ļ��� */
KBASE_API void Base64DecodeToFile(const std::string& encodedstr,const std::string& filename);

/* �ַ�����дת�� */
KBASE_API std::string UPPERCASE(const std::string& source);

/* �ַ���Сдת�� */
KBASE_API std::string LOWERCASE(const std::string& source);

/* ����ַ���������пո� */
KBASE_API std::string TRIMLEFT(const std::string& source, const char* chars2remove);

/* ����ַ����ұ����пո� */
KBASE_API std::string TRIMRIGHT(const std::string& source, const char* chars2remove);

/* ����ַ����������пո� */
KBASE_API std::string TRIMSPACE(const std::string& source);

/* ����ת�� */
KBASE_API std::string LONG2STR(long value);
KBASE_API std::string ULONG2STR(unsigned long value);
KBASE_API std::string INT2STR(int value);
KBASE_API std::string UINT2STR(unsigned int value);
KBASE_API std::string SHORT2STR(short value);
KBASE_API std::string USHORT2STR(unsigned short value);
KBASE_API std::string BYTE2STR(unsigned char value);
KBASE_API std::string BOOL2STR(bool value);
KBASE_API std::string DOUBLE2STR(double value);

KBASE_API long STR2LONG(const std::string& value);
KBASE_API unsigned long STR2ULONG(const std::string& value);
KBASE_API int STR2INT(const std::string& value);
KBASE_API unsigned int STR2UINT(const std::string& value);
KBASE_API short STR2SHORT(const std::string& value);
KBASE_API unsigned short STR2USHORT(const std::string& value);
KBASE_API unsigned char STR2BYTE(const std::string& value);
KBASE_API bool STR2BOOL(const std::string& value);
KBASE_API double STR2DOUBLE(const std::string& value);

KBASE_API unsigned short BOOL2USHORT(bool value);
KBASE_API bool USHORT2BOOL(unsigned short value);

KBASE_API std::string ULONG2HEX(unsigned long value);
KBASE_API unsigned long HEX2ULONG(const std::string& value);

KBASE_API std::string NONULLSTR(const char* value);

/* �ַ����ָ� */
KBASE_API STRING_MAP StrSplit(const std::string& data,const std::string& token);
KBASE_API STRING_MAP_EX StrSplitEx(const std::string& data,const std::string& token);
KBASE_API bool URLSplit(const std::string& url,std::string& protocol,std::string& serveraddr,unsigned short& serverport,std::string& filepath);

/* ��ȡ�ļ���С */
KBASE_API unsigned long GetFileSize(const std::string& strFileFullPath);

/* ɾ���ļ� */
KBASE_API bool DeleteFile(const std::string& strFileFullPath);

/* ��ñ�����ID */
KBASE_API pid_t GetProcessID(void);

/* ѹ���ַ��� */
KBASE_API bool Compress(const char* pSourceData,int nSourceLen,char* pDestData,int& nDestLen);

/* ��ѹ�ַ��� */
KBASE_API bool UnCompress(const char* pSourceData,int nSourceLen,char* pDestData,int& nDestLen);

#ifdef WIN32
/********************************************************************
 * ��ͨ���ַ��������UTF8�ַ���
 ********************************************************************/
//KBASE_API std::string U2A(CString csUnicodeString);

/********************************************************************
 * ��UTF8�ַ��������ͨ���ַ���
 ********************************************************************/
//KBASE_API CString A2U(const std::string& strAnsiString);
#endif

/* ���IP������ nBitȡ32/16/12/8... */
KBASE_API unsigned long GetBitMask(unsigned int nBit);

/********************************************************************
 * Ȩ�������
 * Ȩ�����Գ����ͱ�ʾ,��������λ�趨ÿһλȨ��ֵ,1Ϊtrue,0Ϊfalse
 * Ȩ��λ��˳��ӵ�λ(1)����λ(20)��������.
 ********************************************************************/

/* ����Ȩ��λ
 * ulPrivilege:		����Ȩ����
 * ucBit:			Ȩ��λ(ȡֵ��Χ1-20)
 * bEnabled:		Ȩ��ֵ
 * <RETURN>:		����Ȩ�޺����Ȩ���� */
KBASE_API unsigned long SetPrivilege(unsigned long ulPrivilege,unsigned char ucBit,bool bEnabled);

/* ���Ȩ��λ
 * ulPrivilege:		Ȩ����
 * ucBit:			Ȩ��λ(ȡֵ��Χ1-20)
 * <RETURN>:		Ȩ��ֵ */
KBASE_API bool GetPrivilege(unsigned long ulPrivilege,unsigned char ucBit);

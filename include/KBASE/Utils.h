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

/* 按照指定序号(整形int)保存字符串 */
typedef std::map<int,std::string> STRING_MAP;
typedef std::map<std::string,std::string> STRING_MAP_EX;

/* 按照先进先出顺序保存字符串 */
typedef std::list<std::string> STRING_LIST;

/* 随机初始化函数,在获取所有随机数之前调用此函数进行初始化 */
KBASE_API void InitRandom(void);

/* 获取随机数
 * nNumber: 随机数范围最大值 */
KBASE_API int Random(int nNumber);

/* 获取当前时戳(毫秒millisecond) */
KBASE_API unsigned long GetTimeStamp(void);

/* 获取当前时戳(微秒microsecond) */
KBASE_API unsigned long GetMicroTimeStamp(void);

/* 暂停(毫秒):将阻塞程序 */
KBASE_API void Pause(unsigned long ulMS);

/* BASE64编码 */
KBASE_API void Base64Encode(const std::string& InBuffer,std::string& OutBuffer);

/* BASE64解码 */
KBASE_API void Base64Decode(const std::string& InBuffer,std::string& OutBuffer);

/* 将整个文件进行BASE64编码 */
KBASE_API size_t Base64EncodeFromFile(const std::string& filename,std::string& encodedstr);

/* 将字符串BASE64解码保存到文件中 */
KBASE_API void Base64DecodeToFile(const std::string& encodedstr,const std::string& filename);

/* 字符串大写转换 */
KBASE_API std::string UPPERCASE(const std::string& source);

/* 字符串小写转换 */
KBASE_API std::string LOWERCASE(const std::string& source);

/* 清除字符串左边所有空格 */
KBASE_API std::string TRIMLEFT(const std::string& source, const char* chars2remove);

/* 清除字符串右边所有空格 */
KBASE_API std::string TRIMRIGHT(const std::string& source, const char* chars2remove);

/* 清除字符串两边所有空格 */
KBASE_API std::string TRIMSPACE(const std::string& source);

/* 类型转换 */
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

/* 字符串分割 */
KBASE_API STRING_MAP StrSplit(const std::string& data,const std::string& token);
KBASE_API STRING_MAP_EX StrSplitEx(const std::string& data,const std::string& token);
KBASE_API bool URLSplit(const std::string& url,std::string& protocol,std::string& serveraddr,unsigned short& serverport,std::string& filepath);

/* 获取文件大小 */
KBASE_API unsigned long GetFileSize(const std::string& strFileFullPath);

/* 删除文件 */
KBASE_API bool DeleteFile(const std::string& strFileFullPath);

/* 获得本进程ID */
KBASE_API pid_t GetProcessID(void);

/* 压缩字符串 */
KBASE_API bool Compress(const char* pSourceData,int nSourceLen,char* pDestData,int& nDestLen);

/* 解压字符串 */
KBASE_API bool UnCompress(const char* pSourceData,int nSourceLen,char* pDestData,int& nDestLen);

#ifdef WIN32
/********************************************************************
 * 将通用字符串编码成UTF8字符串
 ********************************************************************/
//KBASE_API std::string U2A(CString csUnicodeString);

/********************************************************************
 * 将UTF8字符串解码成通用字符串
 ********************************************************************/
//KBASE_API CString A2U(const std::string& strAnsiString);
#endif

/* 获得IP的掩码 nBit取32/16/12/8... */
KBASE_API unsigned long GetBitMask(unsigned int nBit);

/********************************************************************
 * 权限码操作
 * 权限码以长整型表示,按二进制位设定每一位权限值,1为true,0为false
 * 权限位的顺序从低位(1)到高位(20)依次排列.
 ********************************************************************/

/* 设置权限位
 * ulPrivilege:		现有权限码
 * ucBit:			权限位(取值范围1-20)
 * bEnabled:		权限值
 * <RETURN>:		设置权限后的新权限码 */
KBASE_API unsigned long SetPrivilege(unsigned long ulPrivilege,unsigned char ucBit,bool bEnabled);

/* 获得权限位
 * ulPrivilege:		权限码
 * ucBit:			权限位(取值范围1-20)
 * <RETURN>:		权限值 */
KBASE_API bool GetPrivilege(unsigned long ulPrivilege,unsigned char ucBit);

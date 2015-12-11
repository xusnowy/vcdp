//IMXEC_SIP.h
#ifndef __IMXEC_SIP_H__
#define __IMXEC_SIP_H__

#include <IMXEC/IMXEC_Export.h>
#include <IMXEC/IMXEC_VideoSetting.h>
#include <IMXEC/IMXEC_AudioSetting.h>


/**
 * SIPЭ��
 * ��SIPЭ����صĻ������ܵķ�װ
 * �����ն˰󶨵�ַ��
 * ����SIP�û�/��ϵͳע�� -- �����·
 * �ж�SIP�û���ע������״̬
 * ����ý��RTP��ʼ�˿�
 * 
 */
class IMXEC_API IMXEC_SIP
{
public:
	IMXEC_SIP(void);
	virtual~IMXEC_SIP(void);
public:
	/******************************************************************************
	* AddVirtualLine
	*���������������·  --- ����SIP������ע��һ���û� --- ������IP���û�����˽���������·
	*���룺	cszUserID		-�û��ʺ�
			cszUserName		-�û�����
			cszPassword		-�û�����
			cszHost			-SIP���������
	*�������
	*����ֵ���ɹ�����>=0[line id]��ʧ�ܷ���-1
	*****************************************************************************/
	static int AddVirtualLine(const char*cszUserID,const char*cszUserName,const char*cszPassword,const char*cszSIPProxy);

	/******************************************************************************
	* RemoveVirtualLine
	*������ɾ��������·
	*���룺	nLineID			-��·��ʶ
	*�������
	*����ֵ����
	*****************************************************************************/
	static void RemoveVirtualLine(int nLineID);

	/******************************************************************************
	* SetCurrentVirtualLine
	*���������õ�ǰ����������·
	*���룺	nLineID			-��·��ʶ
	*�������
	*����ֵ����
	*****************************************************************************/
	static int SetCurrentVirtualLine(int nLineID);

	/******************************************************************************
	* GetCurrentVirtualLine
	*��������ȡ��ǰ����������·
	*���룺��
	*�������
	*����ֵ����·��ʶ
	*****************************************************************************/
	static int GetCurrentVirtualLine(void);

	/******************************************************************************
	* IsVirtualLineRegistrationSuccess
	*�������ж�ָ��SIP�û��Ƿ���ע��ɹ�
	*���룺	nLineID			-��·��ʶ
	*�������
	*����ֵ��1 -- ��ע�᣻0 -- δע��
	*****************************************************************************/
	static int IsVirtualLineRegistrationSuccess(int nLineID);

	/******************************************************************************
	* IsCurrentVirtualLineRegistrationSuccess
	*�������жϵ�ǰʹ���û��Ƿ���ע��ɹ�
	*���룺��
	*�������
	*����ֵ��1 -- ��ע�᣻0 -- δע��
	*****************************************************************************/
	static int IsCurrentVirtualLineRegistrationSuccess(void);

	static int IsVirtualLineRegistrationError(int nLineID);
	static int IsCurrentVirtualLineRegistrationError(void);
	static const char*GetVirtualLineRegistrationErrorCode(int nLineID);
	static const char*GetCurrentVirtualLineRegistrationErrorCode(void);


	/******************************************************************************
	* SetSIPListenPort
	*���������������˿�
	*���룺	nSIPListenPort			-�����˿�
	*�������
	*����ֵ���ɹ�����0��ʧ�ܷ���-1
	*****************************************************************************/
	static int SetSIPListenPort(unsigned short nSIPListenPort);

	/******************************************************************************
	* SetLocalIP
	*���������ñ���IP
	*���룺	cszLocalIP		-����IP
	*�������
	*����ֵ���ɹ�����0��ʧ�ܷ���-1
	*****************************************************************************/
	static int SetLocalIP(const char*cszLocalIP);

	/******************************************************************************
	* SetRTPBasePort
	*���������������˿�
	*���룺	nRTPBasePort			-RTP��ʼ�˿�
	*�������
	*����ֵ���ɹ�����0��ʧ�ܷ���-1
	*****************************************************************************/
	static int SetRTPBasePort(unsigned short nRTPBasePort);

	/******************************************************************************
	* SetAudioDevParam
	*����������������Ƶ�豸����
	*���룺 nAudioCodecID		-��Ƶ����
	*�������
	*����ֵ���ɹ�����0��ʧ�ܷ���-1
	*****************************************************************************/
	static int SetAudioDevParam(X_AUDIO_CODEC_ID nAudioCodecID);

	/******************************************************************************
	* SetMainVideoDevParam
	*����������������Ƶ�豸����
	*���룺 nDevID				-�豸��ʶ
			nFrameRate			-֡��
			nBitrate			-����
			nVideoCodecType		-��Ƶ����
			nVideoFormatType	-��Ƶ��ʽ
	*�������
	*����ֵ���ɹ�����0��ʧ�ܷ���-1
	*****************************************************************************/
	static int SetMainVideoDevParam(int nDevID,int nFrameRate,int nBitrate,VIDEC_CODEC_TYPE nVideoCodecType,VIDEO_FORMAT_TYPE nVideoFormatType);

	/******************************************************************************
	* Start
	*����������SIP����
	*���룺��
	*�������
	*����ֵ���ɹ�����0��ʧ�ܷ���-1
	*****************************************************************************/
	static int Start(void);

	/******************************************************************************
	* Stop
	*������ֹͣSIP����
	*���룺��
	*�������
	*����ֵ���ɹ�����0��ʧ�ܷ���-1
	*****************************************************************************/
	static int Stop(void);
};




#endif

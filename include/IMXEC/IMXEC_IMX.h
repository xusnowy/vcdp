//IMXEC_IMX.h
#ifndef __IMXEC_IMX_H__
#define __IMXEC_IMX_H__

#include <IMXEC/IMXEC_Export.h>
#include <IMXEC/IMXEC_VideoSetting.h>
#include <IMXEC/IMXEC_AudioSetting.h>

class IMXEC_API IMXEC_IMX
{
public:
	IMXEC_IMX(void);
	virtual~IMXEC_IMX(void);
public:
	/******************************************************************************
	* SetUserID
	*�����������û���ʶ
	*���룺 cszUserID		-�û���ʶ
	*�������
	*����ֵ���ɹ�����0��ʧ�ܷ���-1
	*****************************************************************************/
	static int SetUserID(const char*cszUserID);

	/******************************************************************************
	* SetUserName
	*�����������û�����
	*���룺 cszUserName		-�û�����
	*�������
	*����ֵ���ɹ�����0��ʧ�ܷ���-1
	*****************************************************************************/
	static int SetUserName(const char*cszUserName);

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

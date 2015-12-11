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
	*描述：设置用户标识
	*输入： cszUserID		-用户标识
	*输出：无
	*返回值：成功返回0，失败返回-1
	*****************************************************************************/
	static int SetUserID(const char*cszUserID);

	/******************************************************************************
	* SetUserName
	*描述：设置用户名称
	*输入： cszUserName		-用户名称
	*输出：无
	*返回值：成功返回0，失败返回-1
	*****************************************************************************/
	static int SetUserName(const char*cszUserName);

	/******************************************************************************
	* SetAudioDevParam
	*描述：设置主流视频设备参数
	*输入： nAudioCodecID		-音频编码
	*输出：无
	*返回值：成功返回0，失败返回-1
	*****************************************************************************/
	static int SetAudioDevParam(X_AUDIO_CODEC_ID nAudioCodecID);

	/******************************************************************************
	* SetMainVideoDevParam
	*描述：设置主流视频设备参数
	*输入： nDevID				-设备标识
			nFrameRate			-帧率
			nBitrate			-码流
			nVideoCodecType		-视频编码
			nVideoFormatType	-视频格式
	*输出：无
	*返回值：成功返回0，失败返回-1
	*****************************************************************************/
	static int SetMainVideoDevParam(int nDevID,int nFrameRate,int nBitrate,VIDEC_CODEC_TYPE nVideoCodecType,VIDEO_FORMAT_TYPE nVideoFormatType);

	/******************************************************************************
	* Start
	*描述：启动SIP服务
	*输入：无
	*输出：无
	*返回值：成功返回0，失败返回-1
	*****************************************************************************/
	static int Start(void);

	/******************************************************************************
	* Stop
	*描述：停止SIP服务
	*输入：无
	*输出：无
	*返回值：成功返回0，失败返回-1
	*****************************************************************************/
	static int Stop(void);
};

#endif

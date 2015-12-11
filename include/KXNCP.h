#pragma once

#define IDXS_SERVER_VERSION		"2.0.0.0.1128"
#define IDXS_PROTOCOL_VERSION		2000

//////////////////////////////////////////////////////////////////////////////////////
//									SYS												//
//////////////////////////////////////////////////////////////////////////////////////

#define IO_CONNECT_TYPE_CLIENT_SVC			100
#define IO_CONNECT_TYPE_CLIENT_NFS			103		//兼容老版本
#define IO_CONNECT_TYPE_CLIENT_MGW			104
#define IO_CONNECT_TYPE_CLIENT_VRS			105		//监控录像上传

#define IO_CONNECT_TYPE_MCU_ROUTER			200
#define IO_CONNECT_TYPE_NFS_ROUTER			201

#define SERVER_TYPE_MCU						300
#define SERVER_TYPE_MTS						301
#define SERVER_TYPE_MCU_MTS					302

#define IMS_AGENT_ID						400
#define MMS_AGENT_ID						401
#define MON_AGENT_ID						402
#define SMS_AGENT_ID						403
#define FAX_AGENT_ID						404
#define SIP_AGENT_ID						405

//---------------------------------------------------------
// 文件传输常量
#define MAX_FILE_PACKET			65536 + 64
#define MAX_FILE_DATA_PACKET	65536
#define MAX_CMD_PACKET			32768 * 3

//////////////////////////////////////////////////////////////////////////////////////
//									MMS												//
//////////////////////////////////////////////////////////////////////////////////////

// 权限
typedef enum _MMS_RIGHT
{
	MET_RIGHT_SPEACK	= 1,	// 发言
	MET_RIGHT_RECORD,			// 录像
	MET_RIGHT_TALK,				// 讨论
	MET_RIGHT_CONTROL,			// 控制
	MET_RIGHT_WHITE,			// 白板
	MET_RIGHT_FLOAT,			// 浮动
	MET_RIGHT_MET,				// 会议 /*特别处理*/
	MET_RIGHT_DESK,				// 桌面
	MET_RIGHT_PAPER,			// 小纸条
	MET_RIGHT_DOC,
};

// 列表
typedef enum _MMS_LIST
{
	MET_LIST_ROLOCUTOR	= 1,	// 发言
	MET_LIST_QUESTIONER,		// 提问
};

// 附件
typedef enum _MMS_ANNEX
{
	MET_TOPIC	= 1,	// 标题
	MET_BULL,			// 公告
};

//-------------------------------------
// 通道类型
typedef enum _MMS_CHLTYPE
{
	MMS_CHLTYPE_VID = 1,	// 视频通道
	MMS_CHLTYPE_AUD,		// 音频通道
	MMS_CHLTYPE_DOC,		// 文档通道
	MMS_CHLTYPE_CHT,		// 讨论通道
	MMS_CHLTYPE_WHB,		// 白板通道
	MMS_CHLTYPE_DTS,		// 文件传输通道
};

//-------------------------------------
// 通道结构
typedef struct _MMS_CHANNEL
{
	unsigned int	channeltype;
	unsigned long	channelid;
	_MMS_CHANNEL()
	{
		channeltype=0;
		channelid=0;
	};
}MMS_CHANNEL,*PMMS_CHANNEL;

#include <list>
typedef std::list<PMMS_CHANNEL> MMS_CHANNEL_LST;


//=======================================================================================
// 错误代码
//=======================================================================================
#define	ERR_NO							00000		//正确

//---------------------------------------------------------------------------------------
// 系统类或网络类错误代码
//---------------------------------------------------------------------------------------
#define	ERR_SYS_PROTOCOL				10000		//通讯协议版本不匹配
#define	ERR_SYS_UNKNOWN					10001		//未知错误
#define	ERR_SYS_COMMAND					10002		//协议命令错误
#define	ERR_SYS_DATABASE				10003		//数据库错误
#define	ERR_SYS_NETWORK					10004		//网络断开(网络通路断开)
#define	ERR_SYS_SERVERTYPE				10005		//服务器类型错误,登录到错误类型的服务器

//---------------------------------------------------------------------------------------
// 即时通讯类错误代码
//---------------------------------------------------------------------------------------
#define	ERR_IMS_PROTOCOL				20000		//通讯协议版本不匹配
#define	ERR_IMS_INVALIDACCOUNT			20001		//无效的账户(系统没有该账户ID)
#define	ERR_IMS_INVALIDPASSWORD			20002		//无效的密码
#define	ERR_IMS_DUPLICATELOGIN			20003		//该账户已经登录,不得重复登录
#define	ERR_IMS_REQUESTRELOGIN			20004		//服务器要求使用获得的新地址重新登录
#define	ERR_IMS_KICKOUT					20005		//被踢出(该账户在其它地方已登录,强制本地帐号退出)
#define ERR_IMS_MODULELIMIT				20006		//服务器功能限制(服务端即时通讯模块授权没有启用)
#define ERR_IMS_CONNECTLIMIT			20007		//连接服务器到达最大用户数限制
#define ERR_IMS_ACCOUNTLIMIT			20008		//用户登录到达最大用户帐号数限制
#define ERR_IMS_SERVER					20009		//用户帐号在该服务器上不存在或该服务器没有加载帐号验证模块
#define ERR_IMS_SERVERLIMIT				20010		//服务器地址限定,该用户不能在此服务器上登录

//---------------------------------------------------------------------------------------
// 会议通讯类错误代码
//---------------------------------------------------------------------------------------
#define ERR_MMS_PROTOCOL				30000		//通讯协议版本不匹配
#define	ERR_MMS_INVALIDPASSWORD			30001		//无效的会议密码
#define	ERR_MMS_ALREADYLOGIN			30002		//该账户已经进入会议
#define	ERR_MMS_WORKGROUPLIMITS			30003		//会议已经超过六人限制
#define	ERR_MMS_NOMCU					30004		//会议没有适当的MCU服务器
#define	ERR_MMS_OWNERLEAVED				30005		//会议所有者离开会议
#define	ERR_MMS_ROOMLOCKED				30006		//会议已经锁定
#define	ERR_MMS_INVALIDROOMTYPE			30007		//会议室类型不明确
#define	ERR_MMS_INVALIDMEMBERTYPE		30008		//登录者类型不明确
#define	ERR_MMS_LOSSINVALID				30009		//定损报案号不存在
#define	ERR_MMS_LOSSAGAIN				30010		//定损报案号已被其他人登记
#define	ERR_MMS_LOSSHAVEEND				30011		//定损报案号已经定损结束
#define ERR_MMS_MODULELIMIT				30012		//服务器功能限制(系统会议模块授权没有启用)
#define ERR_MMS_CONNECTLIMIT			30013		//系统到达最大会议成员数限制
#define ERR_MMS_HAVETV					30014		//电视墙设备号已存在
#define ERR_MMS_INVALIDTV				30015		//非有效的电视墙设备号
#define ERR_MMS_HAVETVMATRIX			30016		//电视墙矩阵设备号已存在
#define ERR_MMS_INVALIDTVMATRIX			30017		//非有效的电视墙矩阵设备号
#define ERR_MMS_SERVER					30018		//会议服务器断开连接
#define ERR_MMS_AUDITORLIMIT			30019		//会议旁听者最大数量限制

//---------------------------------------------------------------------------------------
// 短信类错误代码
//---------------------------------------------------------------------------------------
#define ERR_SMS_PROTOCOL				40000		//通讯协议版本不匹配
#define	ERR_SMS_GATEWAY					40001		//短信网关发送失败
#define	ERR_SMS_INVALIDSEARIALNO		40002		//序列号码为空或无效
#define	ERR_SMS_NETWORK					40003		//连接到短信网关发生网络故障
#define	ERR_SMS_OTHERS					40004		//连接到短信网关发生其他故障
#define	ERR_SMS_ENTRYLIMITS				40005		//手机号码为空或者超过1000个
#define	ERR_SMS_SPLITCHAR				40006		//手机号码分割符号不正确
#define	ERR_SMS_ERRORNUMBER				40007		//部分手机号码不正确，已删除，其余手机号码被发送
#define	ERR_SMS_CONTENTOVERFLOW			40008		//短信内容为空或超长(70个汉字)
#define	ERR_SMS_BILLING					40009		//短信网关计费失败
#define	ERR_SMS_UNKNOWN					40010		//未知错误
#define ERR_SMS_MODULELIMIT				40011		//服务器功能限制(系统短信模块授权没有启用)
#define ERR_SMS_INVALIDTYPE				40012		//短信类型未定义
#define ERR_SMS_EMPTYCODE				40013		//发送号或接收号为空

//---------------------------------------------------------------------------------------
// 监控类类错误代码
//---------------------------------------------------------------------------------------
#define ERR_MON_PROTOCOL				50000		//通讯协议版本不匹配
#define ERR_MON_REUSESERIAL				50001		//序列号已被其他帐户绑定
#define	ERR_MON_INVALIDACCOUNT			50002		//无效的监控设备(或网关)账户(系统没有该账户ID)
#define	ERR_MON_INVALIDPASSWORD			50003		//无效的密码
#define	ERR_MON_INVALIDSERIAL			50004		//无效的序列号
#define	ERR_MON_ALREADYLOGIN			50005		//已经登录
#define ERR_MON_INVALIDTYPE				50006		//非法的终端类型
#define ERR_MON_MODULELIMIT				50007		//服务器功能限制(系统监控模块授权没有启用)
#define ERR_MON_CONNECTLIMIT			50008		//系统到达最大通道数限制

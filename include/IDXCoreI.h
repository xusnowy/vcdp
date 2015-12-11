/******************************************************************
@file   IDXCore.h
@brief
	提供了终端会议功能的主入口和功能整体封装；
	终端同时只能处于一个会议中，如果需要建立多个会议，那么该用户需要从之前的会议临时离开，召开新的会议；

@note     接口使用说明：

   序号   |                    接口                  |                    描述                        |    是否必须
------------------------------------------------------------------------------------------------------------------

@writor   wangzwa
@version  1.0
@date     2015
@history
2015.11.01	wangzwa		v1.0
******************************************************************/

#ifndef _IDXCOREI_H
#define _IDXCOREI_H

#include <vector>
#include <string>

////////////////////////////////////////
#ifdef IDXCORE_EXPORT
#define IDXCORE_API _declspec(dllexport)
#elif IDXCORE_DLL
#define IDXCORE_API _declspec(dllimport)
#else
#define IDXCORE_API
#endif

////////////////////////////////////////////////////////////////
#if 1 // 2015.11.5 Add by wangzw For Interface of Main Conf

class IMainCtrl
{
public:

};

#endif // 2015
////////////////////////////////////////////////////////////////

#define LEN_MEET_NAME			20		// 会议名称长度
#define LEN_MEET_DESC			100		// 会议描述长度
#define LEN_MEET_PASSWORD		20		// 会议密码长度
#define DROP_DEV_LIST_TO_VIEW	0x12

// 定义了视频显示区域的分屏模板
#include "WinTempletDefine.h"

#if 0 // 2015.11.21
// 权限位命令
typedef enum PRIVILEGE_BIT
{
	PRIVILEGE_BIT_SIP		= 1,	//SIP呼叫
	PRIVILEGE_BIT_SMS		= 2,	//SMS短信
	PRIVILEGE_BIT_MMS		= 3,	//会议管理(WEB)
	PRIVILEGE_BIT_MON		= 4,	//监控点播(WEB)
	PRIVILEGE_BIT_TEM		= 5,	//模板设置
	PRIVILEGE_BIT_FAX		= 6,	//收发传真
	PRIVILEGE_BIT_MSG		= 7,	//机构广播消息
	PRIVILEGE_BIT_BAD		= 8,	//发布公告
	PRIVILEGE_BIT_MAP		= 9,	//地图编辑
	PRIVILEGE_BIT_MAT		= 10,	//矩阵控制
	PRIVILEGE_BIT_LOS		= 11,	//定损权限
	PRIVILEGE_BIT_INFO		= 14,	//修改个人设置
	PRIVILEGE_BIT_ORG		= 17,	//显示机构权限;
};
#endif // 

enum
{
	CON_AFFICHE = 0,				//会议公告
	CON_TITLE,						//会议标题
	CON_CALLING,					//会议点名
	LOCK_CON,						//锁定会议
	SOUND_BESTIR,					//语音激励
	CON_SYNC,						//同步模式
	CON_DESYNC,						//独立模式
	CON_INDEPENDENCE,				//主控模式
	CON_LABIAL_SOUND,				//唇音同步
	LAND_TIMER_TAXIS,				//登录时间排序
	NAME_TAXIS,						//名称排序
	TYPE_TAXIS,						//人员类型排序
	SET_CON_AFFICHE,				//设置公告
	SET_CON_TITLE,					//设置标题
	SET_CON_HAND,					//设置会议举手
	ALLOW_DISCUSS,					//允许讨论
	SCREEN_CONTROL,					//允许申请屏幕控制
	NOTE_INFORM,					//短信通知
	CON_IN_PHASE,					//会议同步
	IN_PHASE_CHOOSE_1,				//选 1 屏
	IN_PHASE_CHOOSE_2,				//选 2 屏
	IN_PHASE_CHOOSE_3,				//选 3 屏
	IN_PHASE_CHOOSE_4,				//选 4 屏
	CONF_KINESCOPE,					//会议录像
	CONF_AVDIO,						//视频
	CONF_DOC,						//文档
	FULL_SCREEN,					//全屏
	SMALL_SCRIP,					//小纸条
	SHOWVIDEOTITLE,					//视频标题
};

//回调
enum
{
	REV_ALLOW_KINESCOPY = 0,		//允许会议录像
	REV_ALLOW_YT_CONTROL,			//允许控制云台
	REV_ALLOW_SPEAK,				//允许申请发言
	REV_ALLOW_WB,					//允许电子白板
	REV_ALLOW_CONTROL,				//允许监控人员控制
	REC_CON_LABIAL_SOUND,			//唇音同步
	REV_ALLOW_FLOOT,				//允许改变浮动窗口
	REV_CON_AFFICHE,				//会议公告
	REV_CON_TITLE,					//会议标题
	REV_CON_HAND,					//会议举手
	REV_CON_CALLING,				//会议点名
	REV_LOCK_CON,					//锁定会议
	REV_SOUND_BESTIR,				//语音激励
	REV_NAME_TAXIS,					//名称排序
	REV_LAND_TIMER_TAXIS,			//登录时间排序
	REV_TYPE_TAXIS,					//人员类型排序
	REV_CON_SYNC,					//同步模式
	REV_CON_DESYNC,					//独立模式
	REV_CON_INDEPENDENCE,			//主控模式
	REV_IN_PHASE_CHOOSE_1,			//选 1 屏
	REV_IN_PHASE_CHOOSE_2,			//选 2 屏
	REV_IN_PHASE_CHOOSE_3,			//选 3 屏
	REV_IN_PHASE_CHOOSE_4,			//选 4 屏
	REV_ALLOW_DISCUSS,				//允许讨论
	REV_SCREEN_CONTROL,				//允许申请屏幕控制
	REV_CONF_KINESCOPE,				//会议录像
	REV_CONF_AVDIO,					//视频
	REV_CONF_DOC,					//文档
	REV_FULL_SCREEN,				//全屏
	REV_SMALL_SCRIP,				//小纸条
	REV_YT_CTRL,					//云台控制
	REV_H323_CTRL,					//H323控制
	REV_SHOW_AVINFO,				//视频信息
};

enum
{
	STREAM_TYPE_AUTO = 0,
	STREAM_TYPE_HIGH,
	STREAM_TYPE_MID,
	STREAM_TYPE_LOW,
};

#define TERM_TYPE_PC		"PC"		//PC版本
#define TERM_TYPE_TERMINAL	"Terminal"	//终端版本

#include "KMMSDefine.h"
#include "StructDefine.h"

// IDXCore通知
// 注：由上层应用继承实现，由IDXCore调用，用于向上层通知
class IIDXCoreNotify
{
public:
	
	// 向上层通知当前会议状态
	// nStatus：当前状态 //0:无，1：在会议，2：在AView
	// 注：上层可据此状态执行 -- 界面显示状态的更新；状态值保存；
	virtual void SetCurRoomStatus(int nStatus)=0;
	// 得到当前会议状态【从上层应用获取】
	// 返回值： 0  无， 1 在会议，2 在AView
	virtual int GetCurRoomStatus(void)=0;

	// 获得本地成员ID
	virtual std::string GetLocalMemberID(void)=0;
	
	// 获得本地用户名称
	virtual std::string GetLocalUserName(void)=0;

	// 根据用户ID获取用户名称
	// 注：上层应用维护的通讯录中检索
	virtual std::string GetUserName(const std::string& strMemberID) = 0;

	// 向上层应用传递提示信息
	// 这些提示信息一般需要上层应用显示给用户
	// 【具体的显示呈现方式由上层应用决定】
	virtual void OnPromptMessage(const std::string& strMsg)=0;

	// 2015
	// 收到视频转发
	// strOriginUser：发起者用户ID
	// strResourceID：视频资源ID
	// bHasPrivilege：是否拥有控制权
	virtual void OnForwardMonVideoIncoming(const std::string& strOriginUser, const std::string& strResourceID, bool bHasPrivilege) = 0;

	// 撤销视频转发
	// strOriginUser：发起者用户ID
	// strResourceID：视频资源ID
	virtual void OnForwardMonVideoCancel(const std::string& strOriginUser, const std::string& strResourceID) = 0;

	// 收到视频请求
	// strRequestUser：请求者用户ID
	// strResourceID：视频资源ID
	// bHasPrivilege：是否请求控制权
	virtual void OnRequestMonVideoIncoming(const std::string& strRequestUser, const std::string& strResourceID, bool bHasPrivilege) = 0;
	// 

	// 通知：邀请加入会议
	// strDomain：域名
	// 注：上层应用应决定是否接受请求，如果接收请求，则调用 IDXCore . AcceptInvitation；否则拒绝，则调用 IDXCore . RejectInvitation
	virtual void OnInviteIntoMeeting(const std::string& strDomain,const std::string& strRoomID,const std::string& strRoomName,const std::string& strInviterNodeID,const std::string& strInviterID, const std::string& strPassword, const std::string& strInviterName)=0;
	// 通知：被邀请者拒绝了邀请
	// 注：上层应用只需要显示相应提示即可
	virtual void OnRejectInvitation(const std::string& inviteeid,const std::string& strinviteName)=0;

	// 通知：向上层应用通知“临时会议请求响应”，携带系统为该临时会议分配的会议ID
	// 注：请参考IDXCoreTest的实现
	// nCode    - 0		：无错；
	//            其他值	：错误码，
	virtual void OnAppTempMetRsp(unsigned long ulRoomID, unsigned long ulGroupID, int nCode = 0) = 0;

	// 通知：进入会议;【errcode!=0时，加入会议存在错误】
	// 注：请参考IDXCoreTest的实现
	virtual void OnEnterRoom(unsigned int errcode, const std::string& errText = "", const std::string& szMetName = "", const std::string& szMetID = "") = 0;

	// 通知：从会议退出
	// 注：上层应用只需考虑界面状态更新即可
	virtual void OnExitRoom(void)=0;

	// 通知：成员离开会议，memberid成员ID，membername成员名称
	// 注：上层应用只需要考虑界面的呈现即可
	virtual void OnMemberOffline(const std::string& memberid,const std::string& membername)=0;

	// 通知：本用户被踢出会议
	// 注：上层应用只需要考虑界面的呈现即可
	virtual void OnKickOut(void)=0;
	// 

	// InviteUserIntoMeeting的响应回调函数
	// strSessionID：发出InviteUserIntoMeeting时返回的SessionID
	// nCode：错误码  0：无错误；其他值：错误码【注：错误码待定】
	virtual void OnRspInviteUserIntoMeeting(const std::string& strSessionID, int nCode) = 0;

	// 通知：用户memberid进入会议
	// 注：上层应用只需要考虑界面的呈现即可
	virtual void OnMemberInMeeting( const std::string& memberid ) = 0;

	// 通知：用户memberid离开会议
	// 注：上层应用只需要考虑界面的呈现即可
	virtual void OnMemberOutMeeting( const std::string& memberid ) = 0;

	// 向上层应用通知：会议中当前的成员列表
	// metRoomItem：会议信息
	// vecOldMember：中存放会议中当前的成员列表
	// hide_members：暂无用
	// 注：该函数目前无用
	virtual void MeetingMember(MMS_ROOM metRoomItem, std::vector<std::string> vecOldMember, const std::vector<std::string> &hide_members, const std::string strGroupId="") = 0;
	// 

	// 通知：会议室已满员
	virtual void OnRoomIsFull() = 0;

	// 请求：请求退出会议室
	// 注：上层应用需要调用相应接口，结束会议【如调用IDXCore::ExitMeeting等】
	virtual void OnRequestExitMeeting(bool bKickOut = false)=0;

	// 通知：音视频的状态【广播/未广播】
	// 注：上层应用只需要考虑界面呈现即可
	virtual void OnUserAVStatus(UINT nType = 0, int nFlag = 0) = 0;

	// 消息框
	// 将消息传递给上层应用，由上层应用提供消息显示机制
	// groupId：组ID
	// sFromId：用户ID，消息来源【取自于网络消息的 from_id 字段】
	// sCmdType：消息所携带的命令【对上层应用而言，仅仅是用于提示】
	// 注：上层应用只需要考虑界面呈现即可
	virtual void OnMeetingMemberMsg(string groupId,string sFromId,string sCmdType,string roomid ="") = 0;

	// 要求上层应用处理全屏
	// 注：上层应用界面相关元素，在全屏下的显式处理等等；包括IDXCore中会议视频窗口的大小/位置等，都是要求由上层应用来处理的
	virtual void SetFullTemplate(bool bFull) = 0;

	// 判断当前是否为全屏状态
	virtual bool IsFullScreen() = 0;

	virtual void OnXSSEResizeWndNotify(int nTMID, int nWndIndex, bool bEnabled) = 0;

	// 视频监控相关  // 2015.12.4
	virtual MapMonGroupItem GetMonGroupItemMap(void)=0;	
	virtual MapMonChannelItem GetMonChannelItemMap(void)=0;
	virtual GROUPINFO*	GetMonGroupItem(const std::string& groupid)=0;
	virtual CHANNELINFO* GetMonChannelItem(const std::string& channelid) = 0;
	// end // 2015.12.4

	// 通知：分屏模板控制器是否【bIsOpen】已打开
	// 注：上层应用只需考虑界面上对状态的呈现即可
	virtual void OnTMCtrlNotify(bool bIsOpen)=0;

	// 通知：码流类型设置后，向上层应用通知所设置的类型iType
	// 注：上层应用只需考虑界面上状态的呈现即可
	virtual void ShowStreamType(int iType) = 0;

	// 帧率控制设置后，向上层应用通知所设置的模式
	// 注：帧率控制模式取值来自于NETEC.h中定义FRAME_RATE_CONTROL_MODE
	// 注：上层应用只需考虑界面上状态的呈现即可
	virtual void ShowFrameRateControlMode(int nMode) = 0;
};

#define SETISBEGGINNER_CHAT			1
#define SETISBEGGINNER_WB			2
#define SETISBEGGINNER_BCDESKTOP	3
#define SETISBEGGINNER_BCVEDIO		4
#define SETISBEGGINNER_FILESEND     5

// IDXCore库的接口定义
// IDXCore对象是整个 终端侧会议功能的主入口和封装
// 上层应用通过调用该接口，实现了对于登录会议、会议内功能、退出会议等
// 
class IIDXCore
{
public:
#if 1 // 2015.11.4
	virtual void OnTest() = 0;
#endif //

	// 释放IDXCore对象，销毁内部所有对象，结束IDXCore
	virtual void ReleaseConnections(void)=0;

	// 请求获取会议列表
	virtual void EnterMeetingMode(void)=0;

	// 向IDXCore设置主控对象【上层应用】
	virtual void SetMainWnd(IMainCtrl *pMainWnd) = 0;

	// 请求创建临时会议
	virtual int RequestCallTempMet() = 0;

	// 命令所有终端退出会议
	virtual void AllMemberExitMeeting(void) = 0;

	// 本终端退出会议
	virtual void ExitMeeting(bool bneedrefresh = true)=0;

	// 向主席请求将某用户加入会议
	// 注：需要主席的同意
	virtual void RequestIntoMeeting(const std::string& userid, const std::string nodeid, const std::string& username) = 0;

	// 向某用户转发视频监控的视频
	// strResourceID：视频监控资源ID
	// bHasPrivilege：是否拥有控制权
	virtual void ForwardMonVideo(const std::string& strResourceID, const std::string& strDstUserID, bool bHasPrivilege, std::string& strSessionID) = 0;

	// 撤销视频转发
	// strOriginUser：发起者用户ID
	// strResourceID：视频资源ID
	// strSessionID：原来发起该请求时的会话ID
	virtual void CancelForwardMonVideo(const std::string& strResourceID, const std::string& strSessionID) = 0;

	// 向用户请求监控视频
	// strAdminUser：该监控的管理者用户ID
	// strResourceID：视频资源ID
	// bHasPrivilege：是否请求控制权
	virtual void RequestMonVideo(const std::string& stAdminUser, const std::string& strResourceID, bool bHasPrivilege) = 0;

	// 邀请用户【userid】进入会议
	// bPresider：该用户是否作为主席
	// strSessionID    - [out] 返回本次请求的会话ID  -- 主要用于在
	virtual void InviteUserIntoMeeting(const std::string& userid, std::string& strSessionID, bool bPresider = false, bool bTempMet = false)=0;

	// 接受邀请，入会
	// 注：用户选择“接受邀请”时，上层应用调用该函数，接收邀请，尝试加入会议
	virtual void AcceptInvitation(std::string strDomain,std::string roomid,std::string password)=0;

	// 拒绝邀请
	// 注：用户选择“拒绝邀请”时，上层应用调用该函数，拒绝邀请
	virtual void RejectInvitation(const std::string& strDomain,const std::string& strRoomID,const std::string& strInviterNodeID) = 0;


	// 显式/隐藏本地视频
	// 注：如果显式，则是以浮动窗口方式
	virtual void ShowMeetingLocalAV(bool bShow) = 0;

	// 打开本地视频
	// 注：将自动安排窗口位置
	virtual int OpenLocalVideo() = 0;
	
	// 关闭本地视频
	virtual void CloseLocalVideo() = 0;

	// 打开某用户【memberid】的视频
	virtual int OpenUserVideo(const std::string memberid) = 0;
	// 打开某用户【memberid】的音频
	virtual int OpenUserAudio(const std::string memberid) = 0;
	// 打开某用户【memberid】的音视频
	virtual int OpenUserAV(const std::string memberid) = 0;

	// 关闭某用户【memberid】的视频
	virtual void CloseUserVideo(const std::string memberid) = 0;
	// 关闭某用户【memberid】的音频
	virtual void CloseUserAudio(const std::string memberid) = 0;
	// 关闭某用户【memberid】的音视频
	virtual void CloseUserAV(const std::string memberid) = 0;

	// 关闭指定屏【nScreenID】上所有用户视频
	virtual void CloseAllVideo(int nScreenID)=0;

	// 广播某用户视频
	virtual int BroadcastUserVideo(const std::string& strMemberID/*被广播人ID*/, int usScreenID/*屏幕ID*/, int usSubwinID/*子窗口ID*/ ) = 0;
	virtual int BroadcastUserAudio(const std::string& strMemberID) = 0;
	virtual int BroadcastUserAV(const std::string& strMemberID/*被广播人ID*/, int usScreenID/*屏幕ID*/, int usSubwinID/*子窗口ID*/) = 0;

	virtual int StopBroadcastUserVideo(const std::string& strMemberID) = 0;
	virtual int StopBroadcastUserAudio(const std::string& strMemberID) = 0;
	virtual int StopBroadcastUserAV(const std::string& strMemberID) = 0;

	// 判断自己是否为当前会议主席
	virtual bool IsMyHost()=0;

	//只判断与会者是否为发言者，如果当前是主持人，返回FALSE
	virtual bool IsMySpeaker() = 0;
	//

	// 判断本人是否为旁听者
	virtual bool IsMyAuditor()=0; //旁听者

	// 请求进入会议【由ulRoomID标识的会议】
	// 参数
	// ulRoomID       -- 【IN】会议ID
	// strUserID      -- 【IN】用户ID，如8010001
	// strUserName    -- 【IN】用户显示名，可为""
	virtual bool StartEnterMeetingRoom(unsigned long ulRoomID, const std::string& strUserID, const std::string& strUserName)=0;

	// 判断是否在会议中
	virtual bool IsInMeeting() = 0;

	// 申请发言
    virtual void RequestSpeak(bool cancel_request = false) = 0;
	// 申请提问
    virtual void RequestQuestion(bool cancel_request = false) = 0;
	
	//0x01:拒绝所有邀请
	//0x02:弹出邀请提示信息
	//0x04:自动进入
	//0x10:如果在会议中，将自动退出会议进入被邀请的会议

	// 同意发言请求
	virtual void AcceptRequestSpeaker(string roomid,string groupId,string sToId,bool bAnswer = true)=0;
	// 拒绝发言请求
	virtual void RejectRequestSpeaker(string roomid,string groupId,string sToId)=0;

	// 同意提问请求
	virtual void AcceptRequestQuiz(string roomid,string groupId,string sToId)=0;
	// 拒绝提问请求
	virtual void RejectRequestQuiz(string roomid,string groupId,string sToId)=0;

	// 得到本地输出视频流码率大小
	// 单位kbps
	virtual long GetVideoOutBitrate() = 0;

	// 得到本地接收视频流码率大小
	// 单位kbps
	virtual long GetVideoInBitrate() = 0;

    //权限控制
	// 设置某权限
    virtual void SetPrivilegeCode(unsigned long nCode) = 0;
	// 获取权限码
    virtual unsigned long GetPrivilegeCode() = 0;
	// 判断某权限是否启用
    virtual bool IsEnabledPrivilege( unsigned long nCode ) = 0;

	// 根据会议成员ID，得到会议成员名称
	virtual std::string GetMemberName(const std::string& memberid)=0;	

	// 2015.12.4 TTT 视频监控相关
	virtual void OnGetGroupInfoEnd()=0;
	virtual void OnChannelInfoEnd()=0;
	virtual void OnChannelInfo(const CHANNELINFO& item)=0;
	virtual void OnUpdateDevName(const std::string& strDevID,const std::string& strName, unsigned long ulGroupID)=0;
	virtual void OnUpdateChannelName(const std::string& strChannelID,const std::string& strName, unsigned long ulGroupID)=0;
	// end TTT
	//码流选择
	// ！！！ 后续需要将码流定义说明在此
	virtual void SetStreamType(int iType) = 0;	//iType为-1时，从配置文件读取来设置

	// 码率控制模式
	// ！！！ 后续需要将码率控制模式说明在此
	virtual void SetFrameRateControlMode(int nMode) = 0;	//nMode为-1时，从配置文件读取来设置

	// 当更换了MCU时，设置给IDXCore
	virtual void SetMCUItem(MMS_MCU* pMCU) = 0;

	// 启动本地录制
	// 将指定的窗口的视频录制下来，保存到本地
	virtual int StartLocalRecord()=0;

	// 停止本地录制
	virtual void StopLocalRecord()=0;

	// 委派临时主席
	// strMemberID: 用户ID
	// bTake: true -- 委派；fale -- 撤销
	virtual int AppointTempPresider(const std::string& strMemberID, bool bTake) = 0;

	// 获得当前活动模板ID
	virtual unsigned long GetActiveTM() = 0;

	// 调整视频窗口模板区的大小
	virtual void ResizeMainHPTM(/*CWnd**/HWND pWnd, int x, int y, int cx, int cy, bool bShow) = 0;

	// 调整
	virtual void ResizeDlgLocalVideoMgr(/*CWnd**/HWND hWnd, int x, int y, int cx, int cy, bool bShow) = 0;

	// 设置视频窗口分屏模板类型
	// 注：如果为同步会议，则所有与会成员的窗口分屏模板将统一改变
	virtual void ChangeTMType(int nType, int nSubType, unsigned long ulScreenIndex) = 0;

	// 显示/隐藏会议主窗口
	virtual void OnShowMainConferenceWnd(bool bShow) = 0;

	// 得到主显示屏大小
	virtual RECT GetPrimaryScreenRect() const = 0;

	// 指定屏【多屏】是否可见
	virtual BOOL IsScreenRectVisible(int nIndex) = 0;
};

// 创建 IIDXCore 对象，该对象为IDXCore库对外的入口
// rNotify：回调/通知类对象引用
// pWnd：父窗口对象
IDXCORE_API IIDXCore* CreateIDXCore(IIDXCoreNotify& rNotify, /*CWnd**/ HWND pWnd);

#endif
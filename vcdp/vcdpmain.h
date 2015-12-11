#ifndef VCDPMAIN_H
#define VCDPMAIN_H
#include "NETEC_Node.h"
#include "NETEC_Setting.h"
#include "NETEC_Core.h"
#include <AUDEC/AUDEC_Engine.h>
#include <VIDEC/VIDEC.h>

#include "KSYSClient.h"
#include "IDXCoreI.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTreeWidget>
#include <QDockWidget>;
#include <QTabWidget>
#include <QToolButton>
#include "ui_vcdpmain.h"
#include "vcdplogin.h"
#include "vcdpusertab.h"
#pragma execution_character_set("utf-8")
class vcdpMain : public QMainWindow,public KSYSSessionEvent, public KIMSSessionEvent, public IIDXCoreNotify, public IMainCtrl

{
	Q_OBJECT

public:
	vcdpMain(QWidget *parent = 0);
	~vcdpMain();

	void DoServerConnect(const std::string& strServerAddr, unsigned short usServerPort, const std::string& strUserID, const std::string& strPassword, const std::string& strStatus);
	void DoServerDisconnect(void);
	void InitToolBar();//初始化工具栏
	void InitLeftUserTreeView();//初始化用户树
	void InitMainView();//初始化主视图
public:
	QToolButton *q_HideView;//隐藏按钮
	QToolButton *q_UserMember;//用户按键区
	QToolButton *q_VedioDisplay;//视频区
	QToolButton *q_GisDisplay;//GIS
	QToolButton *q_ConifgDisply;//配置文件
	QTreeView *q_UserTreeView;
	QDockWidget *q_DockUserView;
protected:
	VcdpLogin *m_LoginUi;//用户登录
	VcdpUserTab *m_TabWidget;//用户按键区
	std::string	m_strServerAddr;//服务器IP
	unsigned short m_usServerPort;//服务器端口
	std::string m_strUserID;//用户ID
	std::string m_strPassword;//用户密码
	std::string m_strStatus;//登录状态
private slots:
	void OnClickTempMetBtn();//创建临时会场
	void OnClickLocalVedio();//打开本地视频
	void OnClickUserMenber();//用户按键区
	void OnClickVedioDisplay();//显示视频
	void OnClickHideView();//隐藏树形控件
	void OnCloseDockUserView(bool isOk);//浮动属性隐藏
private:
	bool m_bUserTreeView;//用户树形显示区域
public:

	//-----------------------------------------------------
	// KSYSSessionEvent
	//-----------------------------------------------------
	virtual void OnServerConnecting(void);
	virtual void OnServerReconnected(void);
	virtual void OnServerBusy(void);
	virtual void OnServerFailed(void);
	virtual void OnServerDisconnected(unsigned int nErrCode);
	virtual void OnServerConnected(void);
	virtual void OnServerListStart(void);
	virtual void OnServerList(const std::string& strMCUID, const std::string& strMCUType,
		unsigned long ulConnections, const std::string& strBandWidth, unsigned long ulActivity,
		const std::string& strIPAddr, unsigned short usIPPort, const std::string& strIPName);
	virtual void OnServerListEnd(void);
	virtual void OnServerRealTime(const std::string& strServerTime){};
	virtual void OnClientVersion(const std::string& strProduct, const std::string& strVersion, bool bForce){};

	//-----------------------------------------------------
	// KIMSSessionEvent
	//-----------------------------------------------------
	virtual void OnLogin(int nErrCode, const std::string& strModuleString);
	virtual void OnLogout(int nErrCode);
	virtual void OnAllUserCount(unsigned long ulCount){};
	virtual void OnOnlineUserCount(unsigned long ulCount){};
	virtual void OnMyName(const std::string& strUserName){};
	virtual void OnMyInfo(const IMS_CONTACT_ITEM& ui){};
	virtual void OnMyPriv(unsigned long ulPrivCode){};
	virtual void OnImage(const std::string& strUserID, const std::string& strImgType, const std::string& strImgData){};
	virtual void OnStatus(const std::string& strUserID, const std::string& strStatus, bool bFirst, const std::string& strNodeID, const std::string& strNatAddr, const std::string& strLocalAddr, unsigned short usLocalPort){};

	virtual void OnGroupItem(const std::string& strGroup, unsigned int nIndex){};
	virtual void OnGroupItemEnd(void){};
	virtual void OnGroupInsert(const std::string& strGroup, unsigned int nIndex){};
	virtual void OnGroupUpdateName(const std::string& strOldGroup, const std::string& strNewGroup){};
	virtual void OnGroupUpdateIndex(const std::string& strGroup, unsigned int nIndex){};
	virtual void OnGroupDelete(const std::string& strGroup){};

	virtual void OnFriendItem(const IMS_CONTACT_ITEM& item){};
	virtual void OnFriendItemEnd(void){};
	virtual void OnFriendInfo(const std::string& strFriendID){};
	virtual void OnFriendApply(const std::string& strFriendID){};
	virtual void OnFriendApplyError(const std::string& strFriendID){};
	virtual void OnFriendAdmit(const std::string& strFriendID){};
	virtual void OnFriendUpdateGroup(const std::string& strFriendID, const std::string& strGroup){};
	virtual void OnFriendDelete(const std::string& strFriendID){};
	virtual void OnFriendSearch(const IMS_CONTACT_ITEM& item){};

	virtual void OnOrgListStart(void){};
	virtual void OnOrgItem(const std::string& strOrgID, const std::string& strOrgName){};
	virtual void OnOrgItemEnd(void){};
	virtual void OnOrgDepartItem(const std::string& strOrgID, const std::string& strDepartID, const std::string& strDepartName, int nLevelID, const std::string& strUpgradeID, int nOrderID){};
	virtual void OnOrgDepartItemEnd(void){};
	virtual void OnOrgDepartUserItem(const std::string& strOrgID, const std::string& strDepartID, const IMS_CONTACT_ITEM& item, int nOrderID){};
	virtual void OnOrgDepartUserItemEnd(void){};
	virtual void OnOrgDeleteItem(const std::string& strOrgID, const std::string& strDepartID, const std::string& strUserID){};
	virtual void OnOrgDeleteItemEnd(void){};
	virtual void OnOrgListEnd(const std::string& strUpdateTime){};

	virtual void OnOnlineMessage(const std::string& strUserID, const std::string& strUserName, const std::string& strNodeID, const XMSG& xmsg){};
	virtual void OnOfflineMessage(const std::string& strUserID, const XMSG& xmsg){};
	virtual void OnSystemMessage(const std::string& strAdminName, const XMSG& xmsg){};
	virtual void OnSystemMessageEnd(void){};
	virtual void OnOrgMessage(const std::string& strOrgID, const std::string& strOrgName,
		const std::string& strDepartID, const std::string& strDepartName,
		const std::string& strUserID, const std::string& strUserName, const XMSG& xmsg){};
	virtual void OnUserData(KCmdUserDataPacket& packet){};
	virtual void OnWEBServer(const std::string& strHost, unsigned short usPort){};
	virtual void OnPBXServer(const std::string& strHost){};
	virtual void OnFAXServer(const std::string& strHost, unsigned short usPort){};
	virtual void OnGetURLItem(const std::string& strName, const std::string& strURL){};
	virtual void OnGetURLListEnd(){};
	virtual void OnGetFAXCount(unsigned int nCount){};
	virtual void OnMapInfo(const std::string& strGroupID, const std::string& strMapMD5){};
	virtual void OnBzIDInfo(const std::string& strGroupID, MAP_BZ_LST listMAPBZ){};
	virtual void OnMonUpdateTime(const std::string& strUpdateTime){};
	virtual void OnGroupInfo(const MONGROUP& item){};
	virtual void OnChannelInfo(const MONCHANNEL& item){};
	virtual void OnGetGroupInfoEnd(){};
	virtual void OnChannelInfoEnd(){};
	virtual void OnMonAlert(const std::string& strChannelID, unsigned short usType, unsigned short usSubtype){};
	virtual void OnDEVAddMyGroup(const std::string& strTmpGrpID, std::string& strAdminID, std::string& strTmpGrpName){};
	virtual void OnDEVDelMyGroup(const std::string& strTmpGrpID, std::string& strAdminID, std::string& strTmpGrpName){};
	virtual void OnDEVRenameMyGroup(const std::string& strTmpGrpID, std::string& strAdminID, std::string& strTmpGrpName){};
	virtual void OnDEVAddMyGroupMember(const std::string& strTmpGrpID, std::string& strMemberID, int nDid){};
	virtual void OnDEVDelMyGroupMember(const std::string& strTmpGrpID, std::string& strMemberID, int nDid){};
	virtual void OnDEVGetMyGroup(const std::string& strTmpGrpID, std::string& strAdminID, std::string& strTmpGrpName){};
	virtual void OnDEVGetMyGroupMember(const std::string& strTmpGrpID, std::string& strMemberID, int nDid){};
	virtual void OnUpdateDevName(const std::string& strDevID, const std::string& strName, unsigned long ulGroupID){};
	virtual void OnUpdateChannelName(const std::string& strChannelID, const std::string& strName, unsigned long ulGroupID){};

	//-----------------------------------------------------
	// IIDXCoreNotify
	//-----------------------------------------------------
	virtual void SetCurRoomStatus(int nStatus); //0:无，1：在会议，2：在AView;
	virtual int GetCurRoomStatus(void); //0:无，1：在会议，2：在AView;

	// 2015
	// 收到视频转发
	// strOriginUser：发起者用户ID
	// strResourceID：视频资源ID
	// bHasPrivilege：是否拥有控制权
	virtual void OnForwardMonVideoIncoming(const std::string& strOriginUser, const std::string& strResourceID, bool bHasPrivilege){};

	// 撤销视频转发
	// strOriginUser：发起者用户ID
	// strResourceID：视频资源ID
	virtual void OnForwardMonVideoCancel(const std::string& strOriginUser, const std::string& strResourceID){};

	// 收到视频请求
	// strRequestUser：请求者用户ID
	// strResourceID：视频资源ID
	// bHasPrivilege：是否请求控制权
	virtual void OnRequestMonVideoIncoming(const std::string& strRequestUser, const std::string& strResourceID, bool bHasPrivilege){};
	// 

	virtual void OnPromptMessage(const std::string& strMsg){};

	virtual void OnInviteIntoMeeting(const std::string& strDomain, const std::string& strRoomID, const std::string& strRoomName, const std::string& strInviterNodeID, const std::string& strInviterID, const std::string& strPassword, const std::string& strInviterName);
	virtual void OnRejectInvitation(const std::string& inviteeid, const std::string& strinviteName){};
	virtual std::string GetLocalMemberID(void){ return ""; };

	virtual void OnAppTempMetRsp(unsigned long ulRoomID, unsigned long ulGroupID, int nCode = 0);
	virtual void OnRspInviteUserIntoMeeting(const std::string& strSessionID, int nCode){};

	virtual void OnEnterRoom(unsigned int errcode, const std::string& errText = "", const std::string& szMetName = "", const std::string& szMetID = "");

	virtual void OnExitRoom(void){};

	virtual void OnMemberOffline(const std::string& memberid, const std::string& membername){};
	virtual void OnKickOut(void){};
	virtual void OnXSSEResizeWndNotify(int nTMID, int nWndIndex, bool bEnabled){};

	// 视频监控相关  // 2015.12.4
	virtual MapMonGroupItem GetMonGroupItemMap(void){ MapMonGroupItem monGrp; return monGrp; };
	virtual MapMonChannelItem GetMonChannelItemMap(void){ MapMonChannelItem monChnl; return monChnl; };
	virtual GROUPINFO*	GetMonGroupItem(const std::string& groupid){ return NULL; };
	virtual CHANNELINFO* GetMonChannelItem(const std::string& channelid){ return NULL; };

	virtual std::string GetLocalUserName(void){ return ""; };

	virtual void OnMemberInMeeting(const std::string& memberid){};
	virtual void OnMemberOutMeeting(const std::string& memberid){};

	virtual void MeetingMember(MMS_ROOM metRoomItem, std::vector<std::string> vecOldMember, const std::vector<std::string> &hide_members, const std::string strGroupId = ""){};

	virtual void OnRoomIsFull(){};
	virtual void OnRequestExitMeeting(bool bKickOut = false){};

	virtual void OnUserAVStatus(UINT nType = 0, int nFlag = 0){};

	virtual void SetFullTemplate(bool bFull){};
	virtual bool IsFullScreen(){ return false; };//是否全屏

	//消息框
	virtual void OnMeetingMemberMsg(string groupId, string sFromId, string sCmdType, string roomid = ""){};

	//获取好友名称
	virtual std::string GetUserName(const std::string& strMemberID){ return ""; };

	virtual void OnTMCtrlNotify(bool bIsOpen){};//模板控制器回调

	//码流选择ToolBar
	virtual void ShowStreamType(int iType){};
	//end
	virtual void ShowFrameRateControlMode(int nMode){};
	//-----------------------------------------------------
private:
	Ui::vcdpMainClass ui;
	QTabWidget *userTabWidget;
	//std::string&	m_strUserID;
	std::string    m_strSessionID;
	IIDXCore*		m_pIDXCore;			// IDXCore
	bool			m_bOwner;			// 是否是我创建的会议
	unsigned long	m_ulRoomID;
	unsigned long	m_ulGroupID;
	int				m_nCurRoomStatus;		// 当前会议状态 0:无，1：在会议，2：在AView;
	bool			m_bShowFloatLocalVideo;
	bool			m_bShowLocalVideo; //当前本地视频状态
	int				m_nScreenID;
	int				m_nTMSubType;

	
};

#endif // VCDPMAIN_H

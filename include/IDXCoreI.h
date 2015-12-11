/******************************************************************
@file   IDXCore.h
@brief
	�ṩ���ն˻��鹦�ܵ�����ں͹��������װ��
	�ն�ͬʱֻ�ܴ���һ�������У������Ҫ����������飬��ô���û���Ҫ��֮ǰ�Ļ�����ʱ�뿪���ٿ��µĻ��飻

@note     �ӿ�ʹ��˵����

   ���   |                    �ӿ�                  |                    ����                        |    �Ƿ����
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

#define LEN_MEET_NAME			20		// �������Ƴ���
#define LEN_MEET_DESC			100		// ������������
#define LEN_MEET_PASSWORD		20		// �������볤��
#define DROP_DEV_LIST_TO_VIEW	0x12

// ��������Ƶ��ʾ����ķ���ģ��
#include "WinTempletDefine.h"

#if 0 // 2015.11.21
// Ȩ��λ����
typedef enum PRIVILEGE_BIT
{
	PRIVILEGE_BIT_SIP		= 1,	//SIP����
	PRIVILEGE_BIT_SMS		= 2,	//SMS����
	PRIVILEGE_BIT_MMS		= 3,	//�������(WEB)
	PRIVILEGE_BIT_MON		= 4,	//��ص㲥(WEB)
	PRIVILEGE_BIT_TEM		= 5,	//ģ������
	PRIVILEGE_BIT_FAX		= 6,	//�շ�����
	PRIVILEGE_BIT_MSG		= 7,	//�����㲥��Ϣ
	PRIVILEGE_BIT_BAD		= 8,	//��������
	PRIVILEGE_BIT_MAP		= 9,	//��ͼ�༭
	PRIVILEGE_BIT_MAT		= 10,	//�������
	PRIVILEGE_BIT_LOS		= 11,	//����Ȩ��
	PRIVILEGE_BIT_INFO		= 14,	//�޸ĸ�������
	PRIVILEGE_BIT_ORG		= 17,	//��ʾ����Ȩ��;
};
#endif // 

enum
{
	CON_AFFICHE = 0,				//���鹫��
	CON_TITLE,						//�������
	CON_CALLING,					//�������
	LOCK_CON,						//��������
	SOUND_BESTIR,					//��������
	CON_SYNC,						//ͬ��ģʽ
	CON_DESYNC,						//����ģʽ
	CON_INDEPENDENCE,				//����ģʽ
	CON_LABIAL_SOUND,				//����ͬ��
	LAND_TIMER_TAXIS,				//��¼ʱ������
	NAME_TAXIS,						//��������
	TYPE_TAXIS,						//��Ա��������
	SET_CON_AFFICHE,				//���ù���
	SET_CON_TITLE,					//���ñ���
	SET_CON_HAND,					//���û������
	ALLOW_DISCUSS,					//��������
	SCREEN_CONTROL,					//����������Ļ����
	NOTE_INFORM,					//����֪ͨ
	CON_IN_PHASE,					//����ͬ��
	IN_PHASE_CHOOSE_1,				//ѡ 1 ��
	IN_PHASE_CHOOSE_2,				//ѡ 2 ��
	IN_PHASE_CHOOSE_3,				//ѡ 3 ��
	IN_PHASE_CHOOSE_4,				//ѡ 4 ��
	CONF_KINESCOPE,					//����¼��
	CONF_AVDIO,						//��Ƶ
	CONF_DOC,						//�ĵ�
	FULL_SCREEN,					//ȫ��
	SMALL_SCRIP,					//Сֽ��
	SHOWVIDEOTITLE,					//��Ƶ����
};

//�ص�
enum
{
	REV_ALLOW_KINESCOPY = 0,		//�������¼��
	REV_ALLOW_YT_CONTROL,			//���������̨
	REV_ALLOW_SPEAK,				//�������뷢��
	REV_ALLOW_WB,					//������Ӱװ�
	REV_ALLOW_CONTROL,				//��������Ա����
	REC_CON_LABIAL_SOUND,			//����ͬ��
	REV_ALLOW_FLOOT,				//����ı両������
	REV_CON_AFFICHE,				//���鹫��
	REV_CON_TITLE,					//�������
	REV_CON_HAND,					//�������
	REV_CON_CALLING,				//�������
	REV_LOCK_CON,					//��������
	REV_SOUND_BESTIR,				//��������
	REV_NAME_TAXIS,					//��������
	REV_LAND_TIMER_TAXIS,			//��¼ʱ������
	REV_TYPE_TAXIS,					//��Ա��������
	REV_CON_SYNC,					//ͬ��ģʽ
	REV_CON_DESYNC,					//����ģʽ
	REV_CON_INDEPENDENCE,			//����ģʽ
	REV_IN_PHASE_CHOOSE_1,			//ѡ 1 ��
	REV_IN_PHASE_CHOOSE_2,			//ѡ 2 ��
	REV_IN_PHASE_CHOOSE_3,			//ѡ 3 ��
	REV_IN_PHASE_CHOOSE_4,			//ѡ 4 ��
	REV_ALLOW_DISCUSS,				//��������
	REV_SCREEN_CONTROL,				//����������Ļ����
	REV_CONF_KINESCOPE,				//����¼��
	REV_CONF_AVDIO,					//��Ƶ
	REV_CONF_DOC,					//�ĵ�
	REV_FULL_SCREEN,				//ȫ��
	REV_SMALL_SCRIP,				//Сֽ��
	REV_YT_CTRL,					//��̨����
	REV_H323_CTRL,					//H323����
	REV_SHOW_AVINFO,				//��Ƶ��Ϣ
};

enum
{
	STREAM_TYPE_AUTO = 0,
	STREAM_TYPE_HIGH,
	STREAM_TYPE_MID,
	STREAM_TYPE_LOW,
};

#define TERM_TYPE_PC		"PC"		//PC�汾
#define TERM_TYPE_TERMINAL	"Terminal"	//�ն˰汾

#include "KMMSDefine.h"
#include "StructDefine.h"

// IDXCore֪ͨ
// ע�����ϲ�Ӧ�ü̳�ʵ�֣���IDXCore���ã��������ϲ�֪ͨ
class IIDXCoreNotify
{
public:
	
	// ���ϲ�֪ͨ��ǰ����״̬
	// nStatus����ǰ״̬ //0:�ޣ�1���ڻ��飬2����AView
	// ע���ϲ�ɾݴ�״ִ̬�� -- ������ʾ״̬�ĸ��£�״ֵ̬���棻
	virtual void SetCurRoomStatus(int nStatus)=0;
	// �õ���ǰ����״̬�����ϲ�Ӧ�û�ȡ��
	// ����ֵ�� 0  �ޣ� 1 �ڻ��飬2 ��AView
	virtual int GetCurRoomStatus(void)=0;

	// ��ñ��س�ԱID
	virtual std::string GetLocalMemberID(void)=0;
	
	// ��ñ����û�����
	virtual std::string GetLocalUserName(void)=0;

	// �����û�ID��ȡ�û�����
	// ע���ϲ�Ӧ��ά����ͨѶ¼�м���
	virtual std::string GetUserName(const std::string& strMemberID) = 0;

	// ���ϲ�Ӧ�ô�����ʾ��Ϣ
	// ��Щ��ʾ��Ϣһ����Ҫ�ϲ�Ӧ����ʾ���û�
	// ���������ʾ���ַ�ʽ���ϲ�Ӧ�þ�����
	virtual void OnPromptMessage(const std::string& strMsg)=0;

	// 2015
	// �յ���Ƶת��
	// strOriginUser���������û�ID
	// strResourceID����Ƶ��ԴID
	// bHasPrivilege���Ƿ�ӵ�п���Ȩ
	virtual void OnForwardMonVideoIncoming(const std::string& strOriginUser, const std::string& strResourceID, bool bHasPrivilege) = 0;

	// ������Ƶת��
	// strOriginUser���������û�ID
	// strResourceID����Ƶ��ԴID
	virtual void OnForwardMonVideoCancel(const std::string& strOriginUser, const std::string& strResourceID) = 0;

	// �յ���Ƶ����
	// strRequestUser���������û�ID
	// strResourceID����Ƶ��ԴID
	// bHasPrivilege���Ƿ��������Ȩ
	virtual void OnRequestMonVideoIncoming(const std::string& strRequestUser, const std::string& strResourceID, bool bHasPrivilege) = 0;
	// 

	// ֪ͨ������������
	// strDomain������
	// ע���ϲ�Ӧ��Ӧ�����Ƿ������������������������ IDXCore . AcceptInvitation������ܾ�������� IDXCore . RejectInvitation
	virtual void OnInviteIntoMeeting(const std::string& strDomain,const std::string& strRoomID,const std::string& strRoomName,const std::string& strInviterNodeID,const std::string& strInviterID, const std::string& strPassword, const std::string& strInviterName)=0;
	// ֪ͨ���������߾ܾ�������
	// ע���ϲ�Ӧ��ֻ��Ҫ��ʾ��Ӧ��ʾ����
	virtual void OnRejectInvitation(const std::string& inviteeid,const std::string& strinviteName)=0;

	// ֪ͨ�����ϲ�Ӧ��֪ͨ����ʱ����������Ӧ����Я��ϵͳΪ����ʱ�������Ļ���ID
	// ע����ο�IDXCoreTest��ʵ��
	// nCode    - 0		���޴�
	//            ����ֵ	�������룬
	virtual void OnAppTempMetRsp(unsigned long ulRoomID, unsigned long ulGroupID, int nCode = 0) = 0;

	// ֪ͨ���������;��errcode!=0ʱ�����������ڴ���
	// ע����ο�IDXCoreTest��ʵ��
	virtual void OnEnterRoom(unsigned int errcode, const std::string& errText = "", const std::string& szMetName = "", const std::string& szMetID = "") = 0;

	// ֪ͨ���ӻ����˳�
	// ע���ϲ�Ӧ��ֻ�迼�ǽ���״̬���¼���
	virtual void OnExitRoom(void)=0;

	// ֪ͨ����Ա�뿪���飬memberid��ԱID��membername��Ա����
	// ע���ϲ�Ӧ��ֻ��Ҫ���ǽ���ĳ��ּ���
	virtual void OnMemberOffline(const std::string& memberid,const std::string& membername)=0;

	// ֪ͨ�����û����߳�����
	// ע���ϲ�Ӧ��ֻ��Ҫ���ǽ���ĳ��ּ���
	virtual void OnKickOut(void)=0;
	// 

	// InviteUserIntoMeeting����Ӧ�ص�����
	// strSessionID������InviteUserIntoMeetingʱ���ص�SessionID
	// nCode��������  0���޴�������ֵ�������롾ע�������������
	virtual void OnRspInviteUserIntoMeeting(const std::string& strSessionID, int nCode) = 0;

	// ֪ͨ���û�memberid�������
	// ע���ϲ�Ӧ��ֻ��Ҫ���ǽ���ĳ��ּ���
	virtual void OnMemberInMeeting( const std::string& memberid ) = 0;

	// ֪ͨ���û�memberid�뿪����
	// ע���ϲ�Ӧ��ֻ��Ҫ���ǽ���ĳ��ּ���
	virtual void OnMemberOutMeeting( const std::string& memberid ) = 0;

	// ���ϲ�Ӧ��֪ͨ�������е�ǰ�ĳ�Ա�б�
	// metRoomItem��������Ϣ
	// vecOldMember���д�Ż����е�ǰ�ĳ�Ա�б�
	// hide_members��������
	// ע���ú���Ŀǰ����
	virtual void MeetingMember(MMS_ROOM metRoomItem, std::vector<std::string> vecOldMember, const std::vector<std::string> &hide_members, const std::string strGroupId="") = 0;
	// 

	// ֪ͨ������������Ա
	virtual void OnRoomIsFull() = 0;

	// ���������˳�������
	// ע���ϲ�Ӧ����Ҫ������Ӧ�ӿڣ��������顾�����IDXCore::ExitMeeting�ȡ�
	virtual void OnRequestExitMeeting(bool bKickOut = false)=0;

	// ֪ͨ������Ƶ��״̬���㲥/δ�㲥��
	// ע���ϲ�Ӧ��ֻ��Ҫ���ǽ�����ּ���
	virtual void OnUserAVStatus(UINT nType = 0, int nFlag = 0) = 0;

	// ��Ϣ��
	// ����Ϣ���ݸ��ϲ�Ӧ�ã����ϲ�Ӧ���ṩ��Ϣ��ʾ����
	// groupId����ID
	// sFromId���û�ID����Ϣ��Դ��ȡ����������Ϣ�� from_id �ֶΡ�
	// sCmdType����Ϣ��Я����������ϲ�Ӧ�ö��ԣ�������������ʾ��
	// ע���ϲ�Ӧ��ֻ��Ҫ���ǽ�����ּ���
	virtual void OnMeetingMemberMsg(string groupId,string sFromId,string sCmdType,string roomid ="") = 0;

	// Ҫ���ϲ�Ӧ�ô���ȫ��
	// ע���ϲ�Ӧ�ý������Ԫ�أ���ȫ���µ���ʽ����ȵȣ�����IDXCore�л�����Ƶ���ڵĴ�С/λ�õȣ�����Ҫ�����ϲ�Ӧ���������
	virtual void SetFullTemplate(bool bFull) = 0;

	// �жϵ�ǰ�Ƿ�Ϊȫ��״̬
	virtual bool IsFullScreen() = 0;

	virtual void OnXSSEResizeWndNotify(int nTMID, int nWndIndex, bool bEnabled) = 0;

	// ��Ƶ������  // 2015.12.4
	virtual MapMonGroupItem GetMonGroupItemMap(void)=0;	
	virtual MapMonChannelItem GetMonChannelItemMap(void)=0;
	virtual GROUPINFO*	GetMonGroupItem(const std::string& groupid)=0;
	virtual CHANNELINFO* GetMonChannelItem(const std::string& channelid) = 0;
	// end // 2015.12.4

	// ֪ͨ������ģ��������Ƿ�bIsOpen���Ѵ�
	// ע���ϲ�Ӧ��ֻ�迼�ǽ����϶�״̬�ĳ��ּ���
	virtual void OnTMCtrlNotify(bool bIsOpen)=0;

	// ֪ͨ�������������ú����ϲ�Ӧ��֪ͨ�����õ�����iType
	// ע���ϲ�Ӧ��ֻ�迼�ǽ�����״̬�ĳ��ּ���
	virtual void ShowStreamType(int iType) = 0;

	// ֡�ʿ������ú����ϲ�Ӧ��֪ͨ�����õ�ģʽ
	// ע��֡�ʿ���ģʽȡֵ������NETEC.h�ж���FRAME_RATE_CONTROL_MODE
	// ע���ϲ�Ӧ��ֻ�迼�ǽ�����״̬�ĳ��ּ���
	virtual void ShowFrameRateControlMode(int nMode) = 0;
};

#define SETISBEGGINNER_CHAT			1
#define SETISBEGGINNER_WB			2
#define SETISBEGGINNER_BCDESKTOP	3
#define SETISBEGGINNER_BCVEDIO		4
#define SETISBEGGINNER_FILESEND     5

// IDXCore��Ľӿڶ���
// IDXCore���������� �ն˲���鹦�ܵ�����ںͷ�װ
// �ϲ�Ӧ��ͨ�����øýӿڣ�ʵ���˶��ڵ�¼���顢�����ڹ��ܡ��˳������
// 
class IIDXCore
{
public:
#if 1 // 2015.11.4
	virtual void OnTest() = 0;
#endif //

	// �ͷ�IDXCore���������ڲ����ж��󣬽���IDXCore
	virtual void ReleaseConnections(void)=0;

	// �����ȡ�����б�
	virtual void EnterMeetingMode(void)=0;

	// ��IDXCore�������ض����ϲ�Ӧ�á�
	virtual void SetMainWnd(IMainCtrl *pMainWnd) = 0;

	// ���󴴽���ʱ����
	virtual int RequestCallTempMet() = 0;

	// ���������ն��˳�����
	virtual void AllMemberExitMeeting(void) = 0;

	// ���ն��˳�����
	virtual void ExitMeeting(bool bneedrefresh = true)=0;

	// ����ϯ����ĳ�û��������
	// ע����Ҫ��ϯ��ͬ��
	virtual void RequestIntoMeeting(const std::string& userid, const std::string nodeid, const std::string& username) = 0;

	// ��ĳ�û�ת����Ƶ��ص���Ƶ
	// strResourceID����Ƶ�����ԴID
	// bHasPrivilege���Ƿ�ӵ�п���Ȩ
	virtual void ForwardMonVideo(const std::string& strResourceID, const std::string& strDstUserID, bool bHasPrivilege, std::string& strSessionID) = 0;

	// ������Ƶת��
	// strOriginUser���������û�ID
	// strResourceID����Ƶ��ԴID
	// strSessionID��ԭ�����������ʱ�ĻỰID
	virtual void CancelForwardMonVideo(const std::string& strResourceID, const std::string& strSessionID) = 0;

	// ���û���������Ƶ
	// strAdminUser���ü�صĹ������û�ID
	// strResourceID����Ƶ��ԴID
	// bHasPrivilege���Ƿ��������Ȩ
	virtual void RequestMonVideo(const std::string& stAdminUser, const std::string& strResourceID, bool bHasPrivilege) = 0;

	// �����û���userid���������
	// bPresider�����û��Ƿ���Ϊ��ϯ
	// strSessionID    - [out] ���ر�������ĻỰID  -- ��Ҫ������
	virtual void InviteUserIntoMeeting(const std::string& userid, std::string& strSessionID, bool bPresider = false, bool bTempMet = false)=0;

	// �������룬���
	// ע���û�ѡ�񡰽������롱ʱ���ϲ�Ӧ�õ��øú������������룬���Լ������
	virtual void AcceptInvitation(std::string strDomain,std::string roomid,std::string password)=0;

	// �ܾ�����
	// ע���û�ѡ�񡰾ܾ����롱ʱ���ϲ�Ӧ�õ��øú������ܾ�����
	virtual void RejectInvitation(const std::string& strDomain,const std::string& strRoomID,const std::string& strInviterNodeID) = 0;


	// ��ʽ/���ر�����Ƶ
	// ע�������ʽ�������Ը������ڷ�ʽ
	virtual void ShowMeetingLocalAV(bool bShow) = 0;

	// �򿪱�����Ƶ
	// ע�����Զ����Ŵ���λ��
	virtual int OpenLocalVideo() = 0;
	
	// �رձ�����Ƶ
	virtual void CloseLocalVideo() = 0;

	// ��ĳ�û���memberid������Ƶ
	virtual int OpenUserVideo(const std::string memberid) = 0;
	// ��ĳ�û���memberid������Ƶ
	virtual int OpenUserAudio(const std::string memberid) = 0;
	// ��ĳ�û���memberid��������Ƶ
	virtual int OpenUserAV(const std::string memberid) = 0;

	// �ر�ĳ�û���memberid������Ƶ
	virtual void CloseUserVideo(const std::string memberid) = 0;
	// �ر�ĳ�û���memberid������Ƶ
	virtual void CloseUserAudio(const std::string memberid) = 0;
	// �ر�ĳ�û���memberid��������Ƶ
	virtual void CloseUserAV(const std::string memberid) = 0;

	// �ر�ָ������nScreenID���������û���Ƶ
	virtual void CloseAllVideo(int nScreenID)=0;

	// �㲥ĳ�û���Ƶ
	virtual int BroadcastUserVideo(const std::string& strMemberID/*���㲥��ID*/, int usScreenID/*��ĻID*/, int usSubwinID/*�Ӵ���ID*/ ) = 0;
	virtual int BroadcastUserAudio(const std::string& strMemberID) = 0;
	virtual int BroadcastUserAV(const std::string& strMemberID/*���㲥��ID*/, int usScreenID/*��ĻID*/, int usSubwinID/*�Ӵ���ID*/) = 0;

	virtual int StopBroadcastUserVideo(const std::string& strMemberID) = 0;
	virtual int StopBroadcastUserAudio(const std::string& strMemberID) = 0;
	virtual int StopBroadcastUserAV(const std::string& strMemberID) = 0;

	// �ж��Լ��Ƿ�Ϊ��ǰ������ϯ
	virtual bool IsMyHost()=0;

	//ֻ�ж�������Ƿ�Ϊ�����ߣ������ǰ�������ˣ�����FALSE
	virtual bool IsMySpeaker() = 0;
	//

	// �жϱ����Ƿ�Ϊ������
	virtual bool IsMyAuditor()=0; //������

	// ���������顾��ulRoomID��ʶ�Ļ��顿
	// ����
	// ulRoomID       -- ��IN������ID
	// strUserID      -- ��IN���û�ID����8010001
	// strUserName    -- ��IN���û���ʾ������Ϊ""
	virtual bool StartEnterMeetingRoom(unsigned long ulRoomID, const std::string& strUserID, const std::string& strUserName)=0;

	// �ж��Ƿ��ڻ�����
	virtual bool IsInMeeting() = 0;

	// ���뷢��
    virtual void RequestSpeak(bool cancel_request = false) = 0;
	// ��������
    virtual void RequestQuestion(bool cancel_request = false) = 0;
	
	//0x01:�ܾ���������
	//0x02:����������ʾ��Ϣ
	//0x04:�Զ�����
	//0x10:����ڻ����У����Զ��˳�������뱻����Ļ���

	// ͬ�ⷢ������
	virtual void AcceptRequestSpeaker(string roomid,string groupId,string sToId,bool bAnswer = true)=0;
	// �ܾ���������
	virtual void RejectRequestSpeaker(string roomid,string groupId,string sToId)=0;

	// ͬ����������
	virtual void AcceptRequestQuiz(string roomid,string groupId,string sToId)=0;
	// �ܾ���������
	virtual void RejectRequestQuiz(string roomid,string groupId,string sToId)=0;

	// �õ����������Ƶ�����ʴ�С
	// ��λkbps
	virtual long GetVideoOutBitrate() = 0;

	// �õ����ؽ�����Ƶ�����ʴ�С
	// ��λkbps
	virtual long GetVideoInBitrate() = 0;

    //Ȩ�޿���
	// ����ĳȨ��
    virtual void SetPrivilegeCode(unsigned long nCode) = 0;
	// ��ȡȨ����
    virtual unsigned long GetPrivilegeCode() = 0;
	// �ж�ĳȨ���Ƿ�����
    virtual bool IsEnabledPrivilege( unsigned long nCode ) = 0;

	// ���ݻ����ԱID���õ������Ա����
	virtual std::string GetMemberName(const std::string& memberid)=0;	

	// 2015.12.4 TTT ��Ƶ������
	virtual void OnGetGroupInfoEnd()=0;
	virtual void OnChannelInfoEnd()=0;
	virtual void OnChannelInfo(const CHANNELINFO& item)=0;
	virtual void OnUpdateDevName(const std::string& strDevID,const std::string& strName, unsigned long ulGroupID)=0;
	virtual void OnUpdateChannelName(const std::string& strChannelID,const std::string& strName, unsigned long ulGroupID)=0;
	// end TTT
	//����ѡ��
	// ������ ������Ҫ����������˵���ڴ�
	virtual void SetStreamType(int iType) = 0;	//iTypeΪ-1ʱ���������ļ���ȡ������

	// ���ʿ���ģʽ
	// ������ ������Ҫ�����ʿ���ģʽ˵���ڴ�
	virtual void SetFrameRateControlMode(int nMode) = 0;	//nModeΪ-1ʱ���������ļ���ȡ������

	// ��������MCUʱ�����ø�IDXCore
	virtual void SetMCUItem(MMS_MCU* pMCU) = 0;

	// ��������¼��
	// ��ָ���Ĵ��ڵ���Ƶ¼�����������浽����
	virtual int StartLocalRecord()=0;

	// ֹͣ����¼��
	virtual void StopLocalRecord()=0;

	// ί����ʱ��ϯ
	// strMemberID: �û�ID
	// bTake: true -- ί�ɣ�fale -- ����
	virtual int AppointTempPresider(const std::string& strMemberID, bool bTake) = 0;

	// ��õ�ǰ�ģ��ID
	virtual unsigned long GetActiveTM() = 0;

	// ������Ƶ����ģ�����Ĵ�С
	virtual void ResizeMainHPTM(/*CWnd**/HWND pWnd, int x, int y, int cx, int cy, bool bShow) = 0;

	// ����
	virtual void ResizeDlgLocalVideoMgr(/*CWnd**/HWND hWnd, int x, int y, int cx, int cy, bool bShow) = 0;

	// ������Ƶ���ڷ���ģ������
	// ע�����Ϊͬ�����飬����������Ա�Ĵ��ڷ���ģ�彫ͳһ�ı�
	virtual void ChangeTMType(int nType, int nSubType, unsigned long ulScreenIndex) = 0;

	// ��ʾ/���ػ���������
	virtual void OnShowMainConferenceWnd(bool bShow) = 0;

	// �õ�����ʾ����С
	virtual RECT GetPrimaryScreenRect() const = 0;

	// ָ�������������Ƿ�ɼ�
	virtual BOOL IsScreenRectVisible(int nIndex) = 0;
};

// ���� IIDXCore ���󣬸ö���ΪIDXCore���������
// rNotify���ص�/֪ͨ���������
// pWnd�������ڶ���
IDXCORE_API IIDXCore* CreateIDXCore(IIDXCoreNotify& rNotify, /*CWnd**/ HWND pWnd);

#endif
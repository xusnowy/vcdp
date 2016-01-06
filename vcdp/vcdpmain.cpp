#include "vcdpmain.h"
#include <QDockWidget>
#include <QDesktopWidget>
vcdpMain::vcdpMain(QWidget *parent)
	: QMainWindow(parent)
	, m_strUserID(std::string(""))
	, m_bShowLocalVideo(false)
	, m_bShowFloatLocalVideo(false)
	, m_nScreenID(0)
	, m_nTMSubType(0)
	, m_strSessionID(std::string(""))
	, m_bUserTreeView(true)
	, m_nCurRoomStatus(ROOM_STATUS_NONE)
	, m_bMetTabView(true)
{
	ui.setupUi(this);
	m_LoginUi = new VcdpLogin();
	m_LoginUi->show();
	close();
	InitToolBar();
	InitLeftUserTreeView();
	InitMainView();
	OnClickMetDisplay();
	//m_TabWidget->setGeometry(QRect(130, 30, 127, 80));
	//m_TabWidget->resize(ui.widgetMain->size());
	//m_TabWidget->showMaximized();
	
	m_pIDXCore = CreateIDXCore(*this, (HWND)this->winId());

	
}

vcdpMain::~vcdpMain()
{

}
//��ʼ��maintoolbar
void vcdpMain::InitToolBar()
{
	
	//������ذ�ť
	q_HideView = new QToolButton;
	q_HideView->setText("����");
	connect(q_HideView, SIGNAL(clicked()), this, SLOT(OnClickHideView()));
	ui.mainToolBar->addWidget(q_HideView);
	//����û�������
	QWidget *BlankAreaWidget = new QWidget(this);
	ui.mainToolBar->addWidget(BlankAreaWidget);
	QHBoxLayout* userLayout = new QHBoxLayout(BlankAreaWidget);
	QSpacerItem* spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	userLayout->addItem(spacer);
	q_UserMember = new QToolButton;
	q_UserMember->setText("�û�������");
	ui.mainToolBar->addWidget(q_UserMember);
	ui.mainToolBar->addSeparator();
	q_VedioDisplay = new QToolButton;
	q_VedioDisplay->setText("��Ƶ");
	ui.mainToolBar->addWidget(q_VedioDisplay);
	ui.mainToolBar->addSeparator();
	q_GisDisplay = new QToolButton;
	q_GisDisplay->setText("GIS��ͼ");
	ui.mainToolBar->addWidget(q_GisDisplay);
	QWidget *BlankAreaWidget2 = new QWidget(this);
	QHBoxLayout* userLayout2 = new QHBoxLayout(BlankAreaWidget2);
	QSpacerItem* spacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	userLayout2->addItem(spacer2);
	ui.mainToolBar->addWidget(BlankAreaWidget2);
	q_ConifgDisply = new QToolButton;
	q_ConifgDisply->setText("����");
	ui.mainToolBar->addWidget(q_ConifgDisply);



	

}
//��ʼ���û�������ͼ
void vcdpMain::InitLeftUserTreeView()
{
	q_DockUserView = new QDockWidget(this);
	q_DockUserView->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);
	//q_UserTreeView = new QTreeView(this);
	VcdpTreeView *test = new VcdpTreeView(q_DockUserView);
	q_DockUserView->setWidget(test);
	connect(test, SIGNAL(sendNumtoMet(QString)), this, SLOT(receiveNum(QString)));
	connect(q_DockUserView, SIGNAL(visibilityChanged(bool)), this, SLOT(OnCloseDockUserView(bool)));
	this->addDockWidget(Qt::LeftDockWidgetArea, q_DockUserView);
}
void vcdpMain::InitMainView()
{
	//����ʾ����

	m_TabWidget = new VcdpUserTab(this);
	m_TabWidget->addUserListMember();
	m_TabWidget->setObjectName(QStringLiteral("tabWidget"));
	ui.widgetMain->layout()->addWidget(m_TabWidget);
	m_userDialer = new VcdpDialer;//��ʼ��������
	m_TabMetWidget = new VcdpUserTab(this);
	m_TabMetWidget->addMetListMember();
	m_TabMetWidget->setObjectName(QStringLiteral("tabMetWidget"));
	ui.widgetMet->layout()->addWidget(m_TabMetWidget);
	ui.verticalLayout_2->setStretch(0, 2);
	ui.verticalLayout_2->setStretch(1, 1);
	ui.widgetMet->hide();
}
void vcdpMain::OnCloseDockUserView(bool isOk)
{
	if (isOk)
	{
		m_bUserTreeView = true;
	}
	else
	{
		m_bUserTreeView = false;
	}
	q_HideView->setText(isOk ? ("����") : ("��ʾ"));


}
//�������οؼ�
void vcdpMain::OnClickHideView()
{
	if (m_bUserTreeView)
	{
		q_DockUserView->setVisible(false);	
	}
	else
	{	
		q_DockUserView->setVisible(true);
	}

	
	

}
//��������ʾ
void vcdpMain::OnClickDialerBtn()
{
	QDesktopWidget *desk = QApplication::desktop();
	int wd = desk->width();
	int ht = desk->height();
	connect(m_userDialer, SIGNAL(sendNum(QString)), this, SLOT(receiveNum(QString)));
	m_userDialer->hide();
	m_userDialer->setWindowFlags(Qt::WindowStaysOnTopHint);
	m_userDialer->setFixedSize(330, 330);
	m_userDialer->move(0, (ht - (m_userDialer->height())*1.4));
	m_userDialer->show();
}

//����᳡
void vcdpMain::receiveNum(const QString &numEdit)
{
	if (m_pIDXCore == NULL)
	{
		return;
	}
	m_pIDXCore->InviteUserIntoMeeting(numEdit.toStdString(), m_strSessionID, false, true);
}
//��ʱ�᳡����ʾ
void vcdpMain::OnClickMetDisplay()
{

if (m_bMetTabView)
	{
		ui.widgetMet->hide();
	}
	else
	{
		ui.widgetMet->show();
	}
	m_bMetTabView = !m_bMetTabView;

}
//��¼������
void vcdpMain::DoServerConnect(const std::string& strServerAddr, unsigned short usServerPort, const std::string& strUserID, const std::string& strPassword, const std::string& strStatus)
{
	m_strServerAddr = strServerAddr;
	m_usServerPort = usServerPort;
	m_strUserID = strUserID;
	m_strPassword = strPassword;
	m_strStatus = strStatus;

	/** ע��2015.9.22 wangzwa ���� B */
	/** ����B-1 */
	/** ע���ڴ�֮ǰҪ����� NETEC_Core::Start(0, false, false, true) */
	/** ע������NETEC��Node����������IP/�˿����ø�NETEC_Node���� */
	NETEC_Node::Start();
	NETEC_Node::SetServerIP(strServerAddr.c_str());
	NETEC_Node::SetServerPort(usServerPort);

	/** ����B-2 : ����KSYSClient�ӿ�SYSSessionConnect��������������� */
	//��������
	if (SYSSessionConnect(this, SERVER_TYPE_MCU_MTS, strUserID) == false)
	{
#if 0
		//����������ʧ��
		if (m_pLoginDlg)
		{
			m_pLoginDlg->SetMessageText(_T("connect failed."));
		}
		return;

#endif	
	}
	/** ����B-3 */
	/** ע����IMS����¼��۲���ע�ᵽKSYSClient */
	IMSSessionAddEvent(this);
	/** ע����MMS����¼��۲���ע�ᵽKSYSClient */
	//	MMSSessionAddEvent(this);
}
void vcdpMain::DoServerDisconnect()
{
	/** ע������KSYSClient��SYSSessionDisconnect�Ͽ��������� */
	//����Ͽ�
	SYSSessionDisconnect(this);
	/** ��KSYSClient����IMS����¼��۲��� */
	IMSSessionRelease();
	/** ��KSYSClient����MMS����¼��۲��� */
	//	MMSSessionRelease();

	/** ע��NETEC_Node::Stop ����NETEC */
	NETEC_Node::Stop();
}

//=======================================================================================
// KSYSSessionEvent
//=======================================================================================
/** ע��2015.9.22 wangzwa ������Ӧ����¼� -- ����֮ǰע����ȥ�Ĺ۲��߶��� */
//---------------------------------------------------------------------------------------
void vcdpMain::OnServerConnecting(void)
{
	if (m_LoginUi)
	{
		//m_LoginUi->hide();
		m_LoginUi->SetMessageText("connecting server...");
	}
	//	if (m_pLoginDlg)
	//	{
	//		m_pLoginDlg->SetMessageText(_T("connecting server..."));
	//	}
}

//---------------------------------------------------------------------------------------
void vcdpMain::OnServerReconnected(void)
{
	if (m_LoginUi)
	{
		m_LoginUi->SetMessageText("reconnected server");
	}

}

//---------------------------------------------------------------------------------------
void vcdpMain::OnServerBusy(void)
{
	if (m_LoginUi)
	{
		m_LoginUi->SetMessageText("server busy.");
	}

}

//---------------------------------------------------------------------------------------
void vcdpMain::OnServerFailed(void)
{

	if (m_LoginUi)
	{
		m_LoginUi->SetMessageText("server connect failed.");
	}
}

//---------------------------------------------------------------------------------------
void vcdpMain::OnServerDisconnected(unsigned int nErrCode)
{

	if (m_LoginUi)
	{
		m_LoginUi->SetMessageText("server disconnected.");
	}
}

//---------------------------------------------------------------------------------------
void vcdpMain::OnServerConnected(void)
{
	//	if (m_pLoginDlg)
	//	{
	//		m_pLoginDlg->SetMessageText(_T("server connected."));
	//	}

	/** ע��2015.9.22 wangzwa */
	/** ����C-1��ͨ��IMSSession�����������¼��Я���û���/���룩 */
	if (m_LoginUi)
	{
		m_LoginUi->SetMessageText("server connected.");
	}
	GetIMSSession().Login(m_strUserID, m_strPassword, m_strStatus, "");
}


//---------------------------------------------------------------------------------------
void vcdpMain::OnServerListStart(void)
{
}

//---------------------------------------------------------------------------------------
void vcdpMain::OnServerList(const std::string& strMCUID, const std::string& strMCUType,
	unsigned long ulConnections, const std::string& strBandWidth, unsigned long ulActivity,
	const std::string& strIPAddr, unsigned short usIPPort, const std::string& strIPName)
{
	//�������б�
}

//---------------------------------------------------------------------------------------
void vcdpMain::OnServerListEnd(void)
{
}

//---------------------------------------------------------------------------------------
/** ��¼���֪ͨ */
void vcdpMain::OnLogin(int nErrCode, const std::string& strModuleString)
{
	if (nErrCode == 0)
	{
#if 0 
		m_bLogin = TRUE;
		CString csInitStatus = _T("");
		if (m_pLoginDlg)
		{
			m_pLoginDlg->ShowWindow(SW_HIDE);
			csInitStatus = m_pLoginDlg->GetInitStatus();
		}
#endif //
		QString qsInitStatus = tr("");
		if (m_LoginUi)
		{
			m_LoginUi->hide();
			qsInitStatus = m_LoginUi->GetInitStatus();
			
		}
		std::string strUserID = GetIMSSession().GetUserID();
		std::string strUserName = GetIMSSession().GetUserName();

//		::OutputDebugString((strUserID + ":" + strUserName).c_str());
		if (m_pIDXCore == NULL)
		{
			return;
		}
		QString qsUserIDName;
		qsUserIDName = QString("%1 <%2>").arg(strUserName.c_str()).arg(strUserID.c_str());
		QWidget::showMaximized();
		//ui.label->setText(qsUserIDName);
		//ui.label_2->setText("online");
		ui.statusBar->showMessage(qsUserIDName);
		//m_pIDXCore->RequestCallTempMet();
#if 0 
		CString csUserIDName;
		csUserIDName.Format(_T("%s <%s>"), strUserName.c_str(), strUserID.c_str());
		GetDlgItem(IDC_STATIC_USERID_USERNAME)->SetWindowText(csUserIDName);
		GetDlgItem(IDC_STATIC_STATUS)->SetWindowText(csInitStatus);
#endif //
		// ��ȡ��ϵ����
		// GetIMSSession().FetchGroups();

		//	ShowWindow(SW_SHOW);
	}

	else
	{
		if (m_LoginUi)
		{
			QString qsText;
			qsText = QString("login failed(errcode=%1).").arg(nErrCode);
			
			m_LoginUi->SetMessageText(qsText);
		
			
		}

	}

}

void vcdpMain::OnClickQuitMet()
{
	if (m_pIDXCore == NULL)
	{
		return;
	}

	m_pIDXCore->ExitMeeting(true);
}
//---------------------------------------------------------------------------------------
void vcdpMain::OnLogout(int nErrCode)
{
#if 0 
	if (m_pLoginDlg)
	{
		CString csText;
		csText.Format(_T("logout(errcode=%d)."), nErrCode);
		m_pLoginDlg->SetMessageText(csText);
	}

	PostMessage(WM_DISCONNECT_SERVER);
#endif //
}

/// IIDXCoreNotify
void vcdpMain::OnEnterRoom(unsigned int errcode, const std::string& errText, const std::string& szMetName, const std::string& szMetID)
{
	if (m_pIDXCore == NULL)
	{
		return;
	}

	if (m_bOwner)
	{
		m_pIDXCore->AppointTempPresider(GetIMSSession().GetUserID(), true);
	}

	m_pIDXCore->SetMainWnd(this);

	// 
	QRect rc = ui.widgetMain->rect();

	int nWidth = rc.width(); // rc.Width() - 2;
	int nHeight = rc.height(); // rc.Height() - 80 - 80;

	//m_pIDXCore->ResizeMainHPTM((HWND)ui.widgetMain->winId(), rc.left() + 1, 80, nWidth, nHeight, true);
	m_pIDXCore->ResizeMainHPTM((HWND)ui.widgetMain->winId(), 0, 0, nWidth, nHeight, true);
	m_pIDXCore->OnShowMainConferenceWnd(true);
	
}

void vcdpMain::OnAppTempMetRsp(unsigned long ulRoomID, unsigned long ulGroupID, int nCode)
{
//	char szOutput[256];
	//sprintf(szOutput, "IDXCoreTestQT::OnAppTempMetRsp room id -- %u", ulRoomID);
	//	::OutputDebugString(szOutput);
	m_ulRoomID = ulRoomID;
	m_ulGroupID = ulGroupID;
	// 

	m_bOwner = true;


	m_pIDXCore->StartEnterMeetingRoom(m_ulRoomID, m_strUserID, "");
	

	return;
}
void vcdpMain::OnInviteIntoMeeting(const std::string& strDomain, const std::string& strRoomID, const std::string& strRoomName, const std::string& strInviterNodeID, const std::string& strInviterID, const std::string& strPassword, const std::string& strInviterName)
{
	if (m_pIDXCore == NULL)
	{
		return;
	}

	QString csRoomID;
	string newRoomId = strRoomID;
	csRoomID = strRoomID.c_str();
	int nPos = csRoomID.indexOf('@');
	if (nPos <= 0)
	{
		newRoomId = strRoomID + "@" + strDomain;
	}
	// �ܾ����
	// m_pIDXCore->RejectInvitation(m_strInviterDomain, m_szInviteRoomID, m_strInviterNodeID);
	// �������
	m_pIDXCore->AcceptInvitation(strDomain, newRoomId, strPassword);

}

void vcdpMain::SetCurRoomStatus(int nStatus) //0:�ޣ�1���ڻ��飬2����AView;
{
	m_nCurRoomStatus = nStatus;
	
}

int vcdpMain::GetCurRoomStatus(void)
{
	return m_nCurRoomStatus;
}

//������ʱ����
void vcdpMain::OnClickTempMetBtn()
{
	if (m_pIDXCore == NULL)
	{
		return;
	}
	m_pIDXCore->RequestCallTempMet();
}
//�򿪱�����Ƶ
void vcdpMain::OnClickLocalVedio()
{
	if (m_pIDXCore == NULL)
	{
		return;
	}

	if (m_bShowLocalVideo)
	{
		m_pIDXCore->CloseLocalVideo();
	} 
	else
	{
		m_pIDXCore->OpenLocalVideo();
	}

	m_bShowLocalVideo = !m_bShowLocalVideo;
	ui.localVedio->setText(m_bShowLocalVideo ? ("�ر���Ƶ") : ("����Ƶ"));
	
}

//�û�������
void vcdpMain::OnClickUserMenber()
{
	if (m_pIDXCore == NULL)
	{
		return;
	}

}
//��Ƶ��ʾ
void vcdpMain::OnClickVedioDisplay()
{
	if (m_pIDXCore == NULL)
	{
		return;
	}
}
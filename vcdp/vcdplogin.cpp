#include "vcdplogin.h"
#include "vcdpmain.h"

extern vcdpMain  *w;
VcdpLogin::VcdpLogin(QWidget *parent)
	: QWidget(parent)
	, m_bLogining(false)
{
	ui.setupUi(this);
	
	ui.serverLineEdit->setText(tr("192.168.0.16"));
	ui.portLineEdit->setText(tr("4222"));
	ui.userLineEdit->setText(tr("8010001"));
	ui.pwdLineEdit->setText(tr("1234567"));
}

VcdpLogin::~VcdpLogin()
{

}
//��¼����
void VcdpLogin::loginBtn()
{

	//w->show();
	if (ui.serverLineEdit->text().trimmed().isEmpty())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�������������ַ!"));
		return;
	}
	if (ui.portLineEdit->text().trimmed().isEmpty())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("������������˿�!"));
		return;
	}
	if (ui.userLineEdit->text().trimmed().isEmpty())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�������û���!"));
		return;
	}
	if (ui.pwdLineEdit->text().trimmed().isEmpty())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����������!"));
		return;
	}
	std::string strServerAddr = ui.serverLineEdit->text().toStdString();
	unsigned short usServerPort = ui.portLineEdit->text().toUInt();
	std::string strUserID = ui.userLineEdit->text().toStdString();
	std::string strPassword = ui.pwdLineEdit->text().toStdString();
	std::string strStatus = "online";
	if (ui.herCheckBox->isChecked())
	{
		strStatus = "hermit";

	}
	w->DoServerConnect(strServerAddr, usServerPort, strUserID, strPassword, strStatus);
	ui.loginBtn->setEnabled(false);
	m_bLogining = true;
}

//��ȡ��½״̬
QString VcdpLogin::GetInitStatus()
{
	if (ui.herCheckBox->isChecked())
	{
		return tr("hermit");
	}
	else
	{
		return tr("online");
	}
}

//���ߵ�½
void VcdpLogin::OnOffLoginBtn()
{
	close();
	w->showMaximized();
}
//��½��ʾ��Ϣ
void VcdpLogin::SetMessageText(QString qsText)
{
	ui.message->setText(qsText);
	
	
}
//ȡ���˳�
void VcdpLogin::OnClickCloseBtn()
{
	if (m_bLogining)
	{
		w->DoServerDisconnect();
		ui.loginBtn->setEnabled(true);
		m_bLogining = false;
	}
	else
	{
		exit(0);
	}

}
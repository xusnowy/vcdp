#ifndef VCDPLOGIN_H
#define VCDPLOGIN_H
//vcdp login
#include <QWidget>
#include "ui_vcdplogin.h"
#include <QMessageBox>
#include <QString>
class VcdpLogin : public QWidget
{
	Q_OBJECT

public:
	VcdpLogin(QWidget *parent = 0);
	~VcdpLogin();
	QString GetInitStatus();
	void SetMessageText(QString qsText);
private slots:
	void loginBtn();
	void OnClickCloseBtn(); 
	void OnOffLoginBtn();

private:
	Ui::vcdpLogin ui;
	bool m_bHermitStatus;
	bool m_bLogining;
};

#endif // VCDPLOGIN_H

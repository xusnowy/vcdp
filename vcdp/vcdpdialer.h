#ifndef VCDPDIALER_H
#define VCDPDIALER_H

#include <QWidget>
#include "ui_vcdpdialer.h"
//vcdp dialer
class VcdpDialer : public QWidget
{
	Q_OBJECT

public:
	VcdpDialer(QWidget *parent = 0);
	~VcdpDialer();
	QString strNum;
signals:
	void sendNum(QString);
private slots:
	void OnChangeNumEdit(QString strNumEdit);
	void OnClickBtn1();
	void OnClickBtn2();
	void OnClickBtn3();
	void OnClickBtn4();
	void OnClickBtn5();
	void OnClickBtn6();
	void OnClickBtn7();
	void OnClickBtn8();
	void OnClickBtn9();
	void OnClickBtn10();
	void OnClickBtn11();
	void OnClickBtn12();
	void OnClickCallBtn();
	void OnClickInviteMetBtn(); 
	void OnClickCleanNun();
	void OnClickCloseDialer();
private:
	Ui::VcdpDialer ui;
};

#endif // VCDPDIALER_H

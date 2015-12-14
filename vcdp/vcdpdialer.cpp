#include "vcdpdialer.h"
#include  <QRegExp>
VcdpDialer::VcdpDialer(QWidget *parent)
	: QWidget(parent)
	, strNum("")
{
	ui.setupUi(this);
	QRegExp regExp("(d+-)?(d{4}-?d{7}|d{3}-?d{8}|^d{7,8})(-d+)?");
	QRegExpValidator *pRegExp = new QRegExpValidator(regExp,this);
	ui.numEdit->setValidator(pRegExp);
}

VcdpDialer::~VcdpDialer()
{

}
void VcdpDialer::OnChangeNumEdit(QString strNumEdit)
{
	strNum = strNumEdit;
	ui.numEdit->setText(strNum);
	
}

void VcdpDialer::OnClickBtn1()
{
	strNum += "1";
	ui.numEdit->setText(strNum);
	ui.numEdit->setFocus();
}
void VcdpDialer::OnClickBtn2()
{
	strNum += "2";
	ui.numEdit->setText(strNum);
	ui.numEdit->setFocus();
}
void VcdpDialer::OnClickBtn3()
{
	strNum += "3";
	ui.numEdit->setText(strNum);
	ui.numEdit->setFocus();
}
void VcdpDialer::OnClickBtn4()
{
	strNum += "4";
	ui.numEdit->setText(strNum);
	ui.numEdit->setFocus();
}
void VcdpDialer::OnClickBtn5()
{
	strNum += "5";
	ui.numEdit->setText(strNum);
	ui.numEdit->setFocus();
}
void VcdpDialer::OnClickBtn6()
{
	strNum += "6";
	ui.numEdit->setText(strNum);
	ui.numEdit->setFocus();
}
void VcdpDialer::OnClickBtn7()

{
	strNum += "7";
	ui.numEdit->setText(strNum);
	ui.numEdit->setFocus();
}
void VcdpDialer::OnClickBtn8()
{
	strNum += "8";
	ui.numEdit->setText(strNum);
	ui.numEdit->setFocus();
}
void VcdpDialer::OnClickBtn9()
{
	strNum += "9";
	ui.numEdit->setText(strNum);
	ui.numEdit->setFocus();
}
void VcdpDialer::OnClickBtn10()
{
	strNum += "*";
	ui.numEdit->setText(strNum);
	ui.numEdit->setFocus();
}
void VcdpDialer::OnClickBtn11()
{
	strNum += "0";
	ui.numEdit->setText(strNum);
	ui.numEdit->setFocus();
}
void VcdpDialer::OnClickBtn12()
{
	strNum += "#";
	ui.numEdit->setText(strNum);
	ui.numEdit->setFocus();
}
void VcdpDialer::OnClickCallBtn()
{
	emit sendNum(strNum);
	ui.numEdit->setFocus();
}
void VcdpDialer::OnClickCleanNun()
{
	if (strNum != NULL)
	{
		strNum = strNum.left(strNum.length() - 1);
	}
	ui.numEdit->setText(strNum);
	ui.numEdit->setFocus();

}
void VcdpDialer::OnClickInviteMetBtn()
{
	ui.numEdit->setFocus();
}
void VcdpDialer::OnClickCloseDialer()
{

}
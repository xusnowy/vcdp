#include "vcdpusertab.h"

VcdpUserTab::VcdpUserTab(QWidget *parent)
	: QTabWidget(parent)
{
	QWidget *tab, *tab_2;
	tab = new QWidget();
	tab->setObjectName(QStringLiteral("tab_1"));
	this->addTab(tab, QString("����1"));
	tab_2 = new QWidget();
	tab_2->setObjectName(QStringLiteral("tab_2"));
	this->addTab(tab_2, QString("����2"));
	
}

VcdpUserTab::~VcdpUserTab()
{

}

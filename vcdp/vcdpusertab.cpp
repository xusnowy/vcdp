#include "vcdpusertab.h"
#include <QToolButton>
#include <QLabel>
#include <QGridLayout>
#include <QScrollArea>
VcdpUserTab::VcdpUserTab(QWidget *parent)
	: QTabWidget(parent)
{


	#if 0
QScrollArea *scrollArea = new QScrollArea(this);
	scrollArea->setObjectName(QStringLiteral("scrollArea"));
	//scrollArea->setWidgetResizable(true);
	scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	layout1->addWidget(scrollArea);
	QWidget *scrollTab1 = new QWidget();
	
	scrollTab1->setObjectName(QStringLiteral("scrollTab1"));
	scrollTab1->setGeometry(QRect(0, 0, 288, 1500));
	//scrollTab1->setMinimumSize(QSize(0,1000));
	scrollArea->setWidget(scrollTab1);
	
	layout1->addWidget(scrollArea, 0, 0, 1, 1);
	QWidget *tab, *tab_2;
	tab = new QWidget();
	
	tab->setObjectName(QStringLiteral("tab_1"));
	this->addTab(tab, QString("分组1"));
	tab->setLayout(layout1);
	QToolButton *tabBtn_1, *tabBtn_2;
	tabBtn_1 = new QToolButton(scrollTab1);
	tabBtn_1->setText("8010001");
	tabBtn_1->setIcon(QPixmap(":/vcdpMain/images/iptel.jpg"));
	tabBtn_1->setIconSize(QPixmap(":/vcdpMain/images/iptel.jpg").size());
	tabBtn_1->setAutoRaise(true);
	tabBtn_1->setFixedSize(70, 70);
	tabBtn_1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	tabBtn_1->show();
	connect(tabBtn_1, SIGNAL(clicked()), this, SLOT(test()));
	tabBtn_2 = new QToolButton(scrollTab1);
	tabBtn_2->setText("8010002");
	tabBtn_2->setIcon(QPixmap(":/vcdpMain/images/iptel.jpg"));
	tabBtn_2->setIconSize(QPixmap(":/vcdpMain/images/iptel.jpg").size());
	tabBtn_2->setAutoRaise(true);
	tabBtn_2->setFixedSize(70, 70);
	tabBtn_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	tabBtn_2->move(0, 1222);
	tabBtn_2->show();
	tab_2 = new QWidget();
	tab_2->setObjectName(QStringLiteral("tab_2"));

	this->addTab(tab_2, QString("分组2"));
	
#endif
	
}

VcdpUserTab::~VcdpUserTab()
{

}

void VcdpUserTab::test()
{
	int i = 0;
}

//增加会议组
void VcdpUserTab::addUserListMember()
{
	QGridLayout *layout1 = new QGridLayout(this);
	layout1->setSpacing(1);
	layout1->setObjectName(QStringLiteral("layout1"));
	layout1->setContentsMargins(0, 24, 0, 0);
	QWidget *tab, *tab_2;
	VcdpUserList *UserList;
	tab = new QWidget();

	tab->setObjectName(QStringLiteral("tab_1"));
	this->addTab(tab, QString("分组1"));
	tab->setLayout(layout1);
	UserList = new VcdpUserList(tab);
	UserList->addItem(new QListWidgetItem(QIcon(":/vcdpMain/images/iptel.jpg"), tr("8010001")));
	UserList->addItem(new QListWidgetItem(QIcon(":/vcdpMain/images/iptel.jpg"), tr("8010002")));
	UserList->addItem(new QListWidgetItem(QIcon(":/vcdpMain/images/iptel.jpg"), tr("8010004")));
	UserList->addItem(new QListWidgetItem(QIcon(":/vcdpMain/images/iptel.jpg"), tr("8010005")));
	UserList->addItem(new QListWidgetItem(QIcon(":/vcdpMain/images/iptel.jpg"), tr("8010006")));
	UserList->addItem(new QListWidgetItem(QIcon(":/vcdpMain/images/iptel.jpg"), tr("8010007")));
	layout1->addWidget(UserList);
	tab_2 = new QWidget();
	tab_2->setObjectName(QStringLiteral("tab_2"));

	this->addTab(tab_2, QString("分组2"));
	UserList->setViewMode(QListView::IconMode);
	UserList->setDragDropMode(QAbstractItemView::DragOnly);
}

void VcdpUserTab::addMetListMember()
{
	QGridLayout *layout1 = new QGridLayout(this);
	layout1->setSpacing(1);
	layout1->setObjectName(QStringLiteral("layout1"));
	layout1->setContentsMargins(0, 24, 0, 0);
	QWidget *tab, *tab_2;
	VcdpUserList *UserList;
	tab = new QWidget();

	tab->setObjectName(QStringLiteral("tab_1"));
	this->addTab(tab, QString("临时会议1"));
	tab->setLayout(layout1);
	UserList = new VcdpUserList(tab);
	//UserList->addItem("123");
	layout1->addWidget(UserList);
	tab_2 = new QWidget();
	tab_2->setObjectName(QStringLiteral("tab_2"));

	this->addTab(tab_2, QString("临时会议2"));
	UserList->setDragDropMode(QAbstractItemView::DropOnly);
}
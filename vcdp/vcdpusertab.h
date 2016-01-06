#ifndef VCDPUSERTAB_H
#define VCDPUSERTAB_H

#include <QTabWidget>
#include "vcdpuserlist.h"
#pragma execution_character_set("utf-8")

class VcdpUserTab : public QTabWidget
{
	Q_OBJECT

public:
	VcdpUserTab(QWidget *parent);
	~VcdpUserTab();
	void addUserListMember();
	void addMetListMember();
public slots:
	void test();
private:
	
};

#endif // VCDPUSERTAB_H

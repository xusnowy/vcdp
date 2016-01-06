#ifndef VCDPTREEVIEW_H
#define VCDPTREEVIEW_H

#include <QTreeView>
#include <QList>
#include <QStandardItem>
#include <QMouseEvent>
class VcdpTreeView : public QTreeView
{
	Q_OBJECT

public:
	VcdpTreeView(QWidget *parent);
	~VcdpTreeView();
	void iteratorOverItems();
	//QList<QStandardItem*> returnTheItenms();
	void mouseDoubleClickEvent(QMouseEvent *event);
signals:
	void sendNumtoMet(const QString strNum);
private:
	QStandardItemModel *model;
};

#endif // VCDPTREEVIEW_H

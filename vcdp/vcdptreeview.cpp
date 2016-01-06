#include "vcdptreeview.h"
#include <QDebug>
VcdpTreeView::VcdpTreeView(QWidget *parent)
	: QTreeView(parent)
{
	model = new QStandardItemModel(4, 2);
	model->setHeaderData(0, Qt::Horizontal, "name");
	model->setHeaderData(1, Qt::Horizontal, "num");

	QStandardItem *item1 = new QStandardItem("801");
	QStandardItem *item2 = new QStandardItem("802");
	model->setItem(0, 0, item1);
	model->setItem(1, 0, item2);

	QStandardItem *item3 = new QStandardItem("803");
	item2->appendRow(item3);

	QModelIndex myparent;
	for (int i = 0; i < 3;i++)
	{
		myparent = model->index(0, 0, myparent);
		model->insertRows(0, 1, myparent);
		model->insertColumns(0, 1, myparent);
		QModelIndex index = model->index(0, 0, myparent);
		model->setData(index, i);
	}
	this->setModel(model);
}
VcdpTreeView::~VcdpTreeView()
{

}

//输出所有的单元格
void VcdpTreeView::iteratorOverItems()
{
	//QList<QStandardItem*> list = this->returnTheItenms();
	
}

void VcdpTreeView::mouseDoubleClickEvent(QMouseEvent *event)
{
	if (event->button()==Qt::LeftButton)
	{
		QModelIndex index = currentIndex();
		QString num = "8010002";
		emit sendNumtoMet(num);
		//qDebug << index.data().toString();
	}
}
/********************************************************************************
** Form generated from reading UI file 'vcdpmain.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VCDPMAIN_H
#define UI_VCDPMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vcdpMainClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *mainLayout;
    QVBoxLayout *verticalLayout_2;
    QWidget *widgetMain;
    QGridLayout *gridLayout;
    QWidget *widgetMet;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_3;
    QPushButton *dialerBtn;
    QPushButton *tempMet;
    QPushButton *localVedio;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_10;
    QSpacerItem *horizontalSpacer;
    QPushButton *metDisplay;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *vcdpMainClass)
    {
        if (vcdpMainClass->objectName().isEmpty())
            vcdpMainClass->setObjectName(QStringLiteral("vcdpMainClass"));
        vcdpMainClass->resize(823, 617);
        centralWidget = new QWidget(vcdpMainClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mainLayout = new QHBoxLayout();
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widgetMain = new QWidget(centralWidget);
        widgetMain->setObjectName(QStringLiteral("widgetMain"));
        gridLayout = new QGridLayout(widgetMain);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout_2->addWidget(widgetMain);

        widgetMet = new QWidget(centralWidget);
        widgetMet->setObjectName(QStringLiteral("widgetMet"));
        gridLayout_2 = new QGridLayout(widgetMet);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));

        verticalLayout_2->addWidget(widgetMet);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);

        mainLayout->addLayout(verticalLayout_2);

        mainLayout->setStretch(0, 5);

        verticalLayout->addLayout(mainLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        dialerBtn = new QPushButton(centralWidget);
        dialerBtn->setObjectName(QStringLiteral("dialerBtn"));

        gridLayout_3->addWidget(dialerBtn, 0, 0, 1, 1);

        tempMet = new QPushButton(centralWidget);
        tempMet->setObjectName(QStringLiteral("tempMet"));

        gridLayout_3->addWidget(tempMet, 0, 1, 1, 1);

        localVedio = new QPushButton(centralWidget);
        localVedio->setObjectName(QStringLiteral("localVedio"));

        gridLayout_3->addWidget(localVedio, 0, 2, 1, 1);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_3->addWidget(pushButton_8, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        gridLayout_3->addWidget(pushButton_10, 0, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 6, 1, 1);

        metDisplay = new QPushButton(centralWidget);
        metDisplay->setObjectName(QStringLiteral("metDisplay"));

        gridLayout_3->addWidget(metDisplay, 0, 7, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        verticalLayout->setStretch(0, 20);
        verticalLayout->setStretch(1, 1);
        vcdpMainClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(vcdpMainClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 823, 23));
        vcdpMainClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(vcdpMainClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        vcdpMainClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(vcdpMainClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        vcdpMainClass->setStatusBar(statusBar);

        retranslateUi(vcdpMainClass);
        QObject::connect(tempMet, SIGNAL(clicked()), vcdpMainClass, SLOT(OnClickTempMetBtn()));
        QObject::connect(localVedio, SIGNAL(clicked()), vcdpMainClass, SLOT(OnClickLocalVedio()));
        QObject::connect(dialerBtn, SIGNAL(clicked()), vcdpMainClass, SLOT(OnClickDialerBtn()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), vcdpMainClass, SLOT(OnClickQuitMet()));
        QObject::connect(metDisplay, SIGNAL(clicked()), vcdpMainClass, SLOT(OnClickMetDisplay()));

        QMetaObject::connectSlotsByName(vcdpMainClass);
    } // setupUi

    void retranslateUi(QMainWindow *vcdpMainClass)
    {
        vcdpMainClass->setWindowTitle(QApplication::translate("vcdpMainClass", "vcdpMain", 0));
        dialerBtn->setText(QApplication::translate("vcdpMainClass", "\346\213\250\345\217\267\347\233\230", 0));
        tempMet->setText(QApplication::translate("vcdpMainClass", "\344\270\264\346\227\266\344\274\232\350\256\256", 0));
        localVedio->setText(QApplication::translate("vcdpMainClass", "\346\211\223\345\274\200\350\247\206\351\242\221", 0));
        pushButton_8->setText(QApplication::translate("vcdpMainClass", "\351\200\200\345\207\272\344\274\232\350\256\256", 0));
        pushButton_10->setText(QApplication::translate("vcdpMainClass", "\346\214\211\351\224\256\345\256\232\345\210\266", 0));
        metDisplay->setText(QApplication::translate("vcdpMainClass", "\344\274\232\350\256\256\346\230\276\347\244\272", 0));
    } // retranslateUi

};

namespace Ui {
    class vcdpMainClass: public Ui_vcdpMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VCDPMAIN_H

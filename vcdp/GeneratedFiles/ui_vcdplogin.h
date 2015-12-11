/********************************************************************************
** Form generated from reading UI file 'vcdplogin.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VCDPLOGIN_H
#define UI_VCDPLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vcdpLogin
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *serverLineEdit;
    QLineEdit *portLineEdit;
    QLineEdit *userLineEdit;
    QLineEdit *pwdLineEdit;
    QCheckBox *herCheckBox;
    QPushButton *loginBtn;
    QPushButton *closeBtn;
    QLabel *message;
    QPushButton *offLoginBtn;

    void setupUi(QWidget *vcdpLogin)
    {
        if (vcdpLogin->objectName().isEmpty())
            vcdpLogin->setObjectName(QStringLiteral("vcdpLogin"));
        vcdpLogin->resize(330, 146);
        label = new QLabel(vcdpLogin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(9, 9, 48, 16));
        label_2 = new QLabel(vcdpLogin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 9, 36, 16));
        label_3 = new QLabel(vcdpLogin);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(9, 35, 48, 16));
        label_4 = new QLabel(vcdpLogin);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(9, 61, 60, 16));
        serverLineEdit = new QLineEdit(vcdpLogin);
        serverLineEdit->setObjectName(QStringLiteral("serverLineEdit"));
        serverLineEdit->setGeometry(QRect(75, 9, 99, 20));
        portLineEdit = new QLineEdit(vcdpLogin);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));
        portLineEdit->setGeometry(QRect(222, 9, 99, 20));
        userLineEdit = new QLineEdit(vcdpLogin);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));
        userLineEdit->setGeometry(QRect(75, 35, 99, 20));
        pwdLineEdit = new QLineEdit(vcdpLogin);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(75, 61, 99, 20));
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        herCheckBox = new QCheckBox(vcdpLogin);
        herCheckBox->setObjectName(QStringLiteral("herCheckBox"));
        herCheckBox->setGeometry(QRect(75, 87, 59, 16));
        loginBtn = new QPushButton(vcdpLogin);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setGeometry(QRect(140, 110, 75, 23));
        closeBtn = new QPushButton(vcdpLogin);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setGeometry(QRect(230, 110, 75, 23));
        message = new QLabel(vcdpLogin);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(150, 85, 161, 20));
        offLoginBtn = new QPushButton(vcdpLogin);
        offLoginBtn->setObjectName(QStringLiteral("offLoginBtn"));
        offLoginBtn->setGeometry(QRect(50, 110, 75, 23));

        retranslateUi(vcdpLogin);
        QObject::connect(loginBtn, SIGNAL(clicked()), vcdpLogin, SLOT(loginBtn()));
        QObject::connect(closeBtn, SIGNAL(clicked()), vcdpLogin, SLOT(OnClickCloseBtn()));
        QObject::connect(offLoginBtn, SIGNAL(clicked()), vcdpLogin, SLOT(OnOffLoginBtn()));

        QMetaObject::connectSlotsByName(vcdpLogin);
    } // setupUi

    void retranslateUi(QWidget *vcdpLogin)
    {
        vcdpLogin->setWindowTitle(QApplication::translate("vcdpLogin", "vcdpLogin", 0));
        label->setText(QApplication::translate("vcdpLogin", "\346\234\215\345\212\241\345\231\250\357\274\232", 0));
        label_2->setText(QApplication::translate("vcdpLogin", "\347\253\257\345\217\243\357\274\232", 0));
        label_3->setText(QApplication::translate("vcdpLogin", "\347\224\250\346\210\267ID\357\274\232", 0));
        label_4->setText(QApplication::translate("vcdpLogin", "\347\224\250\346\210\267\345\257\206\347\240\201\357\274\232", 0));
        herCheckBox->setText(QApplication::translate("vcdpLogin", "Hermit", 0));
        loginBtn->setText(QApplication::translate("vcdpLogin", "\347\231\273\345\275\225", 0));
        closeBtn->setText(QApplication::translate("vcdpLogin", "\345\217\226\346\266\210", 0));
        message->setText(QApplication::translate("vcdpLogin", "message", 0));
        offLoginBtn->setText(QApplication::translate("vcdpLogin", "\347\246\273\347\272\277\347\231\273\351\231\206", 0));
    } // retranslateUi

};

namespace Ui {
    class vcdpLogin: public Ui_vcdpLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VCDPLOGIN_H

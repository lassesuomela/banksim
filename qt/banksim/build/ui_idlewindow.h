/********************************************************************************
** Form generated from reading UI file 'idlewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDLEWINDOW_H
#define UI_IDLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IdleWindow
{
public:
    QWidget *centralwidget;
    QLabel *otsikko;
    QPushButton *nappi;

    void setupUi(QMainWindow *IdleWindow)
    {
        if (IdleWindow->objectName().isEmpty())
            IdleWindow->setObjectName(QString::fromUtf8("IdleWindow"));
        IdleWindow->resize(800, 600);
        centralwidget = new QWidget(IdleWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        otsikko = new QLabel(centralwidget);
        otsikko->setObjectName(QString::fromUtf8("otsikko"));
        otsikko->setGeometry(QRect(240, 100, 371, 111));
        QFont font;
        font.setPointSize(48);
        otsikko->setFont(font);
        nappi = new QPushButton(centralwidget);
        nappi->setObjectName(QString::fromUtf8("nappi"));
        nappi->setGeometry(QRect(320, 260, 151, 61));
        IdleWindow->setCentralWidget(centralwidget);

        retranslateUi(IdleWindow);

        QMetaObject::connectSlotsByName(IdleWindow);
    } // setupUi

    void retranslateUi(QMainWindow *IdleWindow)
    {
        IdleWindow->setWindowTitle(QCoreApplication::translate("IdleWindow", "IdleWindow", nullptr));
        otsikko->setText(QCoreApplication::translate("IdleWindow", "Sy\303\266t\303\244 kortti", nullptr));
        nappi->setText(QCoreApplication::translate("IdleWindow", "nappi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IdleWindow: public Ui_IdleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDLEWINDOW_H

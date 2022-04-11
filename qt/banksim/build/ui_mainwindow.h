/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QStackedWidget *stackedWidget;
    QWidget *sivu1;
    QToolButton *kirjaudu_ulos;
    QToolButton *tilitapahtumat;
    QToolButton *talletus;
    QToolButton *nosto;
    QWidget *sivu2;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        stackedWidget = new QStackedWidget(MainWindow);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 800, 600));
        sivu1 = new QWidget();
        sivu1->setObjectName(QString::fromUtf8("sivu1"));
        kirjaudu_ulos = new QToolButton(sivu1);
        kirjaudu_ulos->setObjectName(QString::fromUtf8("kirjaudu_ulos"));
        kirjaudu_ulos->setGeometry(QRect(20, 450, 371, 71));
        QFont font;
        font.setPointSize(22);
        kirjaudu_ulos->setFont(font);
        tilitapahtumat = new QToolButton(sivu1);
        tilitapahtumat->setObjectName(QString::fromUtf8("tilitapahtumat"));
        tilitapahtumat->setGeometry(QRect(410, 450, 371, 71));
        tilitapahtumat->setFont(font);
        talletus = new QToolButton(sivu1);
        talletus->setObjectName(QString::fromUtf8("talletus"));
        talletus->setGeometry(QRect(440, 100, 261, 231));
        talletus->setFont(font);
        nosto = new QToolButton(sivu1);
        nosto->setObjectName(QString::fromUtf8("nosto"));
        nosto->setGeometry(QRect(110, 100, 261, 231));
        nosto->setFont(font);
        stackedWidget->addWidget(sivu1);
        sivu2 = new QWidget();
        sivu2->setObjectName(QString::fromUtf8("sivu2"));
        stackedWidget->addWidget(sivu2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
        kirjaudu_ulos->setText(QCoreApplication::translate("MainWindow", "mee pois :D", nullptr));
        tilitapahtumat->setText(QCoreApplication::translate("MainWindow", "Tilitapahtumat", nullptr));
        talletus->setText(QCoreApplication::translate("MainWindow", "Talletus", nullptr));
        nosto->setText(QCoreApplication::translate("MainWindow", "Nosto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

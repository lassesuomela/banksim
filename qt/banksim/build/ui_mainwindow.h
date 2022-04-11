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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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
    QToolButton *takaisin;
    QLineEdit *lineEdit;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        stackedWidget = new QStackedWidget(MainWindow);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 800, 600));
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        stackedWidget->setFont(font);
        sivu1 = new QWidget();
        sivu1->setObjectName(QString::fromUtf8("sivu1"));
        kirjaudu_ulos = new QToolButton(sivu1);
        kirjaudu_ulos->setObjectName(QString::fromUtf8("kirjaudu_ulos"));
        kirjaudu_ulos->setGeometry(QRect(20, 480, 371, 71));
        QFont font1;
        font1.setPointSize(22);
        font1.setStyleStrategy(QFont::PreferAntialias);
        kirjaudu_ulos->setFont(font1);
        tilitapahtumat = new QToolButton(sivu1);
        tilitapahtumat->setObjectName(QString::fromUtf8("tilitapahtumat"));
        tilitapahtumat->setGeometry(QRect(410, 480, 371, 71));
        tilitapahtumat->setFont(font1);
        talletus = new QToolButton(sivu1);
        talletus->setObjectName(QString::fromUtf8("talletus"));
        talletus->setGeometry(QRect(440, 100, 261, 231));
        talletus->setFont(font1);
        nosto = new QToolButton(sivu1);
        nosto->setObjectName(QString::fromUtf8("nosto"));
        nosto->setGeometry(QRect(110, 100, 261, 231));
        nosto->setFont(font1);
        stackedWidget->addWidget(sivu1);
        sivu2 = new QWidget();
        sivu2->setObjectName(QString::fromUtf8("sivu2"));
        takaisin = new QToolButton(sivu2);
        takaisin->setObjectName(QString::fromUtf8("takaisin"));
        takaisin->setGeometry(QRect(30, 480, 371, 71));
        takaisin->setFont(font1);
        lineEdit = new QLineEdit(sivu2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(200, 190, 401, 91));
        QFont font2;
        font2.setPointSize(13);
        font2.setStyleStrategy(QFont::PreferAntialias);
        lineEdit->setFont(font2);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_6 = new QPushButton(sivu2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(420, 360, 91, 71));
        pushButton_7 = new QPushButton(sivu2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(30, 360, 91, 71));
        pushButton_8 = new QPushButton(sivu2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(160, 360, 91, 71));
        pushButton_9 = new QPushButton(sivu2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(290, 360, 91, 71));
        pushButton_10 = new QPushButton(sivu2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(550, 360, 91, 71));
        pushButton_11 = new QPushButton(sivu2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(670, 360, 91, 71));
        stackedWidget->addWidget(sivu2);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
        kirjaudu_ulos->setText(QCoreApplication::translate("MainWindow", "mee pois :D", nullptr));
        tilitapahtumat->setText(QCoreApplication::translate("MainWindow", "Tilitapahtumat", nullptr));
        talletus->setText(QCoreApplication::translate("MainWindow", "Talletus", nullptr));
        nosto->setText(QCoreApplication::translate("MainWindow", "Nosto", nullptr));
        takaisin->setText(QCoreApplication::translate("MainWindow", "takaisin", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "60", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "200", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "500", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

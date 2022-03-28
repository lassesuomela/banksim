#include "pincodedll.h"

PinCodeDLL::PinCodeDLL(QWidget * parent) : QWidget (parent)
{

    pinCodeUI = new PinCodeUI(parent);
    pinCodeUI->show();
    qDebug() << "PinCodeDLL called pinCodeUI->show()";

    connect(pinCodeUI, SIGNAL(sendPinCode(QString)), this, SLOT(getPinFromDLL(QString)));
    connect(this, SIGNAL(triesToDLL(int)), pinCodeUI, SLOT(getTries(int)));

}

PinCodeDLL::~PinCodeDLL()
{
    delete pinCodeUI;
    pinCodeUI = nullptr;
    qDebug() << "PinCodeDLL destroyed";
}

void PinCodeDLL::getPinFromDLL(QString pin)
{
    qDebug() << "Got signal from Pin code UI";
    qDebug() << "Emitting Pin code to exe";

    emit pinToExe(pin);
}

void PinCodeDLL::getTriesFromEXE(int tries)
{
    emit triesToDLL(tries);
}

#include "pincodedll.h"

PinCodeDLL::PinCodeDLL(QWidget * parent) : QWidget (parent)
{

    pinCodeUI = new PinCodeUI(parent);

    // flags to prevent window resizing and to disable title bar buttons
    pinCodeUI->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::MSWindowsFixedSizeDialogHint);

    // this disables all actions in parent window
    pinCodeUI->setModal(true);

    connect(pinCodeUI, SIGNAL(sendPinCode(QString)), this, SLOT(getPinFromDLL(QString)));
    connect(this, SIGNAL(triesToDLL(int)), pinCodeUI, SLOT(getTries(int)));
    connect(pinCodeUI, SIGNAL(autoTimeoutSignal()), this, SLOT(getAutoTimeOutSlot()));
}

PinCodeDLL::~PinCodeDLL()
{
    disconnect(pinCodeUI, SIGNAL(sendPinCode(QString)), this, SLOT(getPinFromDLL(QString)));
    disconnect(this, SIGNAL(triesToDLL(int)), pinCodeUI, SLOT(getTries(int)));
    disconnect(pinCodeUI, SIGNAL(autoTimeoutSignal()), this, SLOT(getAutoTimeOutSlot()));
    delete pinCodeUI;
    pinCodeUI = nullptr;

    qDebug() << "PinCodeDLL destroyed";
}

void PinCodeDLL::ShowWindow()
{
    pinCodeUI->show();

    qDebug() << "PinCodeDLL called pinCodeUI->show()";
}

void PinCodeDLL::getAutoTimeOutSlot()
{
    emit autoTimeOutToExe();
}

void PinCodeDLL::getPinFromDLL(QString pin)
{
    qDebug() << "Got signal from Pin code UI, Emitting Pin code to exe";

    emit pinToExe(pin);
    pin = "";
}

void PinCodeDLL::getTriesFromEXE(int tries)
{
    emit triesToDLL(tries);
}

void PinCodeDLL::closeSignalSlot()
{
    pinCodeUI->close();
}

#include "pincodedll.h"

PinCodeDLL::PinCodeDLL(QWidget * parent) : QWidget (parent)
{

    pinCodeUI = new PinCodeUI(parent);
    pinCodeUI->show();
    qDebug() << "PinCodeDLL called pinCodeUI->show()";
}

PinCodeDLL::~PinCodeDLL()
{
    delete pinCodeUI;
    pinCodeUI = nullptr;
    qDebug() << "PinCodeDLL destroyed";
}

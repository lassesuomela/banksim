#ifndef PINCODEDLL_H
#define PINCODEDLL_H
#include <QtWidgets/QWidget>
#include <QDebug>

#include "pinCodeDLL_global.h"
#include "pincodeui.h"

class PINCODEDLL_EXPORT PinCodeDLL : public QWidget
{
    Q_OBJECT
public:
    PinCodeDLL(QWidget * parent = nullptr);
    ~PinCodeDLL();
private:
    PinCodeUI * pinCodeUI;
};

#endif // PINCODEDLL_H

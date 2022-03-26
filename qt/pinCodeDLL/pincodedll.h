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
signals:
    void pinToExe(QString);
    void triesToDLL();

public slots:
    void getPinFromDLL(QString);
};

#endif // PINCODEDLL_H

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

    void ShowWindow();
private:
    PinCodeUI * pinCodeUI;
signals:
    void pinToExe(QString);
    void triesToDLL(int);
    void autoTimeOutToExe();
private slots:
    void getAutoTimeOutSlot();
public slots:
    void getPinFromDLL(QString);
    void getTriesFromEXE(int);
    void closeSignalSlot();
};

#endif // PINCODEDLL_H

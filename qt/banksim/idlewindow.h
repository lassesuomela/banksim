#ifndef IDLEWINDOW_H
#define IDLEWINDOW_H
#include "dllserialport.h"
#include "pincodedll.h"
#include "mainwindow.h"
#include "dllrestapi.h"

#include <QMainWindow>
#include <QString>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class IdleWindow; }
QT_END_NAMESPACE

class IdleWindow : public QMainWindow
{
    Q_OBJECT

public:
    IdleWindow(QWidget *parent = nullptr);
    ~IdleWindow();

public slots:
    void PinSlot(QString);
    void Tries(int);

signals:
    void SendTries(int);
    void sendCloseSignal();

private slots:
    void on_nappi_clicked();

private:
    Ui::IdleWindow *ui;
    DLLSerialPort *serialPort;
    PinCodeDLL *pinCodeDLL;
    MainWindow *mainWindow;
    DLLRestAPI *dllRestApi;
    void HandleCard();
    char* rfid;
    QString pinCode;
    int tries;
    bool CheckInfo(int, char*, QString);

};
#endif // IDLEWINDOW_H

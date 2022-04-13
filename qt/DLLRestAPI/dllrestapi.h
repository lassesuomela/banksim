#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H
#include "dllrestapiengine.h"
#include "DLLRestAPI_global.h"
//saldo set get, log, owner name, kortin tyyppi

class DLLRESTAPI_EXPORT DLLRestAPI : public QObject
{
    Q_OBJECT
public:
    DLLRestAPI(QObject *parent = nullptr);
    ~DLLRestAPI();
    void UpdateLogs(int);
    QString logData[10][4];
    void GetTriesFromApi(QString card_number);
    void UpdateBalance();
    void getLogsByPage(int);
private:
    DLLRestAPIEngine* engine;

signals:
    void InfoSignal(double balance, QString acc_name, QString fname, QString lname, QString card_number, QString card_type, QByteArray profileData);
    void SendTriesToExe(int tries);
    void StatusToExe(QString);
    void logsUpdatedSignal();

private slots:
    void GetTriesSlot(int tries);
    void GetInfo();
    void LogOutSlot();
public slots:
    void LoginSlot(QString, QString);
    void LoginStatusSlot(QString);
    void GetLogs10(); //argument = 0 for getting older logs (page++), -1 when wanting new logs (page--), else page = int
};

#endif // DLLRESTAPI_H

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
    void Login(QString, QString);
    void GetLogs10(int); //argument = 0 for getting older logs (page++), -1 when wanting new logs (page--), else page = int
    void UpdateLogs(int);
    void GetInfo();
    QString logData[10][4];

private:
    DLLRestAPIEngine* engine;


signals:
    void InfoSignal(double balance, QString acc_name, QString fname, QString lname, QString card_number);
};

#endif // DLLRESTAPI_H

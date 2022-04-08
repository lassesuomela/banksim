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
    void GetUserInfo();
    void GetCardInfo();
    void GetAccountInfo();
    void GetLogs1();
    void UpdateLogs(int);
    void GetLastLogs();
    void GetNextLogs();

    void BrowseLogs(bool); //true to go to older logs, false to go to newer logs
private:
    DLLRestAPIEngine* engine;
    int gotLast = 0;
};

#endif // DLLRESTAPI_H

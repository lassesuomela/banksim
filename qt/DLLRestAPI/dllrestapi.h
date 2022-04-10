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
    void GetLogs1(int); //argument = 0 for getting older logs (page++), -1 when wanting new logs (page--), else page = int
    void UpdateLogs(int);
    QString logData[10][4];


private:
    DLLRestAPIEngine* engine;
    int gotLast = 0;


};

#endif // DLLRESTAPI_H

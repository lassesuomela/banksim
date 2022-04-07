#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H
#include "dllrestapiengine.h"
#include "DLLRestAPI_global.h"

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
private:
    DLLRestAPIEngine* engine;
};

#endif // DLLRESTAPI_H

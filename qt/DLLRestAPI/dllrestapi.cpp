#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI(QObject *parent) : QObject(parent)
{
    qDebug()<<"interface constructor";
    engine = new DLLRestAPIEngine;
}

DLLRestAPI::~DLLRestAPI()
{
    delete engine;
    engine = nullptr;
}

void DLLRestAPI::Login(QString email, QString password)
{
    engine->Login(email, password);
}

void DLLRestAPI::GetUserInfo()
{
    engine->GetUserInfo();
}

void DLLRestAPI::GetCardInfo()
{
    engine->GetCardInfo();
}

void DLLRestAPI::GetAccountInfo()
{
    engine->GetAccountInfo();
}

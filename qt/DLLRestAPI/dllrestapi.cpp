#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI(QObject *parent) : QObject(parent)
{
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

void DLLRestAPI::GetLogs1()
{
    engine->GetLogs();
}

void DLLRestAPI::UpdateLogs(int i)
{
    engine->CreateLog(i);
}

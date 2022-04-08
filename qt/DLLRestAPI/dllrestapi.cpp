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

void DLLRestAPI::GetLastLogs()
{
    engine->GetLastLogs();
}
void DLLRestAPI::GetNextLogs()
{
    engine->GetNextLogs();
}

void DLLRestAPI::BrowseLogs(bool wantOlder)
{
    if(wantOlder){
        if(gotLast != 0)
            if(engine->logs_curret_page < engine->logs_total_pages)
                engine->logs_curret_page++;
        engine->GetNextLogs();
        gotLast = 1;
    }else{
        if(gotLast != 0)
            if(engine->logs_curret_page > 0)
                engine->logs_curret_page--;
        engine->GetNextLogs();
        gotLast = 1;
    }

}

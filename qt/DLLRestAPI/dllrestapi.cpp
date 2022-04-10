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

void DLLRestAPI::GetLogs1(int page)
{
    switch (page) {
        case 0:
            engine->logs_curret_page = engine->logs_curret_page+1;
            break;
        case -1:
            engine->logs_curret_page = engine->logs_curret_page-1;
            break;
    default:
        engine->logs_curret_page = page;
    }
    engine->GetLogs();

    for(int i = 0; i<10; i++){
        logData[i][0] = engine->idSignal[i];
        logData[i][1] = engine->dateSignal[i];
        logData[i][2] = engine->eventSignal[i];
        logData[i][3] = engine->amountSignal[i];
    }

    qDebug()<<"ran GetLogs";
}

void DLLRestAPI::UpdateLogs(int i)
{
    engine->CreateLog(i);
}

/*
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
*/

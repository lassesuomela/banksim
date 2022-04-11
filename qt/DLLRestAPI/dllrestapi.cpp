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
    engine->Login(email, password); //bad function names, use card_number and pin
}

void DLLRestAPI::GetLogs10(int page)
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
}

void DLLRestAPI::UpdateLogs(int i)
{
    engine->CreateLog(i);
}

void DLLRestAPI::GetInfo()
{
    emit InfoSignal(engine->account_balance,engine->account_name,engine->fname,engine->lname,engine->card_number,engine->card_type);
}

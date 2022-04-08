#include "dllrestapiengine.h"
//get in order
//login->userinfo->card info->account info->logs
DLLRestAPIEngine::DLLRestAPIEngine(QObject * parent) : QObject(parent)
{

}

DLLRestAPIEngine::~DLLRestAPIEngine()
{

}

void DLLRestAPIEngine::Login(QString email, QString password)
{
    qDebug()<<"login kutsuttu";
    card_number = email;
    QJsonObject jsonObj;
    jsonObj.insert("card_number",email);
    jsonObj.insert("pin",password);
    manager = new QNetworkAccessManager(this);
    QNetworkRequest request(base_url+"api/card/auth");
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));
    reply = manager->post(request, QJsonDocument(jsonObj).toJson());

}

void DLLRestAPIEngine::loginSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    status = json_obj["status"].toString();
    if(status == "success"){
    auth =json_obj["token"].toString();
    auth = "Bearer "+auth;
    authByteArr = auth.toUtf8();
    qDebug()<<status<<auth<<Qt::endl;
    }else{
        qDebug()<<"Wrong pin code"<<json_obj;
    }
    reply->deleteLater();
    manager->deleteLater();
}


void DLLRestAPIEngine::GetUserInfo()
{
    QJsonObject jsonObj;
    QNetworkRequest request(base_url+"api/user/info");

    manager = new QNetworkAccessManager(this);
    request.setRawHeader("Authorization", authByteArr);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getUserInfoSlot(QNetworkReply*)));

    reply = manager->get(request);
}

void DLLRestAPIEngine::getUserInfoSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    fname = json_obj["fname"].toString();
    lname = json_obj["lname"].toString();
    address = json_obj["address"].toString();
    email = json_obj["email"].toString();
    phone = json_obj["phone"].toString();

    qDebug()<<fname<<lname<<address<<email<<phone;
    reply->deleteLater();
    manager->deleteLater();
}


void DLLRestAPIEngine::GetCardInfo()
{
    QJsonObject jsonObj;
    QNetworkRequest request(base_url+"api/card/"+card_number);
    manager = new QNetworkAccessManager(this);
    request.setRawHeader("Authorization", authByteArr);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getCardInfoSlot(QNetworkReply*)));

    reply = manager->get(request);
}

void DLLRestAPIEngine::getCardInfoSlot(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    //qDebug()<< json_array[].toString()<<"account id from asfka";
    qDebug()<<json_array<<"json"<<Qt::endl;

    foreach(const QJsonValue &value, json_array){
        QJsonObject obj = value.toObject();
        account_id_int = obj["account_ID"].toInt();
    }
    qDebug()<<account_id_int<<"got card info"<<Qt::endl;

    reply->deleteLater();
    manager->deleteLater();
}


void DLLRestAPIEngine::GetAccountInfo()
{

    QString requestStr = QStringLiteral("api/account/%1").arg(account_id_int);
    qDebug()<<requestStr<<"req str"<<Qt::endl;
    QNetworkRequest request(base_url+requestStr);
    request.setRawHeader("Authorization", authByteArr);
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getAccountInfoSlot(QNetworkReply*)));

    reply = manager->get(request);
}

void DLLRestAPIEngine::getAccountInfoSlot(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    qDebug()<<json_array<<"json"<<Qt::endl;

    foreach(const QJsonValue &value, json_array){
        QJsonObject obj = value.toObject();
        account_name = obj["name"].toString();
        account_balance = obj["balance"].toDouble();
    }

    qDebug()<<account_balance<<account_name<<"parsed data";
    reply->deleteLater();
    manager->deleteLater();
}


void DLLRestAPIEngine::GetLogs()
{
    QJsonObject jsonObj;
    QNetworkRequest request(base_url+"api/logs/getByCardNumber/"+card_number);
    manager = new QNetworkAccessManager(this);
    request.setRawHeader("Authorization", authByteArr);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getLogsSlot(QNetworkReply*)));

    reply = manager->get(request);
}

void DLLRestAPIEngine::getLogsSlot(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    qDebug()<<json_array<<"json"<<Qt::endl;

    foreach(const QJsonValue &value, json_array){
        QJsonObject obj = value.toObject();
        logs_amount_list << QString::number(obj["amount"].toInt());
        logs_id_list << QString::number(obj["log_ID"].toInt());
        logs_date_list << obj["date"].toString();
        logs_event_list << obj["event"].toString();
    }
    logs_count = json_array.size();
    if(logs_total_pages%10 == 0){
        logs_total_pages = logs_count/10-1;
    }else{
        logs_total_pages = logs_count/10;
    }
    qDebug()<<json_array.size()<<"<- sixe of array";
    for(int i = 0; i < logs_amount_list.size(); i++){
        qDebug()<<logs_amount_list.at(i);
        qDebug()<<logs_id_list.at(i);
        qDebug()<<logs_date_list.at(i);
        qDebug()<<logs_event_list.at(i);
    }


    reply->deleteLater();
    manager->deleteLater();
}






void DLLRestAPIEngine::CreateLog(int amount)
{
    QJsonObject jsonObj;
    jsonObj.insert("amount",amount);
    jsonObj.insert("card_number",card_number);
    manager = new QNetworkAccessManager(this);
    QNetworkRequest request(base_url+"api/logs/create");
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setRawHeader("Authorization", authByteArr);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(createLogSlot(QNetworkReply*)));
    qDebug()<<jsonObj<<"request body";
    reply = manager->post(request, QJsonDocument(jsonObj).toJson());

}

void DLLRestAPIEngine::GetLastLogs()
{
    if(logs_curret_page < logs_total_pages && logs_curret_page > -1){
        for(int i = 0; i<10;i++){
           idSignal[i] = logs_id_list.at(i+logs_curret_page*10);
           dateSignal[i] = logs_date_list.at(i+logs_curret_page*10);
           eventSignal[i] = logs_event_list.at(i+logs_curret_page*10);
           amountSignal[i] = logs_amount_list.at(i+logs_curret_page*10);
        }
        emit logsSignal(idSignal, dateSignal, eventSignal, amountSignal);
    }else if(logs_curret_page == logs_total_pages){
        for(int i = 0; i<10;i++){
            idSignal[i] = "";
            dateSignal[i] = "";
            eventSignal[i] = "";
            amountSignal[i] = "";
        }
        for(int i = 0; i<logs_count-logs_total_pages*10;i++){
           idSignal[i] = logs_id_list.at(i+logs_curret_page*10);
           dateSignal[i] = logs_date_list.at(i+logs_curret_page*10);
           eventSignal[i] = logs_event_list.at(i+logs_curret_page*10);
           amountSignal[i] = logs_amount_list.at(i+logs_curret_page*10);
        }
        emit logsSignal(idSignal, dateSignal, eventSignal, amountSignal);
        qDebug()<<"printed the last logs";
    }
    else{
        qDebug()<<"reached end of list";
    }
    qDebug()<<logs_curret_page<<"logs current page "<<logs_total_pages<<"logs total pages";
    qDebug()<< "printing signal data"<<Qt::endl;
    for(int i = 0; i<10; i++){
        qDebug()<< idSignal[i];
        /*qDebug()<<dateSignal[i];
        qDebug()<<eventSignal[i];
        qDebug()<<amountSignal[i];*/
        idSignal[i] = "";
    }
}

void DLLRestAPIEngine::GetNextLogs()
{
    if(logs_curret_page < logs_total_pages && logs_curret_page > -1){
        for(int i = 0; i<10;i++){
           idSignal[i] = logs_id_list.at(i+logs_curret_page*10);
           dateSignal[i] = logs_date_list.at(i+logs_curret_page*10);
           eventSignal[i] = logs_event_list.at(i+logs_curret_page*10);
           amountSignal[i] = logs_amount_list.at(i+logs_curret_page*10);
        }
        emit logsSignal(idSignal, dateSignal, eventSignal, amountSignal);
    }else if(logs_curret_page == logs_total_pages){
        for(int i = 0; i<10;i++){
            idSignal[i] = "";
            dateSignal[i] = "";
            eventSignal[i] = "";
            amountSignal[i] = "";
        }
        for(int i = 0; i<logs_count-logs_total_pages*10;i++){
           idSignal[i] = logs_id_list.at(i+logs_curret_page*10);
           dateSignal[i] = logs_date_list.at(i+logs_curret_page*10);
           eventSignal[i] = logs_event_list.at(i+logs_curret_page*10);
           amountSignal[i] = logs_amount_list.at(i+logs_curret_page*10);
        }
        emit logsSignal(idSignal, dateSignal, eventSignal, amountSignal);
        qDebug()<<"printed the last logs";
    }
    else{
        qDebug()<<"reached end of list";
    }
    qDebug()<<logs_curret_page<<"logs current page "<<logs_total_pages<<"logs total pages";
    qDebug()<< "printing signal data"<<Qt::endl;
    for(int i = 0; i<10; i++){
        qDebug()<< idSignal[i];
        /*qDebug()<<dateSignal[i];
        qDebug()<<eventSignal[i];
        qDebug()<<amountSignal[i];*/
        idSignal[i] = "";
    }
}

void DLLRestAPIEngine::createLogSlot(QNetworkReply *reply)
{
    status = "";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    qDebug()<<json_doc;
    status = json_obj["status"].toString();
    if(status == "success"){
        qDebug()<<"log added success";
    }else{
        qDebug()<<"error adding log";
    }
    reply->deleteLater();
    manager->deleteLater();
}

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
    //todo login with cardnum and pin
    //use card number saved here for getting card info
    qDebug()<<"login kutsuttu";
    QJsonObject jsonObj;
    jsonObj.insert("email",email);
    jsonObj.insert("password",password);
    manager = new QNetworkAccessManager(this);
    QNetworkRequest request(base_url+"api/user/login");
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
        qDebug()<<"Wrong pin code";
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
    QString card_number = "956693190818";
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

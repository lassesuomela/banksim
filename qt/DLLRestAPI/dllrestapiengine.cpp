#include "dllrestapiengine.h"

DLLRestAPIEngine::DLLRestAPIEngine(QObject * parent) : QObject(parent)
{
    qDebug()<<"constructyor called";

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
    response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    status = json_obj["status"].toString();
    auth =json_obj["token"].toString();
    auth = "Bearer "+auth;
    authByteArr = auth.toUtf8();
    qDebug()<<status<<auth<<Qt::endl;
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
    response_data=reply->readAll();
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
    //todo set the number to a variable
    QString card_number = "956693190818";
    jsonObj.insert("card_number",card_number);
    QNetworkRequest request(base_url+"api/card/getByCardNumber/:card_number");
    manager = new QNetworkAccessManager(this);
    request.setRawHeader("Authorization", authByteArr);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getCardInfoSlot(QNetworkReply*)));

    //reply = manager->get(request, QJsonDocument(jsonObj).toJson());
}

void DLLRestAPIEngine::getCardInfoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    //QJsonObject json_obj = json_doc.object();

    qDebug()<<json_doc;


    reply->deleteLater();
    manager->deleteLater();
}

void DLLRestAPIEngine::GetAccountInfo()
{
    //todo get this id from the card info
    QString account_id = "2";
    QNetworkRequest request(base_url+"api/account/"+account_id);
    request.setRawHeader("Authorization", authByteArr);
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getAccountInfoSlot(QNetworkReply*)));

    reply = manager->get(request);
}

void DLLRestAPIEngine::getAccountInfoSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
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

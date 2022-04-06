#ifndef DLLRESTAPIENGINE_H
#define DLLRESTAPIENGINE_H
#include <QtNetwork>
#include <qnetwork.h>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonDocument>
#include <QDebug>
#include <QString>

class DLLRestAPIEngine : public QObject
{
    Q_OBJECT
public:
    DLLRestAPIEngine(QObject*parent = nullptr);
    ~DLLRestAPIEngine();
    void Login(QString, QString);
    void GetUserInfo();
    void GetCardInfo();
    void GetAccountInfo();

private:
    //network managament
    QJsonObject jsonObj;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString auth = "";
    QString base_url="http://localhost:3000/";
    QString status;
    QByteArray authByteArr;
    //user data
    QString fname;
    QString lname;
    QString address;
    QString email;
    QString phone;
    //card data

    //account data
    double account_balance;
    QString account_name;
    QString account_owner_id;

private slots:
    void loginSlot(QNetworkReply *reply);
    void getUserInfoSlot(QNetworkReply *reply);
    void getCardInfoSlot(QNetworkReply *reply);
    void getAccountInfoSlot(QNetworkReply *reply);
};

#endif // DLLRESTAPIENGINE_H

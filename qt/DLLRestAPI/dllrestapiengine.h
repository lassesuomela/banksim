#ifndef DLLRESTAPIENGINE_H
#define DLLRESTAPIENGINE_H
#include <QtNetwork>
#include <qnetwork.h>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonDocument>
#include <QDebug>
#include <QString>
#include <iostream>

using namespace std;
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
    void GetLogs();
    void CreateLog(int);

    int logs_curret_page = 4;
    int logs_total_pages;
    //logs for updating logs view
    QString idSignal[10];
    QString dateSignal[10];
    QString eventSignal[10];
    QString amountSignal[10];

private:
    //network managament
    QJsonObject jsonObj;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    //QByteArray response_data;
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
    int account_id_int;
    QString account_id;
    //account data
    double account_balance;
    QString account_name;
    //logs
    QList<QString> logs_id_list;
    QList<QString> logs_date_list;
    QList<QString> logs_event_list;
    QList<QString> logs_amount_list;
    int logs_count;
    QString card_number;




private slots:
    void loginSlot(QNetworkReply *reply);
    void getUserInfoSlot(QNetworkReply *reply);
    void getCardInfoSlot(QNetworkReply *reply);
    void getAccountInfoSlot(QNetworkReply *reply);
    void getLogsSlot(QNetworkReply *reply);
    void createLogSlot(QNetworkReply *reply);
};

#endif // DLLRESTAPIENGINE_H

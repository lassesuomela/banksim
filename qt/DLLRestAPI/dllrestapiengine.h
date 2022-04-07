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
    void GetLogs();
    void CreateLog(int);

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
    QList<int> logs_id_list;
    QList<QString> logs_date_list;
    QList<QString> logs_event_list;
    QList<int> logs_amount_list;

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

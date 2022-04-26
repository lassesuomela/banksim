#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <dllrestapi.h>
#include "customamountdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    DLLRestAPI *api;
    void startLogoutTimer();
private slots:

    void on_nosto_clicked();
    void on_takaisin_clicked();
    void on_talletus_clicked();
    void on_takaisin_talletus_clicked();
    void nostoValueUpdateSlot();
    void updateSaldoUI(double saldo);
    void on_clear_clicked();
    void talletusHandler();
    void on_saldo_nappi_clicked();
    void on_close_button_clicked();
    void clearErrorSlot();
    void on_close_clicked();

    void on_tilitapahtumat_clicked();

    void updateLogsView();

    void on_prev_10_clicked();

    void on_next_10_clicked();
    void updateUserInfo(double,QString,QString,QString,QString,QString,QByteArray);

    void on_kirjaudu_ulos_clicked();
    void on_clearTalletus_clicked();

    void on_talletaNappi_clicked();
    void timerSlot();
    void on_nostaNappi_clicked();
    void startTimer();
    void on_customAmount_clicked();
    void customAmountReceivedSlot(double);
    void balanceErrorReceivedSlot(QString);

    void on_credit_button_clicked();
    void on_debit_button_clicked();



signals:
    void logOutSignal();
private:
    QTimer *mainTimer;
    QTimer *logoutTimer;
    QTimer *errorTextTimer;
    Ui::MainWindow *ui;
    void setPicture(QString);
    double saldo;
    double nostoValue = 0.0;
    double talletusValue = 0.0;
    QString last5Transactions[5][3];
    CustomAmountDialog *amntDialog;
    void checkcardtype();
    int cardtype = 9;
};

#endif // MAINWINDOW_H

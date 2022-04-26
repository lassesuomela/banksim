#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(2);
    this->setFixedSize(800,600);
    api = new DLLRestAPI;
    amntDialog = new CustomAmountDialog;
    ui->nostoArvo->setText(QString::number(nostoValue) + "€");
    QPushButton *ottoButtons[6];
    for(int i = 0; i < 6; ++i){
        QString butName = "nosto" + QString::number(i);
        ottoButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(ottoButtons[i], SIGNAL(released()), this,
                SLOT(nostoValueUpdateSlot()));
    }

    ui->talletusArvo->setText(QString::number(nostoValue) + "€");
    QPushButton *talletusButtons[6];
    for(int i = 0; i < 6; ++i){
        QString butName = "talletus" + QString::number(i);
        talletusButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(talletusButtons[i], SIGNAL(released()), this,
                SLOT(talletusHandler()));
    }
    foreach(QPushButton *obj, this->findChildren<QPushButton *>())
            {
            connect(obj,SIGNAL(clicked()),this,SLOT(startTimer()));
        }
    foreach(QToolButton *obj, this->findChildren<QToolButton *>())
    {
        connect(obj,SIGNAL(clicked()),this,SLOT(startTimer()));
    }
    mainTimer = new QTimer(this);
    connect(mainTimer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    logoutTimer = new QTimer(this);
    connect(logoutTimer, SIGNAL(timeout()), this, SLOT(on_kirjaudu_ulos_clicked()));
    errorTextTimer = new QTimer(this);
    connect(errorTextTimer, SIGNAL(timeout()), this, SLOT(clearErrorSlot()));

    connect(api, SIGNAL(saldoUpdated(double)), this, SLOT(updateSaldoUI(double)));
    connect(api, SIGNAL(logsUpdatedSignal()), this, SLOT(updateLogsView()));
    connect(api, SIGNAL(InfoSignal(double,QString,QString,QString,QString,QString,QByteArray)), this, SLOT(updateUserInfo(double,QString,QString,QString,QString,QString,QByteArray)));
    connect(api, SIGNAL(balanceErrorToExe(QString)), this, SLOT(balanceErrorReceivedSlot(QString)));
    connect(amntDialog, SIGNAL(amountToExe(double)), this, SLOT(customAmountReceivedSlot(double)));
}

MainWindow::~MainWindow()
{
    qDebug()<<"main window dest";
    disconnect(api, SIGNAL(saldoUpdated(double)), this, SLOT(updateSaldoUI(double)));
    disconnect(api, SIGNAL(logsUpdatedSignal()), this, SLOT(updateLogsView()));
    disconnect(api, SIGNAL(InfoSignal(double,QString,QString,QString,QString,QString,QByteArray)), this, SLOT(updateUserInfo(double,QString,QString,QString,QString,QString,QByteArray)));
    disconnect(api, SIGNAL(balanceErrorToExe(QString)), this, SLOT(balanceErrorReceivedSlot(QString)));

    delete ui;
    if(api != nullptr){
        qDebug()<<"deleting api";
        delete api;
        api = nullptr;
    }
    if(amntDialog != nullptr){
        delete amntDialog;
        amntDialog = nullptr;
    }

}

void MainWindow::startLogoutTimer()
{
    logoutTimer->start(30000);
}

void MainWindow::updateUserInfo(double balance,QString acc_name,QString fname,QString lname,QString cardNum,QString cardType, QByteArray pictureData)
{
    this->startLogoutTimer();

    QString tempname = lname + " " + fname;
    saldo = balance;
    ui->nameLabel->setText(tempname);
    ui->accountNameLabel->setText(acc_name);
    ui->cardNumberLabel->setText(cardNum);
    ui->cardTypeLabel->setText(cardType);
    ui->account_name->setText(tempname);
    ui->account_name1->setText(tempname);
    ui->nostoArvo->setText(QString::number(nostoValue) + "€");
    updateSaldoUI(saldo);
    ui->talletusArvo->setText(QString::number(talletusValue) + "€");
    QPixmap pixmap;
    pixmap.loadFromData(pictureData);

    int h = ui->pictureLabel->height();
    int w = ui->pictureLabel->width();

    ui->pictureLabel->setPixmap(pixmap.scaled(h, w, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

    QRegion * region = new QRegion(0, 0, h, w, QRegion::Ellipse);

    ui->pictureLabel->setMask(*region);
    if(cardType=="Debit")
        this->cardtype=0;
    if(cardType=="Credit")
        this->cardtype=1;
    checkcardtype();

}

void MainWindow::nostoValueUpdateSlot(){
    QPushButton *button = (QPushButton *)sender();
    nostoValue=button->text().toDouble();
    ui->nostoArvo->setText(QString::number(nostoValue) + "€");
    ui->nostaNappi->setEnabled(true);
}

void MainWindow::updateSaldoUI(double saldo)
{
    QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
    QLocale locale;
    QString word = locale.toString(saldo,'f',2);


    ui->saldoArvo->setText(word+"€");
    ui->saldoArvo_2->setText(word+"€");
    ui->saldoArvo_3->setText(word+"€");
    ui->saldoArvo_4->setText(word+"€");
}

void MainWindow::on_nosto_clicked(){


    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_takaisin_clicked(){
    on_clear_clicked();
    ui->balanceErrorText->setText("");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_talletus_clicked(){
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_takaisin_talletus_clicked(){
    on_clearTalletus_clicked();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_clear_clicked()
{
    nostoValue = 0.0;
    ui->nostoArvo->setText(QString::number(nostoValue) + "€");
    ui->nostaNappi->setEnabled(false);
    ui->balanceErrorText->setText("");
}

void MainWindow::talletusHandler()
{
    QPushButton *button = (QPushButton *)sender();
    talletusValue=button->text().toDouble();
    ui->talletusArvo->setText(QString::number(talletusValue) + "€");
    ui->talletaNappi->setEnabled(true);
}

void MainWindow::on_saldo_nappi_clicked()
{
    api->getLogsByPage(1);
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_close_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    api->getLogsByPage(1);
}

void MainWindow::clearErrorSlot()
{
    ui->balanceErrorText->setText("");
    errorTextTimer->stop();
}

void MainWindow::on_close_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_tilitapahtumat_clicked()
{
    api->getLogsByPage(1);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::updateLogsView()
{
    ui->listWidget->clear();
    ui->transaction->clear();
    QString dataRow = "";
    for(int i = 0; i<10;++i){
        for(int j = 0; j < 3; ++j){
            dataRow.append(api->logData[i][j]);
            if(j == 2 && api->logData[i][j] != "")
                dataRow.append("€");
            dataRow.append(" ");
        }
        if(dataRow != " €")
            ui->listWidget->addItem(dataRow);
        if(i<5){
            ui->transaction->addItem(dataRow);
        }
        dataRow = "";
    }

}

void MainWindow::on_prev_10_clicked()
{
    api->getLogsByPage(0);
}

void MainWindow::on_next_10_clicked()
{
    api->getLogsByPage(-1);
}

void MainWindow::on_kirjaudu_ulos_clicked()
{
    this->hide();
    logoutTimer->stop();
    mainTimer->stop();
    api = new DLLRestAPI;
    saldo = 0;
    nostoValue = 0;
    talletusValue = 0;
    for(int i = 0; i <5; i++){
        for(int j = 0; i<3; i++){
            last5Transactions[i][j] = "";
        }
    }
    cardtype = 9;
    connect(api, SIGNAL(saldoUpdated(double)), this, SLOT(updateSaldoUI(double)));
    connect(api, SIGNAL(logsUpdatedSignal()), this, SLOT(updateLogsView()));
    connect(api, SIGNAL(InfoSignal(double,QString,QString,QString,QString,QString,QByteArray)), this, SLOT(updateUserInfo(double,QString,QString,QString,QString,QString,QByteArray)));
    connect(api, SIGNAL(balanceErrorToExe(QString)), this, SLOT(balanceErrorReceivedSlot(QString)));
    emit logOutSignal();
}

void MainWindow::on_clearTalletus_clicked()
{
    talletusValue = 0.0;
    ui->talletusArvo->setText(QString::number(talletusValue) + "€");
    ui->talletaNappi->setEnabled(false);
}

void MainWindow::on_talletaNappi_clicked()
{
    double amnt = ui->talletusArvo->text().remove("€").toDouble();
    if(amnt != 0.0)
        api->updateBalance(1, amnt, this->cardtype);
    talletusValue = 0.0;
    ui->talletusArvo->setText(QString::number(talletusValue) + "€");
    ui->talletaNappi->setEnabled(false);
}

void MainWindow::timerSlot()
{
    if(ui->stackedWidget->currentIndex() == 0){
        mainTimer->stop();
        logoutTimer->start(20000);
    }else{
        ui->stackedWidget->setCurrentIndex(0);
        mainTimer->stop();
        logoutTimer->start(30000);
    }
}

void MainWindow::on_nostaNappi_clicked()
{
    double amnt = ui->nostoArvo->text().remove("€").toDouble();
    if(amnt != 0.0)
        api->updateBalance(0, amnt, this->cardtype);
    nostoValue = 0.0;
    ui->nostoArvo->setText(QString::number(nostoValue) + "€");
    ui->nostaNappi->setEnabled(false);
}

void MainWindow::startTimer()
{
    if(this->isVisible()){
        qDebug()<<"started main timer and stopped logout";
        mainTimer->start(10000);
        logoutTimer->stop();
    }

}


void MainWindow::on_customAmount_clicked()
{
    amntDialog->show();
}

void MainWindow::customAmountReceivedSlot(double amount)
{
    nostoValue = amount;
    ui->nostoArvo->setText(QString::number(nostoValue) + "€");
    if(amount > 0.0)
        ui->nostaNappi->setEnabled(true);
}

void MainWindow::balanceErrorReceivedSlot(QString err)
{
    ui->balanceErrorText->setText(err);
    errorTextTimer->start(10000);

}



void MainWindow::on_credit_button_clicked()
{
    this->cardtype=1;
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_debit_button_clicked()
{
    this->cardtype=0;
    ui->stackedWidget->setCurrentIndex(0);
    ui->cardTypeLabel->setText("Credit (Debit)");
}

void MainWindow::checkcardtype()
{
    if(this->cardtype==0){
        ui->stackedWidget->setCurrentIndex(0);
    }else if(this->cardtype==1){
        ui->stackedWidget->setCurrentIndex(2);
    }else{
        ui->stackedWidget->setCurrentIndex(0);
    }
}

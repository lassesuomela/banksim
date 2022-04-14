#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    this->setFixedSize(800,600);
    api = new DLLRestAPI;

    ui->nostoArvo->setText(QString::number(nostoValue));
    QPushButton *ottoButtons[6];
    for(int i = 0; i < 6; ++i){
        QString butName = "nosto" + QString::number(i);
        ottoButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(ottoButtons[i], SIGNAL(released()), this,
                SLOT(on_amount_clicked()));
    }

    ui->talletusArvo->setText(QString::number(nostoValue));
    QPushButton *talletusButtons[6];
    for(int i = 0; i < 6; ++i){
        QString butName = "talletus" + QString::number(i);
        talletusButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(talletusButtons[i], SIGNAL(released()), this,
                SLOT(talletusHandler()));
    }

    connect(api, SIGNAL(logsUpdatedSignal()), this, SLOT(updateLogsView()));
    connect(api, SIGNAL(InfoSignal(double,QString,QString,QString,QString,QString,QByteArray)), this, SLOT(updateUserInfo(double,QString,QString,QString,QString,QString,QByteArray)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete api;
    api = nullptr;
}

void MainWindow::updateUserInfo(double balance,QString acc_name,QString fname,QString lname,QString cardNum,QString cardType, QByteArray pictureData)
{
    QString tempname = lname + " " + fname;
    saldo = balance;
    ui->nameLabel->setText(tempname);
    ui->accountNameLabel->setText(acc_name);
    ui->cardNumberLabel->setText(cardNum);
    ui->cardTypeLabel->setText(cardType);
    ui->account_name->setText(tempname);
    ui->account_name1->setText(tempname);
    updateSaldoUI();
    QPixmap pixmap;
    pixmap.loadFromData(pictureData);

    int h = ui->pictureLabel->height();
    int w = ui->pictureLabel->width();

    ui->pictureLabel->setPixmap(pixmap.scaled(h, w, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

    QRegion * region = new QRegion(0, 0, h, w, QRegion::Ellipse);

    ui->pictureLabel->setMask(*region);
    qDebug() << "Picture changed";
}

void MainWindow::on_amount_clicked(){
    QPushButton *button = (QPushButton *)sender();
    nostoValue=button->text().toDouble();
    ui->nostoArvo->setText(QString::number(nostoValue));
}

void MainWindow::updateSaldoUI()
{
    ui->saldoArvo->setText(QString::number(saldo)+"€");
    ui->saldoArvo_2->setText(QString::number(saldo)+"€");
    ui->saldoArvo_3->setText(QString::number(saldo)+"€");
    ui->saldoArvo_4->setText(QString::number(saldo)+"€");
}

void MainWindow::on_nosto_clicked(){
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_takaisin_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_talletus_clicked(){
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_takaisin_talletus_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_clear_clicked()
{
    nostoValue = 0.0;
    ui->nostoArvo->setText(QString::number(nostoValue));
}

void MainWindow::talletusHandler()
{
    QPushButton *button = (QPushButton *)sender();
    talletusValue=button->text().toDouble();
    ui->talletusArvo->setText(QString::number(talletusValue));
}

void MainWindow::on_saldo_nappi_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_close_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
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

//---------------------TILITAPAHTUMAT PAGE-----------------------
void MainWindow::updateLogsView()
{
    ui->listWidget->clear();
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

    emit logOutSignal();

}


void MainWindow::on_clearTalletus_clicked()
{
    talletusValue = 0.0;
    ui->talletusArvo->setText(QString::number(talletusValue));
}


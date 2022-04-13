#include "mainwindow.h"
#include "ui_mainwindow.h"

double nostoValue = 0.0;

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    this->setFixedSize(800,600);
    api = new DLLRestAPI;

    ui->nostoArvo->setText(QString::number(nostoValue));
    QPushButton *numButtons[6];
    for(int i = 0; i < 6; ++i){
        QString butName = "nosto" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(on_amount_clicked()));
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

void MainWindow::updateUserInfo(double,QString acc_name,QString fname,QString lname,QString cardNum,QString cardType, QByteArray pictureData)
{
    QString tempname = lname + " " + fname;

    ui->nameLabel->setText(tempname);
    ui->accountNameLabel->setText(acc_name);
    ui->cardNumberLabel->setText(cardNum);
    ui->cardTypeLabel->setText(cardType);

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
            dataRow.append(" ");
        }
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


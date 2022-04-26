#include "idlewindow.h"
#include "ui_idlewindow.h"

IdleWindow::IdleWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IdleWindow){
    ui->setupUi(this);
    this->setFixedSize(800,600);
    rfid = "";
    tries = 3;
    this->show();
    mainWindow = new MainWindow();
    mainWindow->hide();
    pinCodeDLL = new PinCodeDLL();
    dllRestApi = mainWindow->api;
    mainWindow->move(this->pos());
    connect(pinCodeDLL, SIGNAL(triesToDLL(int)), this, SLOT(Tries(int)));
    connect(pinCodeDLL, SIGNAL(pinToExe(QString)), this, SLOT(PinSlot(QString)));
    connect(dllRestApi, SIGNAL(SendTriesToExe(int)), this, SLOT(GetTries(int)));
    connect(this, SIGNAL(SendTries(int)), pinCodeDLL, SLOT(getTriesFromEXE(int)));
    connect(this, SIGNAL(sendCloseSignal()), pinCodeDLL, SLOT(closeSignalSlot()));
    connect(dllRestApi, SIGNAL(StatusToExe(QString)), this, SLOT(GetLoginStatus(QString)));
    connect(mainWindow, SIGNAL(logOutSignal()), this, SLOT(LogOutSlot()));
    connect(this, SIGNAL(sendAuthInfo(QString,QString)), dllRestApi, SLOT(LoginSlot(QString,QString)));
    connect(pinCodeDLL, SIGNAL(autoTimeOutToExe()), this, SLOT(TimeOutSlot()));
    HandleCard();
}
IdleWindow::~IdleWindow(){
    disconnect(pinCodeDLL, SIGNAL(triesToDLL(int)), this, SLOT(Tries(int)));
    disconnect(pinCodeDLL, SIGNAL(pinToExe(QString)), this, SLOT(PinSlot(QString)));
    disconnect(this, SIGNAL(SendTries(int)), pinCodeDLL, SLOT(getTriesFromEXE(int)));
    disconnect(this, SIGNAL(sendCloseSignal()), pinCodeDLL, SLOT(closeSignalSlot()));
    disconnect(pinCodeDLL, SIGNAL(autoTimeOutToExe()), this, SLOT(TimeOutSlot()));
    disconnect(this, SIGNAL(sendAuthInfo(QString,QString)), dllRestApi, SLOT(LoginSlot(QString,QString)));

    delete ui;
    delete pinCodeDLL;
    pinCodeDLL = nullptr;
    if(serialPort != nullptr){
        qDebug()<<"serial port desto";
        delete serialPort;
        serialPort = nullptr;
    }
    if(mainWindow != nullptr){
        delete mainWindow;
        mainWindow = nullptr;
    }
}

void IdleWindow::PinSlot(QString pin){
    pinCode = pin;
    qDebug() << "pinReceived from pincodedll" << pin;

    emit sendAuthInfo(QString(rfid),pin);
}

void IdleWindow::Tries(int triesAmount){
    tries = triesAmount;
}

void IdleWindow::GetLoginStatus(QString status)
{
    if(status == "success"){
        qDebug() << "Login successful";

        emit sendCloseSignal();
        this->hide();
        rfid = "";
        mainWindow->show();

    }
    else{
        qDebug() << "Login not successful";
    }
}

void IdleWindow::HandleCard(){
      serialPort = new DLLSerialPort(4);


      rfid = serialPort->GetRFID(); //insert real card here
      qDebug()<<rfid<<" debuggg";

//    rfid = "00006000626BD000";
  
    if( rfid != ""){
        delete serialPort;
        serialPort = nullptr;
        qDebug()<<"rfid was not null";
        dllRestApi->GetTriesFromApi(rfid);
    }
}

void IdleWindow::on_nappi_clicked()
{
    HandleCard();
}

void IdleWindow::GetTries(int x)
{
    emit SendTries(x);
    qDebug() << "Sent tries to pincodeui";
    if(!pinCodeDLL->isVisible()){
        pinCodeDLL->ShowWindow();
    }
}

void IdleWindow::LogOutSlot()
{
    this->show();
    dllRestApi = mainWindow->api;
    connect(dllRestApi, SIGNAL(SendTriesToExe(int)), this, SLOT(GetTries(int)));
    connect(dllRestApi, SIGNAL(StatusToExe(QString)), this, SLOT(GetLoginStatus(QString)));
    connect(this, SIGNAL(sendAuthInfo(QString,QString)), dllRestApi, SLOT(LoginSlot(QString,QString)));
    HandleCard();
}

void IdleWindow::TimeOutSlot()
{
    HandleCard();
}

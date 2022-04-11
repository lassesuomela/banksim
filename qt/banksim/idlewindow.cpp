#include "idlewindow.h"
#include "ui_idlewindow.h"

IdleWindow::IdleWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IdleWindow){
    ui->setupUi(this);
    this->setFixedSize(800,600);
    rfid = NULL;
    tries = 3;
    serialPort = new DLLSerialPort(1);
    pinCodeDLL = new PinCodeDLL();
    dllRestApi = new DLLRestAPI();
    connect(pinCodeDLL, SIGNAL(triesToDLL(int)), this, SLOT(Tries(int)));
    connect(pinCodeDLL, SIGNAL(pinToExe(QString)), this, SLOT(PinSlot(QString)));
    connect(dllRestApi, SIGNAL(SendTriesToExe(int)), this, SLOT(GetTries(int)));
    connect(this, SIGNAL(SendTries(int)), pinCodeDLL, SLOT(getTriesFromEXE(int)));
    connect(this, SIGNAL(sendCloseSignal()), pinCodeDLL, SLOT(closeSignalSlot()));

    HandleCard();
}
IdleWindow::~IdleWindow(){
    disconnect(pinCodeDLL, SIGNAL(triesToDLL(int)), this, SLOT(Tries(int)));
    disconnect(pinCodeDLL, SIGNAL(pinToExe(QString)), this, SLOT(PinSlot(QString)));
    disconnect(this, SIGNAL(SendTries(int)), pinCodeDLL, SLOT(getTriesFromEXE(int)));
    disconnect(this, SIGNAL(sendCloseSignal()), pinCodeDLL, SLOT(closeSignalSlot()));

    delete ui;
    delete pinCodeDLL;
    delete mainWindow;
    pinCodeDLL = nullptr;
}

void IdleWindow::PinSlot(QString pin){
    pinCode = pin;
    qDebug() << "pinReceived" << pin;
    if(dllRestApi->Login(rfid,pin) == "success"){
       qDebug() << "BEFORE NEW MAINWINDOW";
       mainWindow = new MainWindow();
       qDebug() << "BEFORE HIDE";
       this->hide();
       qDebug() << "AFTER HIDE";
       emit sendCloseSignal();
       qDebug() << "AFTER SIGNAL";
       mainWindow->show();
       qDebug() << "AFTER SHOW";

    }
    else{
        qDebug() << "ELSE XD" << Qt::endl;
        dllRestApi->GetTries(rfid);
        //emit SendTries(tries);
    }
}

void IdleWindow::Tries(int triesAmount){
    tries = triesAmount;
    qDebug() << "triesamount" << tries;
}

void IdleWindow::HandleCard(){
    //rfid = serialPort->GetRFID(); insert real card here
    rfid = (char*) "107807862962";
    if( rfid != NULL){
        delete serialPort;
        serialPort = nullptr;
        dllRestApi->GetTries(rfid);
        // getTries from db here
        qDebug() << "VITTU TRIES" << tries << Qt::endl;
    }
}

void IdleWindow::on_nappi_clicked()
{
    pinCodeDLL->ShowWindow();
}

void IdleWindow::GetTries(int x)
{
    emit SendTries(x);
    qDebug() << "IDLEWINDOW SLOT";
}

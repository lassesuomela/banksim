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
    connect(pinCodeDLL, SIGNAL(triesToDLL(int)), this, SLOT(Tries(int)));
    connect(pinCodeDLL, SIGNAL(pinToExe(QString)), this, SLOT(PinSlot(QString)));
    connect(this, SIGNAL(SendTries(int)), pinCodeDLL, SLOT(getTriesFromEXE(int)));
    HandleCard();
}
IdleWindow::~IdleWindow(){
    disconnect(pinCodeDLL, SIGNAL(triesToDLL(int)), this, SLOT(Tries(int)));
    disconnect(pinCodeDLL, SIGNAL(pinToExe(QString)), this, SLOT(PinSlot(QString)));
    disconnect(this, SIGNAL(SendTries(int)), pinCodeDLL, SLOT(getTriesFromEXE(int)));
    delete ui;
    delete pinCodeDLL;
    delete mainWindow;
    pinCodeDLL = nullptr;
}

void IdleWindow::PinSlot(QString pin){
    pinCode = pin;
    qDebug() << "pinReceived" << pin;
    if(CheckInfo(tries, rfid, pinCode)){
       mainWindow = new MainWindow();
       this->close();
       mainWindow->show();

    }
    else{
        tries--;
        emit SendTries(tries);
        pinCodeDLL->ShowWindow();
    }
}

void IdleWindow::Tries(int triesAmount){
    tries = triesAmount;
    qDebug() << "triesamount" << tries;
}

void IdleWindow::HandleCard(){
    //rfid = serialPort->GetRFID(); insert real card here
    rfid = (char*) "2";
    if( rfid != NULL){
    delete serialPort;
    serialPort = nullptr;
    emit SendTries(tries);
    pinCodeDLL->ShowWindow();
    }
}

bool IdleWindow::CheckInfo(int tries, char * rfid, QString pinCode){
    if(pinCode != "1234"){
        return false;
    }
    //to-do checkinfo
    qDebug() << tries << rfid << pinCode;
    return true;
}

void IdleWindow::on_nappi_clicked()
{
    pinCodeDLL->ShowWindow();
}

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
    HandleCard();
}
IdleWindow::~IdleWindow(){
    delete ui;
    delete pinCodeDLL;
    pinCodeDLL = nullptr;

}

void IdleWindow::PinSlot(QString pin){
    pinCode = pin;
    qDebug() << "pinReceived" << pin;
    if(CheckInfo(tries, rfid, pinCode)){
        mainWindow = new MainWindow();
        mainWindow->show();

    }
    else{
        tries--;
        emit SendTries(tries);
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
    pinCodeDLL = new PinCodeDLL();
    connect(pinCodeDLL, SIGNAL(triesToDLL(int)), this, SLOT(Tries(int)));
    connect(pinCodeDLL, SIGNAL(pinToExe(QString)), this, SLOT(PinSlot(QString)));
    connect(this, SIGNAL(SendTries(int)), pinCodeDLL, SLOT(getTriesFromEXE(int)));
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

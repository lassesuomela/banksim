#include "pincodeui.h"
#include "ui_pincodeui.h"

PinCodeUI::PinCodeUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PinCodeUI)
{
    ui->setupUi(this);

    // append all buttons 0-9 to button vector
    buttons.append(ui->btn_1);
    buttons.append(ui->btn_2);
    buttons.append(ui->btn_3);
    buttons.append(ui->btn_4);
    buttons.append(ui->btn_5);
    buttons.append(ui->btn_6);
    buttons.append(ui->btn_7);
    buttons.append(ui->btn_8);
    buttons.append(ui->btn_9);
    buttons.append(ui->btn_0);

    // connect all buttons on the vector to handleClick slot
    foreach(QPushButton *btn, buttons){
        connect(btn, SIGNAL(clicked()), this, SLOT(handleClick()));
    }
}

PinCodeUI::~PinCodeUI()
{
    delete ui;
}

QString PinCodeUI::getPinCode()
{
    return pinCode;
}

void PinCodeUI::setPinCodeText(QString text)
{
    // set pinCodeTextBox text to QString
    ui->pinCodeTextBox->setText(text);
}

void PinCodeUI::clearPin()
{
    // clear pinCode and clear pinCodeTextBox
    pinCode = QString("");
    censoredPinCode = "";
    setPinCodeText(censoredPinCode);
}

void PinCodeUI::handleClick()
{

    QObject * sender = QObject::sender();

    QString btnName = sender->objectName();

    // check if pinCode length is 4 or more then return out
    if (pinCode.length() >= 4){
        return;
    }

    // loop through all the buttons in buttons vector assigned in constructor
    // check if current button's name matches the one in the vector
    // assign pushed buttons value to the pin code
    foreach (QPushButton *btn, buttons){
        if(btn->objectName() == btnName){
            qDebug() << "Pushed" << btn->text() << "button";
            pinCode += btn->text();

            // clear censored pincode
            censoredPinCode = "";

            // append '*' to censored pincode based on pinCodes length
            for (int i = 0; i < pinCode.length(); i++){
                censoredPinCode += "*";
            }

            // update text box
            setPinCodeText(censoredPinCode);
        }
    }
}

void PinCodeUI::on_btn_clear_clicked()
{
    clearPin();
    qDebug() << "Pin code cleared";
}


void PinCodeUI::on_btn_ok_clicked()
{
    // check if pinCode length is less than 4 then return out
    if (pinCode.length() < 4){
        return;
    }

    qDebug() << "Pin code:" << pinCode;

    qDebug() << "Emitting signal to Pin code DLL";
    emit sendPinCode(pinCode);
}


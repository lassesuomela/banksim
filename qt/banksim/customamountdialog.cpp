#include "customamountdialog.h"
#include "ui_customamountdialog.h"

CustomAmountDialog::CustomAmountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomAmountDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::MSWindowsFixedSizeDialogHint);
    this->setModal(true);
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
    foreach(QPushButton *btn, buttons){
        connect(btn, SIGNAL(clicked()), this, SLOT(handleClick()));
    }
}

CustomAmountDialog::~CustomAmountDialog()
{
    delete ui;
}

void CustomAmountDialog::setText(QString amnt)
{
    ui->textBox->setText(amnt);
    withdrawAmount = amnt.toDouble();
}

void CustomAmountDialog::handleClick()
{
    QObject * sender = QObject::sender();
    QString btnName = sender->objectName();
    foreach (QPushButton *btn, buttons){
        if(btn->objectName() == btnName){
            text += btn->text();

            setText(text);
        }
    }
}

void CustomAmountDialog::on_btn_clear_clicked()
{
    withdrawAmount = 0.0;
    ui->textBox->setText("");
    text = "";
    ui->infoTextBox->setText("");
}


void CustomAmountDialog::on_btn_cancel_clicked()
{
    withdrawAmount = 0.0;
    ui->textBox->setText("");
    text = "";
    ui->infoTextBox->setText("");
    this->close();
}


void CustomAmountDialog::on_btn_ok_clicked()
{
    if(fmod(withdrawAmount,10) == 0){
        emit amountToExe(withdrawAmount);
        withdrawAmount = 0.0;
        text = "";
        ui->textBox->setText("");
        ui->infoTextBox->setText("");
        this->close();
    }else{
        ui->infoTextBox->setText("Please enter a value divisible by ten");
    }
}


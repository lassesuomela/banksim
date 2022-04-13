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

    ui->nostoArvo->setText(QString::number(nostoValue));
    QPushButton *numButtons[6];
    for(int i = 0; i < 6; ++i){
        QString butName = "nosto" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(on_amount_clicked()));
    }
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_amount_clicked(){
    QPushButton *button = (QPushButton *)sender();
    nostoValue=button->text().toDouble();
    ui->nostoArvo->setText(QString::number(nostoValue));
}

void MainWindow::on_nosto_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_takaisin_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_talletus_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_takaisin_talletus_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_clear_clicked()
{
    nostoValue = 0.0;
    ui->nostoArvo->setText(QString::number(nostoValue));
}

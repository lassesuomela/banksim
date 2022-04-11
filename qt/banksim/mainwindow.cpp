#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    this->setFixedSize(800,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nosto_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_takaisin_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

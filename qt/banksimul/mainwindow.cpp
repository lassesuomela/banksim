#include "mainwindow.h"
#include "mainmenu.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){

    ui->setupUi(this);
    this->setFixedSize(800,600);
}

MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::on_pushButton_clicked(){
    //MainMenu mainMenu;
    //mainMenu.setModal(true);
    //mainMenu.exec();
    hide();
    mainMenu = new MainMenu(this);
    mainMenu->show();
}

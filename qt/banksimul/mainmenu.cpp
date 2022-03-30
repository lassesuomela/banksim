#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_toolButton_4_clicked()
{
 this->close();
}


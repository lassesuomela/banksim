#include "idlewindow.h"
#include "ui_idlewindow.h"

IdleWindow::IdleWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IdleWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
}

IdleWindow::~IdleWindow()
{
    delete ui;
}

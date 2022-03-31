#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "idlewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    IdleWindow *idleWindow;
};

#endif // MAINWINDOW_H

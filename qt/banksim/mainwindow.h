#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

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

    void on_nosto_clicked();

    void on_takaisin_clicked();

    void on_talletus_clicked();

    void on_takaisin_talletus_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

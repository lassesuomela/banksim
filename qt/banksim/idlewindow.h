#ifndef IDLEWINDOW_H
#define IDLEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class IdleWindow; }
QT_END_NAMESPACE

class IdleWindow : public QMainWindow
{
    Q_OBJECT

public:
    IdleWindow(QWidget *parent = nullptr);
    ~IdleWindow();

private slots:
    void on_nappi_clicked();

private:
    Ui::IdleWindow *ui;
};
#endif // IDLEWINDOW_H

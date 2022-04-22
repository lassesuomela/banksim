#ifndef CUSTOMAMOUNTDIALOG_H
#define CUSTOMAMOUNTDIALOG_H
#include <QtWidgets/QDialog>
#include <QDialog>
#include <QDebug>
#include <cmath>
namespace Ui {
class CustomAmountDialog;
}

class CustomAmountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomAmountDialog(QWidget *parent = nullptr);
    ~CustomAmountDialog();

private:
    Ui::CustomAmountDialog *ui;
    QVector <QPushButton *> buttons;
    double withdrawAmount = 0;
    QString text = "";
    void setText(QString);

private slots:
    void handleClick();
    void on_btn_clear_clicked();
    void on_btn_cancel_clicked();
    void on_btn_ok_clicked();

signals:
    void amountToExe(double);
};

#endif // CUSTOMAMOUNTDIALOG_H

#ifndef PINCODEUI_H
#define PINCODEUI_H

#include <QtWidgets/QDialog>
#include <QDebug>

namespace Ui {
class PinCodeUI;
}

class PinCodeUI : public QDialog
{
    Q_OBJECT

public:
    explicit PinCodeUI(QWidget *parent = nullptr);
    ~PinCodeUI();
    QString getPinCode();

private:
    Ui::PinCodeUI *ui;
    QString pinCode;
    QVector <QPushButton *> buttons;
    QString censoredPinCode;

    void setPinCodeText(QString);

private slots:
    void clearPin();
    void handleClick();
    void on_btn_clear_clicked();
    void on_btn_ok_clicked();
signals:
    void sendPinCode(QString);
};

#endif // PINCODEUI_H

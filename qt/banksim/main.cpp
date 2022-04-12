#include "idlewindow.h"
#include "dllserialport.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IdleWindow w;
    w.show();
    return a.exec();
}

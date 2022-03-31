QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    idlewindow.cpp \
    mainwindow.cpp

HEADERS += \
    idlewindow.h \
    mainwindow.h

FORMS += \
    idlewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -LF:/Koulu/olio-ohjelmointi/release/ -lDLLSerialPort
else:win32:CONFIG(debug, debug|release): LIBS += -LF:/Koulu/olio-ohjelmointi/debug/ -lDLLSerialPort

INCLUDEPATH += $$PWD/../DLLSerialPort
DEPENDPATH += $$PWD/../DLLSerialPort

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../pinCodeDLL/build/release/ -lpinCodeDLL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../pinCodeDLL/build/debug/ -lpinCodeDLL

INCLUDEPATH += $$PWD/../pinCodeDLL
DEPENDPATH += $$PWD/../pinCodeDLL

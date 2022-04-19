QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customamountdialog.cpp \
    main.cpp \
    idlewindow.cpp \
    mainwindow.cpp

HEADERS += \
    customamountdialog.h \
    idlewindow.h \
    mainwindow.h

FORMS += \
    customamountdialog.ui \
    idlewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../pinCodeDLL/build/release/ -lpinCodeDLL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../pinCodeDLL/build/debug/ -lpinCodeDLL

INCLUDEPATH += $$PWD/../pinCodeDLL/
DEPENDPATH += $$PWD/../pinCodeDLL/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../DLLSerialPort/build/release/ -lDLLSerialPort
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../DLLSerialPort/build/debug/ -lDLLSerialPort

INCLUDEPATH += $$PWD/../DLLSerialPort/
DEPENDPATH += $$PWD/../DLLSerialPort/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../DLLRestAPI/build/release/ -lDLLRestAPI
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../DLLRestAPI/build/debug/ -lDLLRestAPI

INCLUDEPATH += $$PWD/../DLLRestAPI/
DEPENDPATH += $$PWD/../DLLRestAPI/

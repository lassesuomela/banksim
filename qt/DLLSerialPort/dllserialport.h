#ifndef DLLSERIALPORT_H
#define DLLSERIALPORT_H
#include "dllserialportengine.h"
#include "DLLSerialPort_global.h"

class DLLSERIALPORT_EXPORT DLLSerialPort
{
public:
    DLLSerialPort(int comPort);
    ~DLLSerialPort();
    char* GetRFID();

private:
     DLLSerialPortEngine* engineClass;
};

#endif // DLLSERIALPORT_H

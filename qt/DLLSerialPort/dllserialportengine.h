#ifndef DLLSERIALPORTENGINE_H
#define DLLSERIALPORTENGINE_H
#include <windows.h>
#include <iostream>
#include <cstdio>

const int SERIAL_READ_INTERVAL_TIMEOUT = 50;
const int SERIAL_READ_TOTAL_TIMEOUT_CONSTANT = 50;
const int SERIAL_READ_TOTAL_TIMEOUT_MULTIPLIER = 10;

using namespace std;

class DLLSerialPortEngine
{
public:
    DLLSerialPortEngine(int comPortA);
    bool OpenPort(int baud, int parity, int dataBits, int stopBits);
    void ClosePort();
    void ReadCard(size_t bufferSize, void(*OnRead)(char*));

private:
    HANDLE hSerial;
    bool reading;
    int comPort;
    static HANDLE GetSerialPortHandle(int comPort);
};

#endif // DLLSERIALPORTENGINE_H

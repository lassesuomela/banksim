#include "dllserialport.h"

void ReadCard(char* data);
char* rfid;

DLLSerialPort::DLLSerialPort(int comPort)
{
    engineClass = new DLLSerialPortEngine(comPort);
    engineClass->OpenPort(9600, NOPARITY, 8, ONESTOPBIT);
}

DLLSerialPort::~DLLSerialPort()
{
    engineClass->ClosePort();
    delete engineClass;
    engineClass = nullptr;
}

char* DLLSerialPort::GetRFID()
{
    engineClass->ReadCard(18, ReadCard);
    return rfid;
}

void ReadCard(char* data)
{
    cout << "rfid: " << data << endl;
    rfid = data;

}

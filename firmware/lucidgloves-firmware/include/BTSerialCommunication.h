#pragma once

#include "Arduino.h"
#include "BluetoothSerial.h"
#include "ICommunication.h"

class BTSerialCommunication : public ICommunication {
public:
    BTSerialCommunication();
    bool isOpen();
    void start();
    bool readData(char *input);
    void output(char *data);
private:
    bool m_isOpen;
    BluetoothSerial m_SerialBT;
};
#pragma once

#include "ArduinoBLE.h"
#include "ICommunication.h"

class BLECommunication : public ICommunication {
    public:
        BLECommunication();
        bool isOpen();
        void start();
        void output(char* data);
        bool readData(char* input);
    private:
        bool m_isOpen;
        BLECharacteristic m_tx;
        BLECharacteristic m_rx;
        BLEService m_serial;
};

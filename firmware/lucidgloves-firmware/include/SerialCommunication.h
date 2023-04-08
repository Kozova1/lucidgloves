#pragma once

#include "ICommunication.h"

class SerialCommunication : public ICommunication {
public:
    SerialCommunication();
    bool isOpen();
    void start();
    bool readData(char *input);
    void output(char *data);
private:
    bool m_isOpen;
};
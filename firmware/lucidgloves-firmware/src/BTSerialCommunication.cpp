//only compiles if BTSerial is set because it won't compile for a non-compatible board
#include "Arduino.h"
#include "lucidgloves-firmware.h"

#if COMMUNICATION == COMM_BTSERIAL

#include "BTSerialCommunication.h"

BTSerialCommunication::BTSerialCommunication() {
    m_isOpen = false;
}

bool BTSerialCommunication::isOpen(){
  return m_isOpen;
}

void BTSerialCommunication::start(){
  Serial.begin(115200);
  m_SerialBT.begin(BTSERIAL_DEVICE_NAME);
  Serial.println("The device started, now you can pair it with bluetooth!");
  m_isOpen = true;
}

void BTSerialCommunication::output(char* data){
  m_SerialBT.print(data);
}

bool BTSerialCommunication::readData(char* input){
  /*byte size = m_SerialBT.readBytesUntil('\n', input, 100);
  input[size] = NULL;*/
  String message = m_SerialBT.readStringUntil('\n');
  strcpy(input, message.c_str());
  return input != NULL && strlen(input) > 0;
}
#endif

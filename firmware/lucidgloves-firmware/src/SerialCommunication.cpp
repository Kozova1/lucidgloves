#include "Arduino.h"
#include "ICommunication.h"
#include "lucidgloves-firmware.h"
#include "SerialCommunication.h"

SerialCommunication::SerialCommunication() {
  m_isOpen = false;
}

bool SerialCommunication::isOpen() {
   return m_isOpen;
}

void SerialCommunication::start() {
  Serial.begin(SERIAL_BAUD_RATE);
  m_isOpen = true;
}

bool SerialCommunication::readData(char *input) {
  if (input == NULL)
    return false;
  byte size = Serial.readBytesUntil('\n', input, 100);
  input[size] = '\0';
  return size > 0;
}

void SerialCommunication::output(char *data) {
  Serial.print(data);
  Serial.flush();
}
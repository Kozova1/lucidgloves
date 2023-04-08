//only compiles if BLE is set because it won't compile for a non-compatible board
#include "Arduino.h"
#include "lucidgloves-firmware.h"

#if COMMUNICATION == COMM_BLE
#include "ArduinoBLE.h"
#include "BLECommunication.h"
#include "Encoding.h"

BLECommunication::BLECommunication() :
    m_isOpen(false), 
    m_tx(BLE_TX_UUID, BLERead | BLENotify, 75),
    m_rx(BLE_RX_UUID, BLEWrite | BLEWriteWithoutResponse, 75),
    m_serial(BLE_SERVICE_UUID) {
    m_isOpen = false;
}

bool BLECommunication::isOpen(){
  return m_isOpen;
}

void BLECommunication::start(){
  Serial.begin(115200);
  
  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");
    while (1);
  }

  BLE.setLocalName(BTSERIAL_DEVICE_NAME);
  BLE.setAdvertisedService(m_serial);
  m_serial.addCharacteristic(m_tx);
  m_serial.addCharacteristic(m_rx);
  BLE.addService(m_serial);

  int initialFlexion[5] = { 0 };
  m_tx.writeValue(encode(initialFlexion, 0, 0, false, false, false, false, false, false, false, false));

  Serial.println("The device started, now you can pair it with bluetooth!");
  m_isOpen = true;
}

void BLECommunication::output(char* data){
  m_tx.writeValue(data);
}

bool BLECommunication::readData(char* input){
  return m_rx.value();
}

#endif
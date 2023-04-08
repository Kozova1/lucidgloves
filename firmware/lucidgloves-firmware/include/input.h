#pragma once

#include "Arduino.h"

void setupInputs();
int* getFingerPositions(bool calibrating, bool reset);
int analogReadDeadzone(byte pin);
int getJoyX();
int getJoyY();
bool getButton(byte pin);
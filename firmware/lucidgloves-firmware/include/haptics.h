#pragma once

void setupServoHaptics();
void scaleLimits(int* hapticLimits, float* scaledLimits);
void dynScaleLimits(int* hapticLimits, float* scaledLimits);
void writeServoHaptics(int* hapticLimits);
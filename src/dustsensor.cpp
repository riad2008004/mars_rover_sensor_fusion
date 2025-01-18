#include <Arduino.h>
#include "dustsensor.h"

// Define pin connections
#define measurePin A2 // A0 ,A1 nosto
#define ledPower 7    // For generating pulse

// Timing constants
const int samplingTime = 280;
const int deltaTime = 40;
const int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

// keep callibration constant 170 for perfect
float calibrationConstant = 170;

void dust_sensor_setup()
{
    pinMode(ledPower, OUTPUT);
}
float read_dust_value()
{
    digitalWrite(ledPower, LOW);
    delayMicroseconds(samplingTime);

    voMeasured = analogRead(measurePin);
    delayMicroseconds(deltaTime);
    digitalWrite(ledPower, HIGH);
    delayMicroseconds(sleepTime);
    calcVoltage = voMeasured * (5.0 / 1024.0);
    dustDensity = calibrationConstant * calcVoltage - 0.1;

    return dustDensity;
}

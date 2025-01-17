#include <Arduino.h>
#include "soilsensor.h"

// define moisture sensor input pin
#define MOISTURE_PIN A2

float soil_moisture_read()
{
    float soil_moisture = 0;
    int moisture_in = analogRead(MOISTURE_PIN);
    float moisture_voltage = moisture_in * (5.0 / 1023.0);
    soil_moisture = map(moisture_voltage, 3.15, 1.84, 0.0, 100.00);
    return soil_moisture;
}
#include <Arduino.h>
#include "soilsensor.h"

// define moisture sensor input pin
#define MOISTURE_PIN A6

float soil_moisture_read()
{
    float soil_moisture = 0;
    int moisture_in = analogRead(MOISTURE_PIN);
    long double moisture_voltage = moisture_in * (5.0 / 1023.0);
    soil_moisture = ((moisture_voltage - 1.83) / (4.75 - 1.83)) * 100;
    soil_moisture = 100 - soil_moisture;
    return soil_moisture;
}
#include <Arduino.h>
#include "anemometer.h"

// define the input pin here
#define ANEMOMETER A1

float WIND_SPEED = 0;

float read_anemometer()
{
    int temp_anemo_readings = analogRead(ANEMOMETER);
    float anemo_voltage = temp_anemo_readings * (5 / 1023);
    WIND_SPEED = anemo_voltage * 6;
    return WIND_SPEED;
}

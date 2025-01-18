#include <Arduino.h>
#include "anemometer.h"

// define the input pin here
#define ANEMOMETER A5
// input pins defined

float read_anemometer()
{
    float wind_speed_ms = 0;
    float wind_speed_kh = 0;
    int temp_anemo_readings = analogRead(ANEMOMETER);
    float anemo_voltage = temp_anemo_readings * (5.0 / 1023.0);
    wind_speed_ms = anemo_voltage * 6.0;
    wind_speed_kh = wind_speed_ms * (18 / 5.0);

    return wind_speed_kh;
}

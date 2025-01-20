#include <Arduino.h>
#include "ph_sensor.h"

#define PH_SENSOR_PIN A6

float slope = -7.5;
float offset = 35.5;

int buffer_arr[10];
int temp;
unsigned long int avgval;

float read_PH_data()
{

    for (int i = 0; i < 10; i++)
    {
        buffer_arr[i] = analogRead(PH_SENSOR_PIN);
        delay(30);
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (buffer_arr[i] > buffer_arr[j])
            {
                temp = buffer_arr[i];
                buffer_arr[i] = buffer_arr[j];
                buffer_arr[j] = temp;
            }
        }
    }

    avgval = 0;
    for (int i = 2; i < 8; i++)
    {
        avgval += buffer_arr[i];
    }

    float voltage = (float)avgval * 5.0 / 1024 / 6;
    float ph_act = slope * voltage + offset;

    return ph_act;
}
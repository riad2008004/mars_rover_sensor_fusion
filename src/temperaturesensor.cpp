#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_MLX90614.h>
#include "temperaturesensor.h"

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void temperature_sensor_setup()
{

    if (!mlx.begin())
    {
        Serial.println("Temperature Sensor Not Found");
        while (1)
            ;
    }
}

float read_ambient_temp()
{
    float ambientTemp = mlx.readAmbientTempC();
    return ambientTemp;
}

float read_terget_temp()
{
    float tergetTemp = mlx.readObjectTempC();
    return tergetTemp;
}

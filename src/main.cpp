#include <Arduino.h>
#include "temperaturesensor.h"
#include "anemometer.h"
#include "soilsensor.h"
#include "dustsensor.h"
#include "dht11.h"
#include "ph_sensor.h"
#include "pressure_sensor.h"

float WIND_SPEED, SOIL_MOISTURE, AMBIENT_TEMPERATURE, TERGET_TEMPERATURE, DUST_VALUE,
    DHT_TEMPERATURE, DHT_HUMIDITY, SOIL_PH, ATMOSPHIC_PRESSURE = 0;

void setup()
{
  Serial.begin(9600);

  dht11_setup();
  temperature_sensor_setup();
  dust_sensor_setup();
}

void all_sensor_data_update()
{
  WIND_SPEED = read_anemometer();
  SOIL_MOISTURE = soil_moisture_read();
  AMBIENT_TEMPERATURE = read_ambient_temp();
  SOIL_MOISTURE = read_terget_temp();
  DUST_VALUE = read_dust_value();
  SOIL_PH = read_PH_data();
  DHT_TEMPERATURE = read_dht_temperature();
  DHT_HUMIDITY = read_dht_humidity();
  ATMOSPHIC_PRESSURE = read_pressure();
}

void loop()
{
  all_sensor_data_update();
  String data = "{\"WIND_SPEED\": \"" + String(WIND_SPEED) +
                "\", \"SOIL_MOISTURE\": \"" + String(SOIL_MOISTURE) + "\", " +
                "\"AMBIENT_TEMPERATURE\": \"" + String(AMBIENT_TEMPERATURE) +
                "\", \"DUST_VALUE\": \"" + String(DUST_VALUE) +
                "\", " + "\"SOIL_PH\": \"" + String(SOIL_PH) +
                "\", \"DHT_TEMPERATURE\": \"" + String(DHT_TEMPERATURE) +
                "\", " + "\"DHT_HUMIDITY\": \"" + String(DHT_HUMIDITY) +
                "\"ATMOSPHIC_PRESSURE\": \"" + String(ATMOSPHIC_PRESSURE) + "\"}";
  Serial.println(data);
  delay(1000);
}

#include <Arduino.h>
#include "temperaturesensor.h"
#include "anemometer.h"
#include "soilsensor.h"
#include "dustsensor.h"
#include "dht11.h"
#include "motor_drive.h"
#include "pressure_sensor.h"

const int TOKEN_EXECUTION_TIME = 100;

struct SensorData
{
  float CO = 0;
  float AMMONIA = 0;
  float ETHANOL = 0;
  float H2 = 0;
  float METHANE = 0;
  float WIND_SPEED = 0;
  float SOIL_MOISTURE = 0;
  float AMBIENT_TEMPERATURE = 0;
  float SOIL_TEMPERATURE = 0;
  float DUST_VALUE = 0;
  float DHT_TEMPERATURE = 0;
  float DHT_HUMIDITY = 0;
  float ATMOSPHERIC_PRESSURE = 0;
};

SensorData sensors;

void all_sensor_data_update();

void setup()
{
  Serial.begin(9600);
  drill_motors_setup();

  // dht11_setup();
  // temperature_sensor_setup();
  // dust_sensor_setup();
}

void loop()
{
  if (Serial.available() > 0)
  {
    String token = Serial.readStringUntil('\n');
    token.trim();
    if (token != "SENSOR_DATA_REQUEST")
    {
      execute_command(token);
    }
    else if (token == "SENSOR_DATA_REQUEST")
    {
      all_sensor_data_update();
    }
    delay(TOKEN_EXECUTION_TIME);
  }
}

void all_sensor_data_update()
{
  sensors.WIND_SPEED = read_anemometer();
  sensors.SOIL_MOISTURE = soil_moisture_read();

  // SOIL_TEMPERATURE = read_terget_temp();
  // AMBIENT_TEMPERATURE = read_ambient_temp();
  // DUST_VALUE = read_dust_value();
  // DHT_TEMPERATURE = read_dht_temperature();
  // DHT_HUMIDITY = read_dht_humidity();
  // ATMOSPHIC_PRESSURE = read_pressure();

  String data = "{";

  data += "\"CO\":" + String(sensors.CO, 2) + ",";
  data += "\"AMMONIA\":" + String(sensors.AMMONIA, 2) + ",";
  data += "\"ETHANOL\":" + String(sensors.ETHANOL, 2) + ",";
  data += "\"H2\":" + String(sensors.H2, 2) + ",";
  data += "\"METHANE\":" + String(sensors.METHANE, 2) + ",";
  data += "\"WIND_SPEED\":" + String(sensors.WIND_SPEED, 2) + ",";
  data += "\"SOIL_MOISTURE\":" + String(sensors.SOIL_MOISTURE, 2) + ",";
  data += "\"AMBIENT_TEMPERATURE\":" + String(sensors.AMBIENT_TEMPERATURE, 2) + ",";
  data += "\"SOIL_TEMPERATURE\":" + String(sensors.SOIL_TEMPERATURE, 2) + ",";
  data += "\"DUST_VALUE\":" + String(sensors.DUST_VALUE, 2) + ",";
  data += "\"DHT_TEMPERATURE\":" + String(sensors.DHT_TEMPERATURE, 2) + ",";
  data += "\"DHT_HUMIDITY\":" + String(sensors.DHT_HUMIDITY, 2) + ",";
  data += "\"ATMOSPHERIC_PRESSURE\":" + String(sensors.ATMOSPHERIC_PRESSURE, 2);
  data += "}";

  Serial.println(data);
}

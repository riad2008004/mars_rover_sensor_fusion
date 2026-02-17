#include <Arduino.h>
#include "temperaturesensor.h"
#include "anemometer.h"
#include "soilsensor.h"
#include "dustsensor.h"
#include "dht11.h"
#include "motor_drive.h"
#include "pressure_sensor.h"

const int TOKEN_EXECUTION_TIME = 500;

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
    execute_command(token);
    delay(TOKEN_EXECUTION_TIME);
  }

  // all_sensor_data_update();
  // String data = "{\"WIND_SPEED\": \"" + String(WIND_SPEED) +
  //               "\", \"SOIL_MOISTURE\": \"" + String(SOIL_MOISTURE) + "\", " +
  //               "\"AMBIENT_TEMPERATURE\": \"" + String(AMBIENT_TEMPERATURE) +
  //               "\", \"DUST_VALUE\": \"" + String(DUST_VALUE) +
  //               "\", \"DHT_TEMPERATURE\": \"" + String(DHT_TEMPERATURE) +
  //               "\", " + "\"DHT_HUMIDITY\": \"" + String(DHT_HUMIDITY) + "\", " +
  //               "\"ATMOSPHIC_PRESSURE\": \"" + String(ATMOSPHIC_PRESSURE) + "\"}";
  // Serial.println(data);
  // delay(1000);
}

void all_sensor_data_update()
{
  // WIND_SPEED = read_anemometer();
  // SOIL_MOISTURE = soil_moisture_read();
  // SOIL_TEMPERATURE = read_terget_temp();
  // AMBIENT_TEMPERATURE = read_ambient_temp();
  // // DUST_VALUE = read_dust_value();
  // DHT_TEMPERATURE = read_dht_temperature();
  // DHT_HUMIDITY = read_dht_humidity();
  // ATMOSPHIC_PRESSURE = read_pressure();
}

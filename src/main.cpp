#include <Arduino.h>
#include "temperaturesensor.h"
#include "anemometer.h"
#include "soilsensor.h"

void setup()
{
  Serial.begin(9600);

  temperature_sensor_setup();
}

void loop()
{
  Serial.print("Wind_Spd(Km/h):");
  Serial.print(read_anemometer());
  Serial.print("  ");
  Serial.print("Mois:");
  Serial.print(soil_moisture_read());
  Serial.print("%");
  Serial.print("  ");
  Serial.print("Am T(C):");
  Serial.print(read_ambient_temp());
  Serial.print("  Tergt T(C):");
  Serial.println(read_terget_temp());
  delay(500);
}

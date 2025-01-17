#include <Arduino.h>
#include "anemometer.h"
#include "soilsensor.h"

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Wind_Speed(Km/h):");
  Serial.print(read_anemometer());
  Serial.print("  ");
  Serial.print("Moisture:");
  Serial.print(soil_moisture_read());
  Serial.println("%");
  delay(500);
}

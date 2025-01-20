#include <Arduino.h>
#include "dht11.h"
#include "DHT.h"


//define DHT connection pin
#define DHT_CONNECT 2    
DHT dht;

void dht11_setup()
{
  dht.setup(DHT_CONNECT); 
}

float read_dht_humidity()
{
  

  float humidity = dht.getHumidity();
  return humidity;
}

float read_dht_temperature()
{

  delay(dht.getMinimumSamplingPeriod());

  float temperature = dht.getTemperature();
  return temperature;  
}
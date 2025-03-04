#include "DHT.h"
#include <ArduinoJson.h>

extern DHT dht;

float Temperature, Humidity, HeatIndex;
int LDRValue;

void ReadDHT11() { 
  float temperature = round(dht.readTemperature() * 10) / 10;
  float humidity = round(dht.readHumidity() * 10) / 10;
  float heatIndex = round(dht.computeHeatIndex(temperature, humidity, false) * 10) / 10;

  if (isnan(temperature) || isnan(humidity) || isnan(heatIndex)) {
    Serial.println("DHT11 sensor error!");
  } else {
    Temperature = temperature;
    Humidity = humidity;
    HeatIndex = heatIndex;

    Serial.println("Temp: " + String(Temperature) + " °C");
    Serial.println("Humidity: " + String(Humidity) + " %");
    Serial.println("Heat Index: " + String(HeatIndex) + " °C");
  }
}

void ReadLDR() {
  LDRValue = analogRead(LDR_PIN);
  Serial.println("LDR Value: " + String(LDRValue));

  if (LDRValue < 500) {
    digitalWrite(LIGHT_PIN, HIGH);
    Serial.println("Licht AAN");
  } else {
    digitalWrite(LIGHT_PIN, LOW);
    Serial.println("Licht UIT");
  }
}

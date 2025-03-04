#include "DHT.h"
#include <ArduinoJson.h>

#define DHTTYPE DHT11
#define LDR_PIN A0  
#define LIGHT_PIN D6 

DHT dht(D7, DHTTYPE);  

extern float Temperature, Humidity, HeatIndex;
extern int LDRValue;

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Setup gestart...");

  dht.begin(); 

  pinMode(LDR_PIN, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);

  Serial.println("Setup compleet!");
}

void loop() {
  Serial.println("Loop draait...");

  ReadDHT11();
  ReadLDR();
  SaveToJSON();

  delay(6000);
}

void SaveToJSON() {
  // Voorbeeld van hoe je data naar JSON kunt opslaan
  StaticJsonDocument<200> doc;

  doc["Temperature"] = Temperature;
  doc["Humidity"] = Humidity;
  doc["HeatIndex"] = HeatIndex;
  doc["LDRValue"] = LDRValue;

  String output;
  serializeJson(doc, output);

  Serial.println("JSON data: ");
  Serial.println(output);
}

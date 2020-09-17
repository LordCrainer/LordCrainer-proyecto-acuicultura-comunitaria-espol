#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

#include "./api/components/sd-card/sdCard.service.hpp"

void setup()
{
    Serial.begin(9600);
    Wire.begin();
    initSdCard()
}
void loop()
{
    String Data = leerSD("datacenter.txt");
    escribirSD(Data);
    delay(1000);
}
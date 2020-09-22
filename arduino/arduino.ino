#include <Arduino.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include "./api/components/sd-card/sdCard.service.hpp"

void setup()
{
    initSD();
    escribirSD();
    leerSD();
    mostrar();
    
}
void loop()
{
    delay(1000);
}
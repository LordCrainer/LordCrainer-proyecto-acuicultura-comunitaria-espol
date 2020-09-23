#include <Arduino.h>
#include <SoftwareSerial.h>
// #include <ESP8266WiFi.h>
// #include <ESPAsyncWebServer.h>
// #include <FS.h>
#define ARDUINOJSON_USE_LONG_LONG 1
#include <ArduinoJson.h>

#include "env.h" // Variable de entorno
#include "./api/components/sd-card/sdCard.service.hpp"
// #include "configuration/wifi-config.h"  // Sustituir con datos de vuestra red
// #include "configuration/Server.hpp"

void setup()
{
    initSD();
    escribirSD();
    leerSD();
    mostrar();
    
  // Serial.begin(115200);
  // ConnectWiFi_STA();
  // InitServer();
}

void loop()
{
    delay(1000);
}

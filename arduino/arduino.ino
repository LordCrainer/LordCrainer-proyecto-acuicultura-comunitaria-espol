#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#define ARDUINOJSON_USE_LONG_LONG 1
#include <ArduinoJson.h>

#include "env.h" // Variable de entorno
#include "configuration/wifi-config.h"  // Sustituir con datos de vuestra red
#include "configuration/Server.hpp"

String data;
void setup()
{
  Serial.begin(115200);
  ConnectWiFi_STA();
  InitServer();
}

void loop()
{
}

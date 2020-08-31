#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <ArduinoJson.h>

#include "env.h"
#include "configuration/wifi-config.h"  // Sustituir con datos de vuestra red
#include "configuration/Server.hpp"

void setup() 
{
  Serial.begin(115200);

  ConnectWiFi_AP();

  InitServer();
}

void loop() 
{
}

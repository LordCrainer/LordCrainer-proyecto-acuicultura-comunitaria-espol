#include <Arduino.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#define ARDUINOJSON_USE_LONG_LONG 1
#include <ArduinoJson.h>

#include "env.h" // Variable de entorno

#include "configuration/Server.hpp"
#include "api/utils/api.utils.hpp"
#include "api/utils/json.utils.hpp"
#include "api/components/sd-card/2.service.hpp"
#include "api/components/measurement/measurement.controller.hpp"
#include "api/components/device/1.controller.hpp"
#include "configuration/wifi-config.h"  // Sustituir con datos de vuestra red
#include "router/router.hpp"

void setup()
{
/*   initSD();
  escribirSD("datalog.txt");
  String readedData = leerSD("datalog.txt");
  mostrar(readedData); */

  Serial.begin(115200);
  ConnectWiFi_STA();
  InitServer();
}

void loop()
{
  delay(1000);
}

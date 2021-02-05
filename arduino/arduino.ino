#include <Arduino.h>
#include <SD.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <LiquidCrystal.h>
#include <FS.h>
#define ARDUINOJSON_USE_LONG_LONG 1
#include <ArduinoJson.h>

// VARIABLES DE ENTORNO
#include "env.h" // Variable de entorno

// CONFIGURACIONES GENERALES
#include "config/Server.hpp"
#include "config/wifi-config.h" // Sustituir con datos de vuestra red
#include "config/Sd-config.hpp" // Sustituir con datos de vuestra red
//#include "config/lcd-config.hpp"

// COMPONENTES DEL API REST
#include "api/utils/api.utils.hpp"
#include "api/utils/json.utils.hpp"
#include "api/components/sd-card/sd.service.hpp"
// #include "api/components/lcd/lcd.service.hpp"
#include "api/components/measurement/measurement.controller.hpp"
#include "api/components/device/1.interface/controller.hpp"

// RUTAS DEL API-REST
#include "router/router.hpp"

void setup()
{
  Serial.begin(115200);
  delay(1000);
  ConnectWiFi_AP();
  InitServer();
  boolean isActived = initSD();
  String initializeSD = "\nINICIANDO SD: " + (String)isActived;
  String serverOn = "ESCUCHANDO EN EL PUERTO: " + (String)port;

  Serial.println(initializeSD);
  Serial.println(serverOn);
  delay(1000);
  //setup_lcd();
}

void loop()
{
  Serial.println("SERVIDOR ESTABLECIDO...");
  String readedData = testSD();
  Serial.println(readedData);
  delay(3000);
  //controlBoton();
  //menuPrin();
}

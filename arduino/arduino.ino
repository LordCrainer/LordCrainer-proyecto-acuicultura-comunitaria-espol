#include <Arduino.h>
#define ARDUINOJSON_ENABLE_ARDUINO_STRING 1
#define ARDUINOJSON_USE_LONG_LONG 1
#include <SPI.h>
#include "SD.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <ArduinoJson.h>
#include <Wire.h>
// #include <OneWire.h>
// #include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include "LittleFS.h"

// VARIABLES DE ENTORNO
#include "env.h" // Variable de entorno

// CONFIGURACIONES GENERALES
#include "config/Server.hpp"
#include "config/wifi-config.h"     // Sustituir con datos de vuestra red
#include "config/Sd-config.hpp"     // Sustituir con datos de vuestra red
#include "config/sensor-config.hpp" // Sustituir con datos de vuestra red
#include "config/lcd-config.hpp"
// UTILS
#include "api/utils/api.utils.hpp"
#include "api/utils/json.utils.hpp"
// COMPONENTES DEL API REST
#include "api/components/file-system/2.adapter/controller.hpp"
#include "api/components/sd-card/controller.hpp"
#include "api/components/lcd/lcd.service.hpp"
// #include "api/components/sensor/3.application/service.hpp"
#include "api/components/measurement/2.adapter/controller.hpp"
#include "api/components/device/1.interface/controller.hpp"

// RUTAS DEL API-REST
#include "router/router.hpp"

void setup()
{
  Serial.begin(115200);
  delay(1000);
  ConnectWiFi_AP();
  InitServer();
  ;
  byte isActived = initSD();
  String initializedSD = "\nINICIANDO SD: " + (String)isActived;
  Serial.println(initializedSD);
  // String serverOn = "ESCUCHANDO EN EL PUERTO: " + (String)port;
}

void loop()
{

  //controlBoton();
  //menuPrin();
}

/*
  SD card read/write

  This example shows how to read and write data to and from an SD card file
  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

  created   Nov 2010
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

*/

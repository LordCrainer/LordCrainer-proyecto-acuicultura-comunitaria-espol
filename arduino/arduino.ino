#include <Arduino.h>
#include <SPI.h>
#include "SD.h"
// #include <SD.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#define ARDUINOJSON_USE_LONG_LONG 1
#include <ArduinoJson.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "LittleFS.h"

// VARIABLES DE ENTORNO
#include "env.h" // Variable de entorno

// CONFIGURACIONES GENERALES
#include "config/Server.hpp"
#include "config/wifi-config.h" // Sustituir con datos de vuestra red
#include "config/Sd-config.hpp" // Sustituir con datos de vuestra red
#include "config/lcd-config.hpp"

// COMPONENTES DEL API REST
#include "api/utils/api.utils.hpp"
#include "api/utils/json.utils.hpp"
#include "api/components/file-system/controller.hpp"
#include "api/components/sd-card/sd.service.hpp"
#include "api/components/lcd/lcd.service.hpp"
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
  initFS();
  //boolean isActived = initSD();
  //String initializeSD = "\nINICIANDO SD: " + (String)isActived;
/*   String serverOn = "ESCUCHANDO EN EL PUERTO: " + (String)port;

  //Serial.println(initializeSD);
  Serial.println(serverOn);
  setupLCD("BIENVENIDO");
  delay(1000);
  using namespace sdfat;
  SdFat SD;
  if (!SD.begin(PIN_SD))
  {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done."); */
}

void loop()
{
  /* Serial.println("SERVIDOR ESTABLECIDO...");
  String readedData = testSD();
  Serial.println(readedData);
  delay(3000); */
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
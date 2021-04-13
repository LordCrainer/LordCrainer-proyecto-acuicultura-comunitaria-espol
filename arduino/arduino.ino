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
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include "LittleFS.h"
#include "RTClib.h"

// VARIABLES DE ENTORNO
#include "env.h" // Variable de entorno

// CONFIGURACIONES GENERALES
#include "config/Server.hpp"
#include "config/wifi-config.h" // Sustituir con datos de vuestra red
#include "config/Sd-config.hpp"
#include "config/time-config.hpp"
#include "config/sensor-config.hpp"
#include "config/measurement-config.hpp"
#include "config/lcd-config.hpp"
// UTILS
#include "api/utils/time.utils.hpp"
#include "api/utils/fp-function.hpp"
#include "api/utils/api.utils.hpp"
#include "api/utils/json.utils.hpp"
// COMPONENTES DEL API REST
#include "api/components/file-system/2.adapter/controller.hpp"
#include "api/components/sd-card/2.adapter/controller.hpp"
#include "api/components/lcd/lcd.service.hpp"
#include "api/components/sensor/2.adapter/controller.hpp"
#include "api/components/measurement/2.adapter/controller.hpp"
#include "api/components/device/2.adapter/controller.hpp"

// RUTAS DEL API-REST
#include "router/router.hpp"

void setup()
{
  // PRE
  global_temp = getTemp();
  
  Serial.flush();
  initTime();
  // SETUP
  Serial.begin(115200);
  ConnectWiFi_STA();
  InitServer();
  initLCD("INICIANDO...");
  boolean isActived = initSD();
  Serial.println("\nESTADO DEL SD: " + String(isActived));
}

void loop()
{
  lastTime = getTempDelay(lastTime, 3000);
  //lcdControlButton();
  //lcdPrintMenu();
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

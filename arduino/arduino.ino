#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <FS.h>
#define ARDUINOJSON_ENABLE_ARDUINO_STRING 1
#define ARDUINOJSON_USE_LONG_LONG 1
#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include "SD.h" // #include "LittleFS.h"
#include <DallasTemperature.h>
#include <OneWire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"

// ******** ARCHIVOS DEL PROGRAMA ********
// VARIABLES DE ENTORNO
#include "env.h" // Variable de entorno como: red wifi

// CONFIGURACIONES GENERALES
#include "config/wifi-config.h" 
#include "config/Sd-config.hpp"
#include "config/time-config.hpp"
#include "config/sensor-config.hpp"
#include "config/measurement-config.hpp"
#include "config/lcd-config.hpp"

// INFRAESTRUCTURA
#include "Infraestructure/server/Server.hpp"
#include "Infraestructure/bd/sd-card.repository.hpp"

// UTILIDADES PARA EL API REST
#include "api/utils/index.hpp"

// COMPONENTES DEL API REST
#include "api/components/share/2.adapter/controller.hpp"
#include "api/components/sd-card/2.adapter/controller.hpp"
#include "api/components/lcd/lcd.service.hpp"
#include "api/components/sensor/2.adapter/controller.hpp"
#include "api/components/measurement/2.adapter/controller.hpp"
#include "api/components/device/2.adapter/controller.hpp"

// RUTAS DEL API-REST
#include "adapter/router.hpp"

void setup()
{
  Serial.flush();
  Serial.begin(115200);
  boolean isActived = initSD() ? true: false;
  // SETUP
  initTime();
  ConnectWiFi_STA();
  InitServer();
  initLCD("INICIANDO...");
  Serial.println("\nSTATUS SD: " + String(isActived));
  initSensors();
}

void loop()
{
  lastTime = getTemperatureWithDelay(lastTime, 3000);
}

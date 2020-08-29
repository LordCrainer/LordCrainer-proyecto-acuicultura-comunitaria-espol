#include "sensor.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Arduino.h>




void setup() {
  // put your setup code here, to run once:
  // Iniciamos la comunicación serie
    
    Serial.begin(9600);
    setup_prog();
}

void loop() 
{
  
    
  sensorTEMPE();
  resultadoPH();
  oxigenoD();
  
}
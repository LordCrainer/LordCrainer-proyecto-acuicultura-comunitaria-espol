#include <Arduino.h>
#include "env.h"
#include "configuration/Server.hpp"

void setup()
{
  // put your setup code here, to run once:
  // Iniciamos la comunicación serie

  Serial.begin(115200);
  setup_prog();
}

void loop()
{

  sensorTEMPE();
  resultadoPH();
  oxigenoD();
}
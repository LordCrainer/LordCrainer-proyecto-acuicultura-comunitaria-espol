#include "device.service.hpp"

void startMeasurement(AsyncWebServerRequest *request)
{
  String data = readDataFromSD();
  request->send(200, "application/json", data);
}

void allConfiguration(AsyncWebServerRequest *request)
{
  String data = readDataConfiguration();
  request->send(200, "application/json", data);
}
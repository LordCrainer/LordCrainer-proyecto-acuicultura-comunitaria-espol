#include "2.service.hpp"

void allConfiguration(AsyncWebServerRequest *request)
{
  String data = getAllConfig();
  request->send(200, "application/json", data);
}

void startMeasurement(AsyncWebServerRequest *request)
{
  String response = startDevice();
  request->send(200, "application/json", response);
}

#include "../2.application/index.hpp"

void allConfiguration(AsyncWebServerRequest *request)
{
  String data = getAllConfig();
  request->send(200, "application/json", data);
}

void startDevice(AsyncWebServerRequest *request)
{
  String response = startMeasurement();
  request->send(200, "application/json", response);
}

#include "../2.application/index.hpp"

void getAllConfig(AsyncWebServerRequest *request)
{
  String data = allConfig();
  request->send(200, "application/json", data);
}

void startDevice(AsyncWebServerRequest *request)
{
  String response = startMeasurement();
  request->send(200, "application/json", response);
}

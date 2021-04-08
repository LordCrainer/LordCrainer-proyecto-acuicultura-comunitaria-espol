#include "../3.application/index.hpp"

void getAllConfig(AsyncWebServerRequest *req)
{
  String RESPONSE_END = allConfig();
  req->send(200, "application/json", RESPONSE_END);
}

void startingDevice(AsyncWebServerRequest *req)
{
  String res;
  String iteration = getParameterByName(req, "iteration");
  Serial.print("INTERATION IS: ");
  Serial.println(iteration);
  if (iteration == "")
  {
    Serial.println("If IN");
    res = startOneMeasurement("1517383146498", 25);
  }
  else
  {
    Serial.println("If OUT");
    res = startDevice(req);
  }
  req->send(200, "application/json", res);
}

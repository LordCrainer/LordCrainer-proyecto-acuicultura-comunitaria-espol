#include "../3.application/index.hpp"

void getAllConfig(AsyncWebServerRequest *req)
{
  String RESPONSE_END = allConfig();
  req->send(200, "application/json", RESPONSE_END);
}

void startingDevice(AsyncWebServerRequest *req)
{
  String res;
  // String iteration = getParameterByName(req, "iteration");
  // byte pool_id = getParameterByName(req, "pool_id").toInt();
  res = startDevice(req);
  /*   if (iteration == "")
  {
    res = startOneMeasurement("1517383146500", pool_id);
  }
  else
  {
    res = startDevice(req);
  } */
  req->send(200, "application/json", res);
}

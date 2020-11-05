#include "application/configuration.hpp"
// incluir a 


void allConfiguration(AsyncWebServerRequest *request)
{
  String data = getAllConfig();
  request->send(200, "application/json", data);
}

void initMeasurement(AsyncWebServerRequest *request){
  const char *PARAM_FILTER = "pool_id";
  String poolId = request->getParam(PARAM_FILTER)->value();
  if (request->hasParam(PARAM_FILTER))
  {
    getFiltered(request);
  }
}
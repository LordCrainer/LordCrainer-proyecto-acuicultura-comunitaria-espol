#include "../3.use-case/index.hpp"

void gettingTempSensor(AsyncWebServerRequest *req)
{
    String json = getOneSensor(GLOBAL_TEMP);
    req->send(200, "application/json", json);
}
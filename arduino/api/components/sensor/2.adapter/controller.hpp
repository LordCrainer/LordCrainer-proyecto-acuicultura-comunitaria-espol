#include "../3.use-case/index.hpp"

void gettingSensor(AsyncWebServerRequest *req)
{
    ISensor sensor;
    sensor.name = getParameterByName(req, "name");
    String json = getOneSensor(sensor);
    req->send(200, "application/json", json);
}
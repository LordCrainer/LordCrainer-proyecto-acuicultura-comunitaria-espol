#include "../3.application/index.hpp"

void homeRequest(AsyncWebServerRequest *req)
{
    req->send(200, "text/plain", "Hello, world");
}

void notFound(AsyncWebServerRequest *req)
{
    String json = objToJson("message", "Page (route) not found");
    req->send(404, "application/json", json);
}
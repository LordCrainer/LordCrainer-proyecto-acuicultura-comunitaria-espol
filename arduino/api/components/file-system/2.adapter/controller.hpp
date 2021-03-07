#include "../3.use-case/service.hpp"

void readingFS(AsyncWebServerRequest *request)
{
    String response = readFS("data.json");
    request->send(200, "application/json", response);
}
void writingFS(AsyncWebServerRequest *request)
{
    String json;
    DynamicJsonDocument doc(250);
    doc["data"] = "Prueba SD exitosa";
    serializeJson(doc, json);
    String response = writeFS("data.json", json);
    request->send(200, "application/json", json);
}

void appendFS(AsyncWebServerRequest *request)
{
    String json;
    DynamicJsonDocument doc(250);
    doc["data"] = "Prueba APPEND FILE";
    serializeJson(doc, json);
    String response = appendFile("data.json", json);
    request->send(200, "application/json", json);
}
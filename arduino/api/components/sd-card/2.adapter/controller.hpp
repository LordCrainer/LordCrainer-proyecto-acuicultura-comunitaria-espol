#include "../3.use-case/index.hpp"

void writingSD(AsyncWebServerRequest *request)
{
    String filename = getParameterByName(request, "filename");
    String data = getParameterByName(request, "data");
    byte isWritten = writeSD(filename, data);
    request->send(200, "application/json", data);
}

void readingSD(AsyncWebServerRequest *request)
{
    String filename = getParameterByName(request, "filename");
    String readedData = readSD(filename);
    Serial.println(String(readedData.length()));
    request->send(200, "application/json", {});
}

void appendSD(AsyncWebServerRequest *request)
{
    String json;
    StaticJsonDocument<24> doc;
    doc["status"] = "OK";
    serializeJson(doc, json);
    request->send(200, "application/json", json);
}

void directorySD(AsyncWebServerRequest *request)
{
    String json;
    StaticJsonDocument<24> doc;
    doc["status"] = "OK";
    serializeJson(doc, json);
    File root = SD.open("/");
    printDirectory(root, 0);
    request->send(200, "application/json", json);
}

void deletingSD(AsyncWebServerRequest *request)
{
}
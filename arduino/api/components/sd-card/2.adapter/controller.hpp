#include "../3.use-case/index.hpp"

void writingSD(AsyncWebServerRequest *request)
{
    String filename = getParameterByName(request, "filename");
    String data = getParameterByName(request, "data");
    const boolean isWritten = writeSD(filename, data);
    request->send(200, "application/json", data);
}

void readingSD(AsyncWebServerRequest *request)
{
    String filename = getParameterByName(request, "filename");
    String readedData = readSD(filename);
    request->send(200, "application/json", readedData);
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
    String *arr = findFileByName("/", "P1_");
    Serial.println(arr[0]);
    findFileByName("/", "P30_");
    printDirectory(root, 0);
    request->send(200, "application/json", json);
}

void deletingSD(AsyncWebServerRequest *request)
{
    String json;
    StaticJsonDocument<24> doc;
    String filename = getParameterByName(request, "filename");
    boolean isDeleted = deleteSD(filename);
    doc["status"] = isDeleted;
    serializeJson(doc, json);
    request->send(200, "application/json", json);
}
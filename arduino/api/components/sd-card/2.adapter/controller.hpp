#include "../3.use-case/index.hpp"

void writingSD(AsyncWebServerRequest *request)
{
    String json;
    StaticJsonDocument<64> doc;
    doc["name"] = "COMUNITARIAS";
    doc["id"] = 1;
    JsonArray data = doc.createNestedArray("data");
    data.add(48.75608);
    data.add(2.302038);
    serializeJson(doc, json);
    byte isWritten = writeSD("data.json", json);
    request->send(200, "application/json", json);
}

void readingSD(AsyncWebServerRequest *request)
{
    String readedData = readSD("data.json");
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
    printDirectory(root, 0);
    request->send(200, "application/json", json);
}
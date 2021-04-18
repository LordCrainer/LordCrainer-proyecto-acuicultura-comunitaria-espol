#include "../3.use-case/index.hpp"

void writingSD(AsyncWebServerRequest *req)
{
    String filename = getParameterByName(req, "filename");
    String data = getParameterByName(req, "data");
    const boolean isWritten = writeSD(filename, data);
    req->send(200, "application/json", data);
}

void readingSD(AsyncWebServerRequest *req)
{
    String filename = getParameterByName(req, "filename");
    String readedData = readSD(filename);
    req->send(200, "application/json", readedData);
}

void appendSD(AsyncWebServerRequest *req)
{
    String json;
    StaticJsonDocument<24> doc;
    doc["status"] = "OK";
    serializeJson(doc, json);
    req->send(200, "application/json", json);
}

void directorySD(AsyncWebServerRequest *req)
{
    String json;
    json = "[" + printDirectory(SD.open("/"), 0) + "]";
    req->send(200, "application/json", json);
}

void deletingSD(AsyncWebServerRequest *req)
{
    // PARAMS
    byte filemax = getParameterByName(req, "filemax").toInt();
    String filename = getParameterByName(req, "filename");
    //VALIDATION
    filemax = filemax == 0 ? 10 : filemax;
    filename = filename == "" ? "" : filename + ",";
    // ACTIONS
    String data = execManyFiles(deleteSD, filename, ",", filemax);
    // WRAP
    data = "{\"data\": \"" + data + "\"}";
    req->send(200, "application/json", data);
}
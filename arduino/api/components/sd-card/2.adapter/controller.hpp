#include "../3.use-case/index.hpp"

void writingSD(AsyncWebServerRequest *req)
{
    String filename = getParameterByName(req, "filename");
    String data = getParameterByName(req, "data");
    const boolean isWritten = writeSD(filename, data);
    req->send(201, "application/json", data);
}

void readingSD(AsyncWebServerRequest *req)
{
    String filename = getParameterByName(req, "filename");
    String readedData = readSD(filename);
    req->send(200, "application/json", readedData);
}

void appendSD(AsyncWebServerRequest *req)
{
    String json = objToJson("status", "OK", 24);
    req->send(200, "application/json", json);
}

void directorySD(AsyncWebServerRequest *req)
{
    String path = getParameterByName(req, "path");
    //Validation
    path = path = "" ? "/" : path;
    //Actions
    String json = "[" + printDirectory(SD.open(path), 0) + "]";
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
    data = objToJson("data", data);
    // data = "{\"data\": \"" + data + "\"}";
    req->send(204, "application/json", data);
}

void overwrittingSD(AsyncWebServerRequest *req)
{
    String filename = getParameterByName(req, "filename");
    String data = getParameterByName(req, "data");
    const boolean isOverWritten = overwriteSD(filename, data);
    req->send(201, "application/json", data);
}


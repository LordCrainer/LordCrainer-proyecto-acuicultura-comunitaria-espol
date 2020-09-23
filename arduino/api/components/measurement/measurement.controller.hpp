#include "measurement.service.hpp"

const char *PARAM_FILTER = "filter";

void getAll(AsyncWebServerRequest *request)
{
  String data = readDataFromSD();
  request->send(200, "application/json", data);
}

void getFiltered(AsyncWebServerRequest *request)
{
  String message = "Get filtered by " + request->getParam(PARAM_FILTER)->value();
  Serial.println(message);
  request->send(200, "text/plain", message);
}

void getById(AsyncWebServerRequest *request, String path)
{
  int id = GetIdFromURL(request, path);
  String data = readDataFromSD();
  String filteredData = findById(data, id);
  request->send(200, "application/json", filteredData);
}

void getRequest(AsyncWebServerRequest *request)
{
  String path = "/measurement/";
  if (request->hasParam(PARAM_FILTER))
  {
    getFiltered(request);
  }
  else if (request->url().indexOf(path) != -1)
  {
    getById(request, path);
  }
  else
  {
    getAll(request);
  }
}

void postRequest(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
{
  String bodyContent = GetBodyContent(data, len);

  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, bodyContent);
  if (error)
  {
    request->send(400);
    return;
  }

  String string_data = doc["data"];
  String message = "Create " + string_data;
  Serial.println(message);
  request->send(200, "application/json", message);
}

void patchRequest(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
{
  int id = GetIdFromURL(request, "/item/");
  String bodyContent = GetBodyContent(data, len);

  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, bodyContent);
  if (error)
  {
    request->send(400);
    return;
  }

  String string_data = doc["data"];
  String message = String("Update ") + id + " with " + string_data;
  Serial.println(message);
  request->send(200, "application/json", message);
}

void putRequest(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
{
  int id = GetIdFromURL(request, "/item/");
  String bodyContent = GetBodyContent(data, len);

  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, bodyContent);
  if (error)
  {
    request->send(400);
    return;
  }

  String string_data = doc["data"];
  String message = String("Replace ") + id + " with " + string_data;
  Serial.println(message);
  request->send(200, "application/json", message);
}

void deleteRequest(AsyncWebServerRequest *request)
{
  int id = GetIdFromURL(request, "/measurement/");
  String json;
  String message = String("DELETED ") + id + " SUCESSFULLY";
  json = objectToJsonDynamic("message", message, 50);
  Serial.println(json);
  request->send(200, "application/json", json);
}
#include "measurement.service.hpp"

const char *PARAM_FILTER = "filter";

void getAll(AsyncWebServerRequest *request)
{
  String data = testAllMeasurement();
  Serial.println(data);
  request->send(200, "application/json", data);
}

void getFiltered(AsyncWebServerRequest *request)
{
  String message = "Get filtered by " + request->getParam(PARAM_FILTER)->value();
  Serial.println(message);
  request->send(200, "application/json", message);
}

void getById(AsyncWebServerRequest *request, String path)
{
  String data = testAllMeasurement();
  String json;
  int id = GetIdFromURL(request, path);

  DynamicJsonDocument doc(1024);
  DynamicJsonDocument doc1(1024);

  deserializeJson(doc, data);
  int elements = sizeof(doc)/sizeof(doc[0]);

  for (int i=0; i<elements; i++)
    {
      JsonObject root_0 = doc[i];
      if (int root_0_pool_id = root_0["pool_id"] == id)
        doc1.add(doc[i]);
    }
  serializeJson(doc1, json);
  Serial.println(json);
  request->send(200, "application/json", json);
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

void arduinoJsonCommonVariable(AsyncWebServerRequest *request)
{
  String json;
  DynamicJsonDocument doc(250);
  doc["url"] = request->url();
  doc["host"] = request->host();
  doc["method"] = request->method();
  serializeJson(doc, json);
  request->send(200, "application/json", json);
}
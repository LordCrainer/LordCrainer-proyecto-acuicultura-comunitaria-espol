#include "../3.use-case/index.hpp"

const char *PARAM_FILTER = "filter";
// Measurement/apdater: Leyendo las mediciones
void readingMeasurement(AsyncWebServerRequest *req)
{
  String route = "/measurement/";
  String res;
  if (req->url().indexOf(route) != -1)
  {
    res = readOneMeasurement(req, route);
  }
  else
  {
    res = readAllMeasurement(req);
  }
  req->send(200, "application/json", res);
}

void postRequest(AsyncWebServerRequest *req, uint8_t *data, size_t len, size_t index, size_t total)
{
  String bodyContent = getBodyContent(data, len);

  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, bodyContent);
  if (error)
  {
    req->send(400);
    return;
  }

  String json = doc["data"];
  String message = "Create " + json;
  Serial.println(message);
  req->send(200, "application/json", json);
}

void patchRequest(AsyncWebServerRequest *req, uint8_t *data, size_t len, size_t index, size_t total)
{
  int id = getIdFromURL(req, "/item/");
  String bodyContent = getBodyContent(data, len);

  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, bodyContent);
  if (error)
  {
    req->send(400);
    return;
  }

  String string_data = doc["data"];
  String message = String("Update ") + id + " with " + string_data;
  Serial.println(message);
  req->send(200, "application/json", message);
}

void putRequest(AsyncWebServerRequest *req, uint8_t *data, size_t len, size_t index, size_t total)
{
  int id = getIdFromURL(req, "/item/");
  String bodyContent = getBodyContent(data, len);

  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, bodyContent);
  if (error)
  {
    req->send(400);
    return;
  }

  String string_data = doc["data"];
  String message = String("Replace ") + id + " with " + string_data;
  Serial.println(message);
  req->send(200, "application/json", message);
}

void deleteRequest(AsyncWebServerRequest *req)
{
  int id = getIdFromURL(req, "/measurement/");
  String json;
  String message = String("DELETED ") + id + " SUCESSFULLY";
  json = objToJson("message", message, 50);
  Serial.println(json);
  req->send(200, "application/json", json);
}
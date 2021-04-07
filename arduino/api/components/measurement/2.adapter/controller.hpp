#include "../3.use-case/index.hpp"

const char *PARAM_FILTER = "filter";

void getMeasurement(AsyncWebServerRequest *request)
{
  String path = "/measurement/";
  String response;
  // /measurement/12 => 12
  // response = request->url().indexOf(path) != -1 ? getMeasurementById(request, path) : getMeasurementtAll(request);
  if (request->url().indexOf(path) != -1)
  {
    response = readOneMeasurement(request, path);
  }
  /* else if (request->hasParam(PARAM_FILTER))
  {
    response = getFiltered(request);
  } */
  else
  {
    response = readAllMeasurement(request);
  }
  request->send(200, "application/json", response);
}

void postRequest(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
{
  String bodyContent = getBodyContent(data, len);

  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, bodyContent);
  if (error)
  {
    request->send(400);
    return;
  }

  String json = doc["data"];
  String message = "Create " + json;
  Serial.println(message);
  request->send(200, "application/json", json);
}

void patchRequest(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
{
  int id = getIdFromURL(request, "/item/");
  String bodyContent = getBodyContent(data, len);

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
  int id = getIdFromURL(request, "/item/");
  String bodyContent = getBodyContent(data, len);

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
  int id = getIdFromURL(request, "/measurement/");
  String json;
  String message = String("DELETED ") + id + " SUCESSFULLY";
  json = objectToJsonDynamic("message", message, 50);
  Serial.println(json);
  request->send(200, "application/json", json);
}
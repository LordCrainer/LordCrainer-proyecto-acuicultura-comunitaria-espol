void homeRequest(AsyncWebServerRequest *request) {
  request->send(200, "text/plain", "Hello, world");
}

void notFound(AsyncWebServerRequest *request) {
	request->send(404, "text/plain", "Not found");
}

String findById(String data, int id)
{
  const size_t capacity = 4 * JSON_ARRAY_SIZE(3) + 9 * JSON_OBJECT_SIZE(3) + 3 * JSON_OBJECT_SIZE(4);
  String json;

  DynamicJsonDocument doc(capacity);
  DynamicJsonDocument doc1(capacity);

  deserializeJson(doc, data);

  int length = doc.size();
  Serial.println(length);

  for (int i = 0; i < length; i++)
  {
    JsonObject root_0 = doc[i];
    if (root_0["pool_id"] == id)
      doc1.add(doc[i]);
  }
  serializeJson(doc1, json);
  return json;
}

void getHeaders(AsyncWebServerRequest *request)
{
  int headers = request->headers();
  int i;
  for (i = 0; i < headers; i++)
  {
    AsyncWebHeader *h = request->getHeader(i);
    Serial.printf("HEADER[%s]: %s\n", h->name().c_str(), h->value().c_str());
  }
}

void getAllParameters(AsyncWebServerRequest *request)
{
  int params = request->params();
  for (int i = 0; i < params; i++)
  {
    AsyncWebParameter *p = request->getParam(i);
    if (p->isFile())
    { //p->isPost() is also true
      Serial.printf("FILE[%s]: %s, size: %u\n", p->name().c_str(), p->value().c_str(), p->size());
    }
    else if (p->isPost())
    {
      Serial.printf("POST[%s]: %s\n", p->name().c_str(), p->value().c_str());
    }
    else
    {
      Serial.printf("GET[%s]: %s\n", p->name().c_str(), p->value().c_str());
    }
  }
}

void arduinoJsonCommonVariable(AsyncWebServerRequest *request)
{
  String json;
  DynamicJsonDocument doc(250);
  doc["url"] = request->url();
  doc["host"] = request->host();
  doc["method"] = request->method();
  doc["PARAMS"] = request->params();
  doc["HEADERS"] = request->headers();
  serializeJson(doc, json);
  request->send(200, "application/json", json);
}
void merge(JsonObject dest, JsonObjectConst src)
{
  for (auto kvp : src)
  {
    dest[kvp.key()] = kvp.value();
  }
}

void homeRequest(AsyncWebServerRequest *request)
{
  request->send(200, "text/plain", "Hello, world");
}

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Not found");
}

String GetBodyContent(uint8_t *data, size_t len)
{
  String content = "";
  for (size_t i = 0; i < len; i++)
  {
    content.concat((char)data[i]);
  }
  return content;
}

int GetIdFromURL(AsyncWebServerRequest *request, String root)
{
  String string_id = request->url(); // /measurement/1
  string_id.replace(root, "");       // "1"
  int id = string_id.toInt();        //  1
  return id;
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

  // const size_t capacity = JSON_ARRAY_SIZE(3) + 4 * JSON_OBJECT_SIZE(1) + 25;
  //String json;
  //StaticJsonDocument<capacity> doc;
  int nParams = request->params();
  Serial.println(nParams);
  //JsonArray paramsList = doc.to<JsonArray>();
  //JsonObject param = doc.createNestedObject();
  for (int i = 0; i < nParams; i++)
  {
    AsyncWebParameter *p = request->getParam(i);
    //param["pool_id"] = p->value().c_str();
    //paramsList[i] = param["pool_id"];

    if (p->isFile())
    { //p->isPost() is also true
      Serial.printf("FILE[%s]: %s, size: %u\n", p->name().c_str(), p->value().c_str(), p->size());
      //paramsList["size"] = p->size();
    }
    Serial.printf("FILE[%s]: %s, size: %u\n", p->name().c_str(), p->value().c_str(), p->size());
  }
  request->send(200, "application/json", {});
  //serialize(doc, json);
  //return json;
}

void arduinoJsonCommonVariable(AsyncWebServerRequest *request)
{
  String json;
  StaticJsonDocument<150> doc;
  doc["url"] = request->url();
  doc["host"] = request->host();
  doc["method"] = request->method();
  doc["PARAMS"] = request->params();
  doc["HEADERS"] = request->headers();
  serializeJson(doc, json);
  request->send(200, "application/json", json);
}
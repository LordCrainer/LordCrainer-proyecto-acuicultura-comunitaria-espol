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

String getBodyContent(uint8_t *data, size_t len)
{
  String content = "";
  for (size_t i = 0; i < len; i++)
  {
    content.concat((char)data[i]);
  }
  return content;
}

int getIdFromURL(AsyncWebServerRequest *request, String root)
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

String getParameterByName(AsyncWebServerRequest *request, const char *param)
{
  if (request->hasArg(param))
  {
    return request->arg(param);
  }
  return "";
}

void getAllParameters(AsyncWebServerRequest *request)
{
  int nParams = request->params();
  for (int i = 0; i < nParams; i++)
  {
    AsyncWebParameter *p = request->getParam(i);

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

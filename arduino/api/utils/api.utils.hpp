void merge(JsonObject dest, JsonObjectConst src)
{
  for (auto kvp : src)
  {
    dest[kvp.key()] = kvp.value();
  }
}

void homeRequest(AsyncWebServerRequest *req)
{
  req->send(200, "text/plain", "Hello, world");
}

void notFound(AsyncWebServerRequest *req)
{
  String json = objToJson("message", "Page (route) not found");
  req->send(404, "application/json", json);
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

int getIdFromURL(AsyncWebServerRequest *req, String route)
{
  String string_id = req->url(); // /measurement/1
  string_id.replace(route, "");  // "1"
  int id = string_id.toInt();    //  1
  return id;
}

void getHeaders(AsyncWebServerRequest *req)
{
  int headers = req->headers();
  int i;
  for (i = 0; i < headers; i++)
  {
    AsyncWebHeader *h = req->getHeader(i);
    Serial.printf("HEADER[%s]: %s\n", h->name().c_str(), h->value().c_str());
  }
}

String getParameterByName(AsyncWebServerRequest *req, String param)
{
  if (req->hasArg(param.c_str()))
  {
    return req->arg(param.c_str());
  }
  return "";
}

/* IObject *getParamsByName(AsyncWebServerRequest *req, String params[])
{
  byte size = sizeof(params);
  IObject obj[size];
  for (byte i = 0; i < size; i++)
  {
    obj[params[i]] = getParameterByName(req, params[i]);
    //obj[i].key = params[i];
    //obj[i].value = getParameterByName(req, params[i]);
  }
  return obj;
} */

void getAllParameters(AsyncWebServerRequest *req)
{
  int nParams = req->params();
  for (int i = 0; i < nParams; i++)
  {
    AsyncWebParameter *p = req->getParam(i);

    if (p->isFile())
    { //p->isPost() is also true
      Serial.printf("FILE[%s]: %s, size: %u\n", p->name().c_str(), p->value().c_str(), p->size());
      //paramsList["size"] = p->size();
    }
    Serial.printf("FILE[%s]: %s, size: %u\n", p->name().c_str(), p->value().c_str(), p->size());
  }
  req->send(200, "application/json", {});
  //serialize(doc, json);
  //return json;
}

/* String findById(String data, int id)
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
} */
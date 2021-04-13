String dirModel(IDirectory dir)
{
  int capacity = 50 + dir.name.length() + dir.content.length();
  String json;
  DynamicJsonDocument doc(capacity);
  doc["name"] = dir.name;
  doc["type"] = dir.type;
  doc["content"] = serialized(dir.content);
  serializeJson(doc, json);
  return json;
}
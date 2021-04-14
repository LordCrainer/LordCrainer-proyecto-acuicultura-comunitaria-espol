/**
 *  sd-card/domain: Modela la estructura IFiles y lo serializa a json
 *  @param  file  Estructura IFiles
 */
String fileModel(IFiles file)
{
  int capacity = 50 + file.name.length();
  String json;
  DynamicJsonDocument doc(capacity);
  doc["name"] = file.name;
  doc["type"] = file.type;
  doc["size"] = file.size;
  serializeJson(doc, json);
  return json;
}
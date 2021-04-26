
// Convertir un
String objToJson(String key, String value, int sizeDoc = 1024)
{
    String json;
    DynamicJsonDocument doc(sizeDoc);
    doc[key] = value;
    serializeJson(doc, json);
    return json;
}

String jsonToString(String json, String key, int sizeDoc = 1024)
{
    DynamicJsonDocument doc(sizeDoc);
    deserializeJson(doc, json);
    String value = doc[key];
    return value;
}

String serializedToArray(String data)
{
    return "[" + data + "]";
}
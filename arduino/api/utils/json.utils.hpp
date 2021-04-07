
// Convertir un
String objectToJsonDynamic(String key, String value, int sizeDoc = 1024)
{
    String json;
    DynamicJsonDocument doc(sizeDoc);
    doc[key] = value;
    serializeJson(doc, json);
    return json;
}

String JsonToTextDynamic(String json, int sizeDoc = 1024)
{
    DynamicJsonDocument doc(sizeDoc);
    deserializeJson(doc, json);
    return json;
}

String serializedToArray(String data, const int capacity)
{
    String json;
    DynamicJsonDocument doc(capacity);
    JsonArray array = doc.to<JsonArray>();
    array.add(data);
    serializeJson(doc, json);
    return json;
}
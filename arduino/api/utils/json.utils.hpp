// callFunction: Función como parámetro en otra función.
typedef void (*callFunction)(void);

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

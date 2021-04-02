String sensorModel(IParams data)
{
    String json;
    StaticJsonDocument<50> doc;
    doc["value"] = data.value;
    doc["name"] = data.name;
    serializeJson(doc, json);
    return json;
}
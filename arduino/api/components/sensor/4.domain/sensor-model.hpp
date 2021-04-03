String sensorModel(IParams data)
{
    String json;
    StaticJsonDocument<50> doc;
    JsonObject obj = doc.as<JsonObject>();
    doc["value"] = data.value;
    doc["name"] = data.name;
    serializeJson(doc, json);
    return json;
}

String modelAllSensor(IParams data1, IParams data2)
{
    String json;
    StaticJsonDocument<150> doc;
    String Temp = sensorModel(data1);
    String PH = sensorModel(data2);
    JsonDocument arr = doc.createNestedArray("params");
    arr[0] = Temp;
    //arr.add(Temp);
    //arr.add(PH);
    serializeJson(doc, json);
    return json;
}
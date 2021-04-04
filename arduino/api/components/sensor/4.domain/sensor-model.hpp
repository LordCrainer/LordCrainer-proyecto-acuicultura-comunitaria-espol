// Modela los datos de un sensor a json
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

// Modela los datos de todos los sensores a json
String modelAllSensor(IParams data1, IParams data2)
{
    String json;
    StaticJsonDocument<150> doc;
    String Temp = sensorModel(data1);
    String PH = sensorModel(data2);
    JsonArray array = doc.to<JsonArray>();
    array.add(Temp);
    array.add(PH);
    //arr.add(Temp);
    //arr.add(PH);
    serializeJson(doc, json);
    return json;
}
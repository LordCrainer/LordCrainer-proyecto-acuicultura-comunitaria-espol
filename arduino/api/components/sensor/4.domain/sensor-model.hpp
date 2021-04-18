/**
	 * Sensor/domain: Modela la estructura IParams para serializar en un json
     * @param data  Estructura IParams
	 */
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

/**
	 * Sensor/domain: Modela todas interfaces IParams serializandolos a json (Se escala manualmente)
     * @param  params# Todos los parámetros tienen como estructura IParams
	 */
String modelAllSensor(IParams params[])
{
    String data = "";
    byte longitud = sizeof(params);
    for (byte i = 0; i < longitud; i++)
    {
        data = data + "," + sensorModel(params[i]);
    }
    data.remove(0, 1);
    return data;
    // String Temp = sensorModel(data1);
    // String PH = sensorModel(data2);
    // String DO = sensorModel(data3);
    // return Temp + "," + PH + "," + DO;
}

IParams initilizeSensor(String filename)
{
    IParams param;
    String json;
    StaticJsonDocument<50> doc;
    json = readSD(filename);
    deserializeJson(doc, json);
    param.max = doc["max"].as<double>();
    param.min = doc["min"].as<double>();
    param.name = doc["name"].as<String>();
    return param;
}
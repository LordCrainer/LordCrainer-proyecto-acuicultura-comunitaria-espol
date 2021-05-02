/**
	 * Sensor/domain: Modela la estructura ISensor para serializar en un json
     * @param data  Estructura ISensor
	 */
String sensorModel(ISensor sensor)
{
    String json;
    StaticJsonDocument<100> doc;
    // JsonObject obj = doc.as<JsonObject>();
    doc["value"] = sensor.value;
    doc["name"] = sensor.name;
    doc["alert"] = sensor.alert;
    serializeJson(doc, json);
    return json;
}

/**
	 * Sensor/domain: Modela todas interfaces ISensor serializandolos a json (Se escala manualmente)
     * @param  params# Todos los parámetros tienen como estructura ISensor
	 */
String modelAllSensor(ISensor params[])
{
    String data = "";
    byte longitud = sizeof(params) - 1;
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

String sensorStatus(ISensor param)
{
    if (param.value == NULL)
    {
        return "NOT VALUE";
    }
    if (param.max == NULL || param.min == NULL)
    {
        return "MAX OR MIN NULL";
    }
    if (param.min == param.max)
    {
        return "EQUAL MAX & MIN";
    }
    if (param.value > param.max)
    {
        return "OVER";
    }
    if (param.value < param.min)
    {
        return "UNDER";
    }
    return "OK";
}
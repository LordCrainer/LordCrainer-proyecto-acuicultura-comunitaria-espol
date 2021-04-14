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
     * @param  data# Todos los parámetros tienen como estructura IParams
	 */
String modelAllSensor(IParams data1, IParams data2, IParams data3)
{
    String Temp = sensorModel(data1);
    String PH = sensorModel(data2);
    String DO = sensorModel(data3);
    return Temp + "," + PH + "," + DO;
}
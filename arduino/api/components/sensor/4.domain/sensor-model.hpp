/**
	 * Sensor/domain: Modela la estructura ISensor para serializar en un json
     * @param data  Estructura ISensor
	 */
String sensorModel(ISensor data)
{
    String json;
    StaticJsonDocument<50> doc;
    JsonObject obj = doc.as<JsonObject>();
    doc["value"] = data.value;
    doc["name"] = data.name;
    doc["alert"] = data.alert;
    Serial.println("SENSOR/DOMAIN/MODEL_1 " + data.name;
    serializeJson(doc, json);
    Serial.println("SENSOR/DOMAIN/MODEL_2 " + json);
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

ISensor initilizeSensor(String filename, ISensor sensor)
{
    String json;
    StaticJsonDocument<50> doc;
    json = readSD(filename);
    DeserializationError err = deserializeJson(doc, json);
    if (err)
    {
        return sensor;
    }
    sensor.max = doc["max"].as<double>();
    sensor.min = doc["min"].as<double>();
    sensor.name = doc["name"].as<String>();
    Serial.println("SENSOR/DOMAIN/INITSENSOR " + json);
    return sensor;
}

/**
	 * Sensor/use-case: Iniciar el bus de datos
	 */
void initSensors() //ISensor sensors[]
{
    sensorTemp.begin();
    GLOBAL_TEMP.nane = "temperature";
    GLOBAL_PH.name = "ph";
    GLOBAL_DO.name = "do";
    GLOBAL_TEMP = initilizeSensor("/config/sensor/temp.json", GLOBAL_TEMP);
    GLOBAL_PH = initilizeSensor("/config/sensor/ph.json", GLOBAL_PH);
    GLOBAL_DO = initilizeSensor("/config/sensor/do.json", GLOBAL_DO);
}
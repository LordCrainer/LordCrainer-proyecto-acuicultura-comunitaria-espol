/**
	 * Sensor/domain: Modela la estructura ISensor para serializar en un json
     * @param data  Estructura ISensor
	 */
String sensorModel(ISensor data)
{
    String json;
    StaticJsonDocument<100> doc;
    // JsonObject obj = doc.as<JsonObject>();
    doc["value"] = data.value;
    doc["name"] = data.name;
    doc["alert"] = data.alert;
    Serial.println("SENSOR/DOMAIN/MODEL_1 " + data.name);
    Serial.println("SENSOR/DOMAIN/MODEL_1 " + data.alert);
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
    json = readSD(filename);
    StaticJsonDocument<100> doc;
    DeserializationError err = deserializeJson(doc, json);
    if (err)
    {
        Serial.println("Sensor/Domain/initSensor: ERROR=>" + String(err.c_str()));
        return sensor;
    }
    sensor.max = doc["max"].as<double>();
    sensor.min = doc["min"].as<double>();
    sensor.name = doc["name"].as<String>();
    S return sensor;
}

/**
	 * Sensor/use-case: Iniciar el bus de datos
	 */
void initSensors() //ISensor sensors[]
{
    sensorTemp.begin();
    GLOBAL_TEMP.name = "temperature";
    GLOBAL_TEMP.max = 36;
    GLOBAL_TEMP.min = 31;
    GLOBAL_PH.name = "ph";
    GLOBAL_TEMP.max = 8.52;
    GLOBAL_TEMP.min = 6.52;
    GLOBAL_DO.name = "do";
    GLOBAL_TEMP.max = 150;
    GLOBAL_TEMP.min = 120;
    GLOBAL_TEMP = initilizeSensor("/config/sensor/temp.json", GLOBAL_TEMP);
    GLOBAL_PH = initilizeSensor("/config/sensor/ph.json", GLOBAL_PH);
    GLOBAL_DO = initilizeSensor("/config/sensor/do.json", GLOBAL_DO);
}
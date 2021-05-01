/**
	 * Sensor/domain/sensors: Obtiene los datos del sensor de Oxígeno disuelto
	 */
ISensor getDOxygen(ISensor sensor)
{
    uint8_t temp = (uint8_t)GLOBAL_TEMP.value;
    uint16_t oxyD = analogRead(D_OXY_PIN);
    uint32_t volt = uint32_t(VOLT_REF) * oxyD / ADC_RES;
    sensor.value = float(ajustDO(volt, temp) / 1000);
    sensor.alert = sensorStatus(sensor);
    return sensor;
}

/**
	 * Sensor/domain/sensors: Obtiene todos los datos del sensor PH
     * @param ph 
	 */
ISensor getPh(ISensor sensor, byte iteration = 20)
{
    sensor.value = getValuePH(PH_PIN, iteration);
    sensor.alert = sensorStatus(sensor);
    return sensor;
}

/**
	 * Sensor/domain/sensors: Obtiene todos los datos del sensor  temperatura
	 */
ISensor getTemp(ISensor sensor)
{
    sensor.value = getValueTemp();
    sensor.alert = sensorStatus(sensor);
    return sensor;
}

ISensor execOneSensor(ISensor sensor)
{
    sensor.name.toLowerCase();

    if (sensor.name.startsWith("ph"))
    {
        return getPh(GLOBAL_PH);
    }
    if (sensor.name.startsWith("do"))
    {
        return GLOBAL_DO; // getDOxygen(GLOBAL_DO)
    }
    if (sensor.name.startsWith("temperature"))
    {
        return GLOBAL_TEMP;
    }
    sensor.alert = "Unknown";
    return sensor;
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
    return sensor;
}

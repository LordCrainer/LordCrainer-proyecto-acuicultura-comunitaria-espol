String sensorStatus(ISensor param)
{
    String letter = param.name.substring(0, 1);
    if (param.value > param.max)
    {
        return "SL" + letter;
    }
    if (param.value < param.min)
    {
        return "BL" + letter;
    }
    return "OK";
}

/**
	 * Sensor/domain/sensors: Obtiene los datos del sensor de Oxígeno disuelto
	 */
ISensor getDOxygen(ISensor DO)
{
    uint8_t temp = (uint8_t)GLOBAL_TEMP.value;
    uint16_t oxyD = analogRead(D_OXY_PIN);
    uint32_t volt = uint32_t(VOLT_REF) * oxyD / ADC_RES;
    DO.value = float(ajustDO(volt, temp) / 1000);
    DO.alert = sensorStatus(DO);
    return DO;
}

/**
	 * Sensor/domain/sensors: Obtiene todos los datos del sensor PH
     * @param ph 
	 */
ISensor getPh(ISensor ph, byte iteration = 20)
{
    ph.value = getValuePH(PH_PIN, iteration);
    ph.alert = sensorStatus(ph);
    return ph;
}

/**
	 * Sensor/domain/sensors: Obtiene todos los datos del sensor  temperatura
	 */
ISensor getTemp(ISensor temp)
{
    temp.value = getValueTemp();
    temp.alert = sensorStatus(temp);
    return temp;
}

ISensor execOneSensor(ISensor sensor)
{
    sensor.name.toLowerCase();
    if (name.startsWith("ph"))
    {
        return getPh(GLOBAL_PH);
    }
    if (name.startsWith("do"))
    {
        return GLOBAL_DO; // getDOxygen(GLOBAL_DO)
    }
    if (name.startsWith("temp"))
    {
        return GLOBAL_TEMP;
    }
    sensor.alert = "Unknown";
    return sensor;
}
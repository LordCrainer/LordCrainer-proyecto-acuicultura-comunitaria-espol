// *************** TEMPERATURE ***************
double getValueTemp()
{
    sensorTemp.requestTemperatures();
    return sensorTemp.getTempCByIndex(0);
}

/**
	 * Sensor/use-case: Obtiene el valor de temperatura
	 */
ISensor getTemp(ISensor temp)
{
    temp.value = getValueTemp();
    temp.alert = sensorStatus(temp);
    return temp;
}
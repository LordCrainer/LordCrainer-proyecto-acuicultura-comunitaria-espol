/**
	 * Sensor/domain/sensors: Obtiene el valor de temperatura
	 */
double getValueTemp()
{
    sensorTemp.requestTemperatures();
    return sensorTemp.getTempCByIndex(0);
}

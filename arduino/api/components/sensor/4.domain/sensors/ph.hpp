/**
	 * Sensor/domain/sensors: Obtiene el valor de PH
     * @param pin pin analog
     * @param iteration Número de mediciones para obtener un promedio
	 */
double getValuePH(const uint8_t pin, byte iteration)
{
    int ph = 0;
    double prom = 0;
    for (int i = 0; i < iteration; i++)
    {
        ph = analogRead(pin);
        prom = prom + ph;
    }
    prom = prom / iteration;
    return (7 + ((prom - 605) * 3 / (-18))) / 10;
}

/**
	 * Sensor/use-case: Obtiene los datos generales del sensor PH
     * @param ph 
	 */
ISensor getPh(ISensor ph, byte iteration = 20)
{
    ph.value = getValuePH(PH_PIN, iteration);
    ph.alert = sensorStatus(ph);
    return ph;
}
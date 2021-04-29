/**
 * Measurement/use-case:    Inicia sólo un proceso de medición de todos los sensores
 * 
 * @param measurement  Interfaz de las mediciones
*/
String startOneMeasurement(IMeasurement measurement, ISensor sensors[])
{
    measurement.params = "[" + getSomeSensors(sensors) + "]";
    measurement.status = "OK";
    return measurementModel(measurement);
}

/**
 * Measurement/use-case: Inicia varios procesos de medición acorde al número establecido, de todos los sensores
 * @param med  Interfaz de las mediciones
 * @param numMed   Cantidad de mediciones a realizar 
*/
String startAllMeasurement(IMeasurement med, ISensor sensors[], const byte numMed = 10)
{
    String data;
    String json;
    const byte lastIndex = numMed - 1;
    if (numMed <= 0)
    {
        return "";
    }

    for (byte i = 0; i < numMed; i++)
    {
        data = startOneMeasurement(med, sensors);
        /*         if (i == lastIndex)
        {
            json = json + data;
            break;
        } */
        json = json + "," + data;
    }
    json.remove(0, 1);
    return json;
}
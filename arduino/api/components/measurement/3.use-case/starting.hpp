/**
 * Measurement/use-case:    Inicia sólo un proceso de medición de todos los sensores
 * 
 * @param time  Captura el tiempo
 * @param pool_id   Obtiene el número de la piscina a sensar 
*/
String startOneMeasurement(String time, byte pool_id)
{
    IMeasurement measurement;
    measurement.device_id = "ABCD"; // getDeviceID
    measurement.created_at = time;
    measurement.pool_id = pool_id;
    measurement.params = "[" + getAllSensor() + "]";
    measurement.status = "OK";
    return measurementModel(measurement);
}

/**
 * Measurement/use-case: Inicia varios procesos de medición acorde al número establecido, de todos los sensores
 * @param time  Captura el tiempo
 * @param pool_id   Obtiene el número de la piscina a sensar 
 * @param numMed   Cantidad de mediciones a realizar 
*/
String startAllMeasurement(String time, const byte pool_id, const byte numMed)
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
        data = startOneMeasurement(time, pool_id);
        if (i == lastIndex)
        {
            json = json + data;
            break;
        }
        json = data + "," + json;
    }

    return json;
}
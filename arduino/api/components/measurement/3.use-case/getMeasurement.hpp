// Obtiene toda la metadata de una medición general.
String getOneMeasurement(String time, byte pool_id)
{
    IMeasurement measurement;
    // getDeviceID
    measurement.device_id = "ABCD";
    measurement.created_at = time;
    measurement.pool_id = pool_id;
    measurement.params = getAllSensor();
    measurement.status = "OK";
    const String data = measurementModel(measurement);
    return data;
}

Sring getAllMeasurement(String time, byte pool_id, byte numMed)
{
    int capacity = 210 * iteration;
    DynamicJsonDocument doc(capacity);
    String data;
    String temp;
    byte lastIndex = numMed - 1;
    for (byte i = 0; i < numMed; i++)
    {
        data = getOneMeasurement(time, pool_id);
        data.replace("\\", "");
        if (i == lastIndex)
        {
            temp = temp + data;
            break;
        }
        temp = data + "," + temp;
        // Serial.println("[" + data + "]");
        // arr[i] = "value";
        params.add(data);
    }
}
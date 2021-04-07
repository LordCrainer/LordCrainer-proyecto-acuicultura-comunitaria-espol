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
    return measurementModel(measurement);
    ;
}

String getAllMeasurement(String time, byte pool_id, const byte numMed)
{
    int capacity = 210 * numMed;
    String data;
    String json;
    const byte lastIndex = numMed - 1;
    for (byte i = 0; i < numMed; i++)
    {
        data = getOneMeasurement(time, pool_id);
        data.replace("\\", "");
        if (i == lastIndex)
        {
            json = json + data;
            break;
        }
        json = data + "," + json;
    }
    json = "[" + json + "]";
    json = serializedToArray(json, capacity);
    Serial.println(json);
    return json;
}
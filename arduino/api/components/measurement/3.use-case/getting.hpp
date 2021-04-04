// Obtiene toda la metadata de una medición general.
String getAllMeasurement(String time, byte pool_id)
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
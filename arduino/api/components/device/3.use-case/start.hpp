// Device/ue-case: Inicia el proceso de medición y guardado de los datos
// Args:
// AsyncWebServerRequest *request: Petición realizada por el cliente
String startDevice(AsyncWebServerRequest *request)
{
    IMeasurement med;
    // PARAMS
    med.created_at = getParameterByName(request, "time");
    med.pool_id = getParameterByName(request, "pool_id").toInt();
    byte iteration = getParameterByName(request, "iteration").toInt();
    //VALIDATION
    String time = String(getTime().unixtime());
    med.created_at = med.created_at == "" ? time : med.created_at;
    med.pool_id = med.pool_id == 0 ? 1 : med.pool_id;
    iteration = iteration == 0 ? 10 : iteration;
    // INICIALIZACIÓN
    med.device_id = "ABCD"; //getDeviceID();
    // ACTIONS
    String data = "[" + startAllMeasurement(med, iteration) + "]";
    String filename = setFilename("P", med.pool_id, med.created_at, "json");
    const boolean isCreated = createSD(filename, data);
    return data;
}

// Device/ue-case: Inicia el proceso de medición y guardado de los datos
// Args:
// AsyncWebServerRequest *request: Petición realizada por el cliente
String startDevice(AsyncWebServerRequest *request)
{
    IMeasurement measure;
    // PARAMS
    String timeParam = getParameterByName(request, "time");
    byte id = getParameterByName(request, "pool_id").toInt();
    byte iteration = getParameterByName(request, "iteration").toInt();

    // PRE ACTIONS
    String time = String(getTime().unixtime());
    measure.device_id = "ABCD"; //getDeviceID();

    //VALIDATION
    measure.created_at = timeParam == "" ? time : timeParam;
    measure.pool_id = id == 0 ? 1 : id;
    iteration = iteration == 0 ? 10 : iteration;

    // INICIALIZACIÓN
    ISensor sensors[] = {GLOBAL_TEMP, GLOBAL_PH, GLOBAL_DO};
    // ACTIONS
    String data = "[" + startAllMeasurement(measure, sensors, iteration) + "]";
    String filename = setFilename("P", measure.pool_id, measure.created_at, "json");
    const boolean isCreated = createSD(filename, data);
    return data;
}

// Device/ue-case: Inicia el proceso de medición y guardado de los datos
// Args:
// AsyncWebServerRequest *request: Petición realizada por el cliente
String startDevice(AsyncWebServerRequest *request)
{
    IMeasurement measure;
    // PARAMS
    String timeParam = getParameterByName(request, "time");
    byte id = getParameterByName(request, "pool_id").toInt();
    byte nMeditions = getParameterByName(request, "nMeditions").toInt();

    // PRE ACTIONS
    String time = getTimeUnix();
    measure.device_id = "ABCD"; //getDeviceID();

    //VALIDATION
    measure.created_at = timeParam == "" ? time : timeParam;
    measure.pool_id = id == 0 ? 1 : id;
    nMeditions = nMeditions == 0 ? 10 : nMeditions;

    // INICIALIZACIÓN
    GLOBAL_DO.value = 21;
    GLOBAL_DO.name = "DO";
    ISensor sensors[] = {GLOBAL_TEMP, GLOBAL_PH, GLOBAL_DO};
    // ACTIONS
    String data = "[" + startAllMeasurement(measure, sensors, nMeditions) + "]";
    String filename = setFilename("P", measure.pool_id, measure.created_at, "json");
    String destiny = "/data/" + filename;
    const boolean isCreated = createSD(destiny, data);
    return data;
}

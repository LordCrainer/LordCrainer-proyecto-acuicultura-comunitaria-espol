// Inicia el proceso de medición y guardado de los datos
String startDevice(AsyncWebServerRequest *request)
{
    // DECLARATION VARIABLE
    byte iteration = 10;
    byte pool_id = 1;
    String time = "1517383146999";
    // PARAMS
    time = getParameterByName(request, "time");
    iteration = getParameterByName(request, "iteration").toInt();
    pool_id = getParameterByName(request, "pool_id").toInt();
    // ACTIONS
    String data = startAllMeasurement(time, pool_id, iteration);
    String filename = setFilename("P", pool_id, time, "json");
    const boolean isCreated = createSD(filename, data);
    return data;
}

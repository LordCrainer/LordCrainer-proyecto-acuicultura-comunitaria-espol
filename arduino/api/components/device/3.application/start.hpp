// Device: Inicia el proceso de medición y guardado de los datos
String startDevice(AsyncWebServerRequest *request)
{
    // PARAMS
    byte pool_id = getParameterByName(request, "pool_id").toInt();
    byte iteration = getParameterByName(request, "iteration").toInt();
    String time = getParameterByName(request, "time");
    //VALIDATION
    time = time == "" ? String(getTime().unixtime()) : time;
    pool_id = pool_id == 0 ? 1 : pool_id;
    iteration = iteration == 0 ? 10 : iteration;
    Serial.println("START DEVICE - ITERATION: " + String(iteration));
    // ACTIONS
    String data = "[" + startAllMeasurement(time, pool_id, iteration) + "]";
    String filename = setFilename("P", pool_id, time, "json");
    const boolean isCreated = createSD(filename, data);
    return data;
}

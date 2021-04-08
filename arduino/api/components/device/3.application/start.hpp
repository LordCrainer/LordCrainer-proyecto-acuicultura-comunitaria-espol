// Inicia el proceso de medición y guardado de los datos
String startDevice(AsyncWebServerRequest *request)
{
    const char *time = "1517383146498"; //getTime();
    byte iteration = getParameterByName(request, "iteration").toInt();
    byte pool_id = getParameterByName(request, "pool_id").toInt() | 10;
    String data = startAllMeasurement(time, pool_id, iteration);
    // String data = startOneMeasurement(time, pool_id);
    String filename = setFilename("P", pool_id, time, "json"); // P1_1517383146498.json
    const byte existFile = 1;
    if (existFile == 1)
    {
        // const isDeleted = deleteFileSD(filename);
    }
    const byte isCreated = createSD(filename);
    const byte isWritten = writeSD(filename, data);

    // String readedData = readSD("measurement.txt");
    return data;
}

// Inicia el proceso de medición y guardado de los datos
String startMeasurement()
{
    String time = "1517383146498"; //getTime();
    byte numMeasu = 100;
    byte pool_id = 1;
    // String data = repeatFunction(getAllMeasurement, 10, time, pool_id);
    String data = getAllMeasurement(time, pool_id);
    String filename = setFilename("P", pool_id, time, "json"); // P1_1517383146498.json
    const byte existFile = 1;
    if (existFile == 1)
    {
        // const isDeleted = deleteFileSD(filename);
    }
    const byte isCreated = createSD(filename);
    const byte isWritten = writeSD(filename, data);

    // String readedData = readSD("measurement.txt");
    return "OK";
}

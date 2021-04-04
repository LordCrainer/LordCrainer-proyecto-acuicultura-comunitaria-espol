// Captura los datos de todos los sensores
String getAllSensor()
{
    IParams temp;
    IParams ph;
    temp.name = "Temperature";
    temp.value = 10.0;
    // // getPh();
    ph.value = 7.0;
    ph.name = "PH";
    return modelAllSensor(temp, ph);
}

// Inicia el proceso de medición y guardado de los datos
String startDevice()
{
    String time = "1517383146498"; //getTime();
    byte numMeasu = 100;

    String data = getAllMeasurement(time, 1);
    String filename = setFilename("P", measurement.pool_id, time, "json"); // P1_1517383146498.json
    const byte existFile = 1;
    if (existFile == 1)
    {
        // const isDeleted = deleteFileSD(filename);
    }
    const byte isCreated = createSD(filename);
    const byte isWritten = writeSD(filename, data);

    String readedData = readSD("measurement.txt");
    return String(measurement.status);
}

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

String startDevice()
{
    String time = "1517383146498";
    IMeasurement measurement;
    measurement.device_id = "ABCD";
    measurement.created_at = time;
    measurement.status = "OK";
    measurement.pool_id = 1;
    // Leer los datos de los sensores
    measurement.params = getAllSensor();
    const String data = measurementModel(measurement);
    String filename = setFilename("P", measurement.pool_id, time, "json"); // P1_1517383146498.json

    // Verificar si existe un archivo parecido
    // const existFile = verifyFile(filename);
    const byte existFile = 1;
    //// Si existe, eliminar el anterior y crear una nuevo
    if (existFile == 1)
    {
        // const isDeleted = deleteFileSD(filename);
    }
    // Crear el archivo P1_2021-03-01-13-01
    const byte isCreated = createSD(filename);
    // Añadir el nombre al archivo de registro

    // JsonDocument arr = JsonArray<String>;
    // arr.add();
    // Almacenarlos en una variable
    // Guardar en el archivo creado
    String readedData = readSD("measurement.txt");
    return readedData;
}

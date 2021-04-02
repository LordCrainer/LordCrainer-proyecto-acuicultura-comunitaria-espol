String startDevice()
{
    // Obtener el dato de la piscina a medir pool_id
    String pool = "1";
    // Capturar el tiempo actual: 2021-03-01-13-01
    String time = "20210301-1301";
    String filename = "P" + pool + "_" + time + ".json"; // P1_20210301-1301.json
    // Leer los datos de los sensores
    // const byte temp = getTemp();
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
    String data = readSD("measurement.txt");
    return data;
}

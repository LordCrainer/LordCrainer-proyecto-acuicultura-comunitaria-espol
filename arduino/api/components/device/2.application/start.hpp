String startDevice()
{
    // Obtener el dato de la piscina a medir
    String pool = "p1";
    // Capturar el tiempo actual: 2021-03-01-13-01
    String time = "20210301-1301";
    String filename = pool + time;
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

    // Leer los datos de los sensores
    // JsonDocument arr = JsonArray<String>;
    // arr.add();
    // Almacenarlos en una variable
    // Guardar en el archivo creado
    String data = readSD("measurement.txt");
    return data;
}

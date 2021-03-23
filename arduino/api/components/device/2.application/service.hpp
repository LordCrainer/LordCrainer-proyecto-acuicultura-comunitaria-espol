#include "../3.domain/example.hpp" //Este módulo se puede borrar
String getAllConfig()
{
    String configuration = readSD("configuration.txt");
    configuration = configurationModel();
    return configuration;
}

String startDevice()
{
    // Capturar el tiempo actual
    // Verificar si existe un archivo parecido
    // Crear el archivo P1_Fecha
    // Añadir el nombre el archivo de registro
    // 
    String data = readSD("measurement.txt");
    return data;
}

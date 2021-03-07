#include "../3.domain/example.hpp" //Este módulo se puede borrar
String getAllConfig()
{
    String configuration = readSD("configuration.txt");
    configuration = configurationModel();
    return configuration;
}

String startDevice()
{
    //
    String data = readSD("measurement.txt");
    return data;
}

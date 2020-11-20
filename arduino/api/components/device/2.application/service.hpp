#include "../3.domain/example.hpp" //Este módulo se puede borrar

String getAllConfig()
{
    String configuration = readDataFromSD("configuration.txt");
    configuration = configurationModel();
    return configuration;
}

String startDevice()
{
    //
    String data = readDataFromSD("measurement.txt");
    return data;
}
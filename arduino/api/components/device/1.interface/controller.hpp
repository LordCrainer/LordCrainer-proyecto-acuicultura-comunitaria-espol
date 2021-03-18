#include "../2.application/service.hpp"

void allConfiguration(AsyncWebServerRequest *request)
{
  String data = getAllConfig();
  request->send(200, "application/json", data);
}

void startMeasurement(AsyncWebServerRequest *request)
{
  // Capturar el tiempo actual
  // Verificar si existe un archivo parecido
  // Crear el archivo
  // 
  String response = startDevice();
  request->send(200, "application/json", response);
}

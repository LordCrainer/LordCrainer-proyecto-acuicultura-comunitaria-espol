#include "../3.use-case/index.hpp"

// Device/adapter: Obteniendo toda la configuración del sistema
void getAllConfig(AsyncWebServerRequest *req)
{
  String RESPONSE_END = allConfig("configuration.json");
  req->send(200, "application/json", RESPONSE_END);
}

// Device/adapter: Iniciando proceso de medición y captura de datos.
void startingDevice(AsyncWebServerRequest *req)
{
  String res;
  res = startDevice(req);
  req->send(200, "application/json", res);
}

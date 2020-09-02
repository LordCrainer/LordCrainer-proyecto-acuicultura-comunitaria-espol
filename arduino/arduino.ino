// #include <ESP8266WiFi.h>
// #include <ESPAsyncWebServer.h>
// #include <FS.h>

#include "api/utils/json.utils.hpp"

#include "env.h"
// #include "configuration/wifi-config.h"  // Sustituir con datos de vuestra red
// #include "configuration/Server.hpp"

String data;
void setup()
{
  Serial.begin(115200);
  Serial.print("Serialize: ");
  data = objectToJsonDynamic("Nombre", "Carlos");
  Serial.println(data);
  data = JsonToTextDynamic(data);
  Serial.print("Deserialize: ");
  Serial.println(data);
  Serial.println(data["Nombre"]);

  //ConnectWiFi_AP();

  //InitServer();
}

void loop()
{
}

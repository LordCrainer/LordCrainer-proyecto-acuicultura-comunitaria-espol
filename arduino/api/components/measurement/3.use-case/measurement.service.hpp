#include "../4.domain/measurement.interface.hpp"

String getMeasurementById(AsyncWebServerRequest *request, String path)
{
  int id = GetIdFromURL(request, path);
  String data = readDataFromSD("nameFile.txt");
  String filteredData = findById(data, id);
  return filteredData;
}



String getMeasurementtAll(AsyncWebServerRequest *request)
{
  String data = readDataFromSD("nameFile.txt");
  return data;
}

String getFiltered(AsyncWebServerRequest *request)
{
  String data = readDataFromSD("nameFile.txt");
  return data;
}

String measurementData()
{
  String output;
  IMeasurement measurement;
  StaticJsonDocument<384> root;

  root["pool_id"] = "1";
  root["device_id"] = "aa";

  JsonArray params = root.createNestedArray("params");

  JsonObject params_0 = params.createNestedObject();
  params_0["name"] = "Temp";
  params_0["value"] = 100;
  params_0["alert"] = "OK";

  JsonObject params_1 = params.createNestedObject();
  params_1["name"] = "OX";
  params_1["value"] = 100;
  params_1["alert"] = "OK";

  JsonObject params_2 = params.createNestedObject();
  params_2["name"] = "ph";
  params_2["value"] = 100;
  params_2["alert"] = "OK";
  root["created_at"] = 1595477800181;

  serializeJson(root, output);
  return output;
}
#include "../4.domain/index.hpp"

String getAllMeasurementt(AsyncWebServerRequest *request)
{
  String data = readSD("filename.txt");
  return data;
}
String getOneMeasurement(AsyncWebServerRequest *request, String path)
{
  int id = GetIdFromURL(request, path); // 1
  String data = readSD("data_p1_20210312_0432.json");
  if (data == "NO")
  {
    return "";
  }
  String filteredData = findById(data, id);
  return filteredData;
}

String getFiltered(AsyncWebServerRequest *request)
{
  String data = readSD("filename.txt");
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
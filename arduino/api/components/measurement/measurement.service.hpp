#include "./measurement.model.hpp"

int GetIdFromURL(AsyncWebServerRequest *request, String root)
{
  String string_id = request->url(); // /measurement/1
  string_id.replace(root, "");       // "1"
  int id = string_id.toInt();        //  1
  return id;
}

String getMeasurementById(AsyncWebServerRequest *request, String path)
{
  int id = GetIdFromURL(request, path);
  String data = readDataFromSD("filename.txt");
  String filteredData = findById(data, id);
  return filteredData;
}

String GetBodyContent(uint8_t *data, size_t len)
{
  String content = "";
  for (size_t i = 0; i < len; i++)
  {
    content.concat((char)data[i]);
  }
  return content;
}

String getMeasurementtAll(AsyncWebServerRequest *request)
{
  String data = readDataFromSD("filename.txt");
  return data;
}

String getFiltered(AsyncWebServerRequest *request)
{
  String data = readDataFromSD("filename.txt");
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
#include "../4.domain/model-measurement.hpp"

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

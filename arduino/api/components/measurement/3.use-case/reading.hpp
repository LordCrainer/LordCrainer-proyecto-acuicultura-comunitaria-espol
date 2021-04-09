#include "../4.domain/model-measurement.hpp"

String readOneMeasurement(AsyncWebServerRequest *request, String path)
{
  int pool_id = getIdFromURL(request, path); // 1
  // Recoger todos lo sarchivos que comiencen con P1
  findFileByName("/", "P1");
  String data = readSD("P30_1517383146498.json");
  // String filteredData = findById(data, pool_id);
  return data;
}
String readAllMeasurement(AsyncWebServerRequest *request)
{
  String data = readSD("filename.txt");
  return data;
}

String getFiltered(AsyncWebServerRequest *request)
{
  String data = readSD("filename.txt");
  return data;
}

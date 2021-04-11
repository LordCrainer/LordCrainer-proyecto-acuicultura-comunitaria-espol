#include "../4.domain/model-measurement.hpp"

String readOneMeasurement(AsyncWebServerRequest *request, String path)
{
  int pool_id = getIdFromURL(request, path);
  String prefix = "P" + String(pool_id) + "_";
  String list = findFileByName("/", prefix);
  String data = "[" + readManyFiles(list, ",", 10) + "]";
  return data;
}

String readAllMeasurement(AsyncWebServerRequest *request)
{
  String prefix = "P";
  String list = findFileByName("/", prefix);
  String data = "[" + readManyFiles(list, ",", 10) + "]";
  return data;
}

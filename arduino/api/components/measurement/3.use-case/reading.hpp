#include "../4.domain/model-measurement.hpp"

// Measurement/
//  Lee únicamente los archivos de la piscina seleccionada y que coincida con un prefijo: "P1_" o "P10_"
// Limitado a 10 archivos.
String readOneMeasurement(AsyncWebServerRequest *request, String path)
{
  int pool_id = getIdFromURL(request, path);
  String prefix = "P" + String(pool_id) + "_";
  String list = findFileByName("/", prefix);
  String data = "[" + readManyFiles(list, ",", 10) + "]";
  return data;
}

// Measurement: Lee todos los archivos que tenga el prefijo "P".
// Limitado a 10 archivos.
String readAllMeasurement(AsyncWebServerRequest *request)
{
  String prefix = "P";
  String list = findFileByName("/", prefix);
  String data = "[" + readManyFiles(list, ",", 10) + "]";
  return data;
}

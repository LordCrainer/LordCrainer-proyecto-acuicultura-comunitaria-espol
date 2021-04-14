#include "../4.domain/model-measurement.hpp"

// Measurement/
//  Lee únicamente los archivos de la piscina seleccionada y que coincida con un prefijo: "P1_" o "P10_"
// Limitado a 10 archivos.
String readOneMeasurement(AsyncWebServerRequest *req, String route)
{
  // PARAMS
  byte filemax = getParameterByName(req, "filemax").toInt();
  String prefix = getParameterByName(req, "prefix");
  String path = getParameterByName(req, "path");
  byte pool_id = getIdFromURL(req, route);
  // VALIDATION
  pool_id = pool_id < 0 ? 1 : pool_id;
  filemax = filemax == 0 ? 10 : filemax;
  prefix = prefix == "" ? "P" + String(pool_id) + "_" : prefix;
  path = path == "" ? "/" : path;
  // ACTIONS
  Serial.println("PREFIX: " + prefix);
  String list = findFileByName(path, prefix);
  String data = "[" + execManyFiles(readSD, list, ",", filemax) + "]";
  return data;
}

// Measurement: Lee todos los archivos que tenga el prefijo "P".
// Limitado a 10 archivos.
String readAllMeasurement(AsyncWebServerRequest *req)
{
  // PARAMS
  byte filemax = getParameterByName(req, "filemax").toInt();
  String prefix = getParameterByName(req, "prefix");
  // VALIDATION
  filemax = filemax == 0 ? 10 : filemax;
  prefix = prefix == "" ? "P" : prefix;
  // ACTIONS
  String list = findFileByName("/", prefix);
  String data = "[" + execManyFiles(readSD, list, ",", filemax) + "]";
  return data;
}

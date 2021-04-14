#include "../4.domain/model-measurement.hpp"

/**
 * Measurement/use-case: Lee unicamente los archivos que coincidad con un prefijo. Ejemplo: P1_, P2_
 * 
 * @param req  Peitición del cliente
 * @param route   Ruta de la llamada
*/
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
  String list = findFileByName(path, prefix, filemax);
  String data = "[" + execManyFiles(readSD, list, ",", filemax) + "]";
  return data;
}

/**
 * Measurement/use-case: Lee todos los archivos que coincidan con un prefijo
 * 
 * @param req  Peitición del cliente
*/
String readAllMeasurement(AsyncWebServerRequest *req)
{
  // PARAMS
  byte filemax = getParameterByName(req, "filemax").toInt();
  String prefix = getParameterByName(req, "prefix");
  // VALIDATION
  filemax = filemax == 0 ? 10 : filemax;
  prefix = prefix == "" ? "P" : prefix;
  // ACTIONS
  String list = findFileByName("/", prefix, filemax);
  String data = "[" + execManyFiles(readSD, list, ",", filemax) + "]";
  return data;
}

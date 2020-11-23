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
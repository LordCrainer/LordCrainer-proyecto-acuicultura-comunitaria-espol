int GetIdFromURL(AsyncWebServerRequest *request, String root)
{
  String string_id = request->url(); // /measurement/1
  string_id.replace(root, "");       // "1"
  int id = string_id.toInt();        //  1
  return id;
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

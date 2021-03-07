struct Config
{
  int pool = 1;
  int temp = 30;
  int oxi = 1000;
  int ph = 5;
  bool alertaTemp = true;
  bool alertaOxi = true;
  bool alertaPh = false;
  String cadena = "";
};
Config config;

byte writeSD(String nameFile, String data)
{
  File file;
  file = SD.open(nameFile, FILE_WRITE);
  if (file)
  {
    file.print(data);
    file.close();
    return 1;
  }
  return 0;
}

String readSD(String nameFile)
{
  File file;
  String data;
  char readedCharacter;
  file = SD.open(nameFile, FILE_READ); //abrimos  el archivo
  if (file)
  {
    while (file.available())
    {
      readedCharacter = file.read();
      data += readedCharacter;
    }
    file.close(); //cerramos el archivo
  }
  else
  {
    Serial.println("Error al abrir el archivo");
  }
  return data;
}

String readDataFromSD(String nameFile)
{
  String json;
  const size_t capacity = 4 * JSON_ARRAY_SIZE(3) + 9 * JSON_OBJECT_SIZE(3) + 3 * JSON_OBJECT_SIZE(4);
  DynamicJsonDocument doc(capacity);

  JsonObject doc_0 = doc.createNestedObject();
  doc_0["pool_id"] = 1;
  doc_0["device_id"] = "PC001";

  JsonArray doc_0_params = doc_0.createNestedArray("params");

  JsonObject doc_0_params_0 = doc_0_params.createNestedObject();
  doc_0_params_0["name"] = "temparature";
  doc_0_params_0["value"] = 25.43;
  doc_0_params_0["alert"] = "OK";

  JsonObject doc_0_params_1 = doc_0_params.createNestedObject();
  doc_0_params_1["name"] = "oxygen";
  doc_0_params_1["value"] = 12.05;
  doc_0_params_1["alert"] = "OVER";

  JsonObject doc_0_params_2 = doc_0_params.createNestedObject();
  doc_0_params_2["name"] = "ph";
  doc_0_params_2["value"] = 6.5;
  doc_0_params_2["alert"] = "UNDER";
  doc_0["created_at"] = 1600362938050;

  JsonObject doc_1 = doc.createNestedObject();
  doc_1["pool_id"] = 2;
  doc_1["device_id"] = "PC001";

  JsonArray doc_1_params = doc_1.createNestedArray("params");

  JsonObject doc_1_params_0 = doc_1_params.createNestedObject();
  doc_1_params_0["name"] = "temparature";
  doc_1_params_0["value"] = 25.45;
  doc_1_params_0["alert"] = "OK";

  JsonObject doc_1_params_1 = doc_1_params.createNestedObject();
  doc_1_params_1["name"] = "oxygen";
  doc_1_params_1["value"] = 11.25;
  doc_1_params_1["alert"] = "OVER";

  JsonObject doc_1_params_2 = doc_1_params.createNestedObject();
  doc_1_params_2["name"] = "ph";
  doc_1_params_2["value"] = 6.52;
  doc_1_params_2["alert"] = "UNDER";
  doc_1["created_at"] = 1600362938917;

  JsonObject doc_2 = doc.createNestedObject();
  doc_2["pool_id"] = 1;
  doc_2["device_id"] = "PC001";

  JsonArray doc_2_params = doc_2.createNestedArray("params");

  JsonObject doc_2_params_0 = doc_2_params.createNestedObject();
  doc_2_params_0["name"] = "temparature";
  doc_2_params_0["value"] = 25.47;
  doc_2_params_0["alert"] = "OK";

  JsonObject doc_2_params_1 = doc_2_params.createNestedObject();
  doc_2_params_1["name"] = "oxygen";
  doc_2_params_1["value"] = 11.25;
  doc_2_params_1["alert"] = "OVER";

  JsonObject doc_2_params_2 = doc_2_params.createNestedObject();
  doc_2_params_2["name"] = "ph";
  doc_2_params_2["value"] = 6.52;
  doc_2_params_2["alert"] = "UNDER";
  doc_2["created_at"] = 1600362939773;

  serializeJson(doc, json);
  return json;
}

void printDirectory(File dir, int numTabs)
{
  while (true)
  {

    File entry = dir.openNextFile();
    if (!entry)
    {
      // no more files
      Serial.println("**nomorefiles**");
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++)
    {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory())
    {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    }
    else
    {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
  }
}
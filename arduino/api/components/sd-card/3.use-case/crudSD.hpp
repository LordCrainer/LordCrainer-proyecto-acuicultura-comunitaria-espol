boolean writeSD(String filename, String data)
{
  File file;
  file = SD.open(filename, FILE_WRITE);
  if (file)
  {
    file.print(data);
    file.close();
    return true;
  }
  return false;
}

boolean createSD(String filename, String data)
{
  File file;
  const boolean existFile = SD.exists(filename);
  if (existFile)
  {
    return false;
  }
  file = SD.open(filename, FILE_WRITE);
  if (file)
  {
    file.print(data);
    file.close();
    return true;
  }
  return false;
}

String readSD(String filename)
{
  File file;
  String data;
  char readedCharacter;
  file = SD.open(filename, FILE_READ);
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
    return "";
  }
  return data;
}

boolean deleteSD(String filename)
{
  return SD.remove(filename);
}

// Encontrar archivos por el nombre
// path: Ruta
// prefix: Prefijo o caracteres iniciales
// numFile: Cantidad de archivos a buscar (default = 10)
String findFileByName(String path, String prefix, byte numFile = 10)
{
  File file = SD.open(path);
  String listFiles = "";
  byte index = 0;
  while (true)
  {
    File entry = file.openNextFile();
    String filename = String(entry.name());
    if (!entry)
    {
      Serial.println("**nomorefiles**");
      break;
    }
    if (numFile == index + 1)
    {
      listFiles = filename + listFiles;
      break;
    }
    if (filename.startsWith(prefix))
    {
      listFiles = filename + "," + listFiles;
      index++;
    }
  }
  // listFiles.remove(0, 1);
  return listFiles;
}

// Lee una cadena continua de datos separados por ","
String readManyFiles(String data, String separator = ",", int sizeMax = 10)
{
  const int lengthData = data.length();
  int position[sizeMax];
  int index = 0;
  String input;
  String output = "";
  if (lengthData <= 0)
  {
    return output;
  }
  // INICIO DEL BUCLE
  position[0] = 0;
  for (byte i = 0; i < sizeMax; i++)
  {
    position[i + 1] = data.indexOf(separator, index);
    if (position[i + 1] == -1)
    {
      break;
    }
    input = readSD(data.substring(index, position[i + 1]));
    if (input.startsWith("["))
    {
      input.remove(0, 1);
      input.remove(input.length() - 1, 1);
    }
    output = output + "," + input;
    index = position[i + 1] + 1;
  }
  output.remove(0, 1);
  return output;
}

// Obtiene e imprime todos los directorios, subdirectorios y archivos dentro del disposito de almacenamiento (SD CARD)
String printDirectory(File dir, int numTabs)
{
  String json = "";
  IDirectory folder;
  IFiles file;

  while (true)
  {
    File entry = dir.openNextFile();
    if (!entry)
    {
      Serial.println("**END DIR**");
      break;
    }

    /*     for (uint8_t i = 0; i < numTabs; i++)
    {
      // Serial.print('\t');
    } */
    // Serial.print(entry.name());
    if (entry.isDirectory())
    {
      Serial.println(entry.name());
      folder.name = entry.name();
      folder.type = 1;
      Serial.println("DIR: " + folder.name);
      folder.content = "[" + printDirectory(entry, numTabs + 1) + "]";
      json = json + "," + dirModel(folder);
      /*       JsonObject dir = data.createNestedObject();
      dir["name"] = entry.name();
      dir["type"] = 1;
      JsonArray content = dir.createNestedArray("content");
      content.add(printDirectory(entry, numTabs + 1)) */
      // Serial.println("/");
    }
    else
    {
      file.name = entry.name();
      file.size = entry.size();
      file.type = 0;
      Serial.println("\tFILE: \t" + file.name + "\t\t\t\t\tSize: " + ajustUnitSize(file.size));
      json = json + "," + fileModel(file);
      /*       JsonObject file = data.createNestedObject();
      file["name"] = entry.name();
      file["type"] = 0;
      file["size"] = entry.size();
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC); */
    }
  }
  json.remove(0, 1);
  return json;
}
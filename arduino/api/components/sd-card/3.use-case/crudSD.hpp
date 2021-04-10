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

void printDirectory(File dir, int numTabs)
{
  while (true)
  {
    File entry = dir.openNextFile();
    if (!entry)
    {
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
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
  }
}

boolean deleteSD(String filename)
{
  return SD.remove(filename);
}

// Encontrar archivos por el nombre
// path: Ruta
// prefix: Prefijo o caracteres iniciales
// numFile: Cantidad de archivos a buscar (default = 10)
String *findFileByName(String path, String prefix, byte numFile = 10)
{
  File file = SD.open(path);
  String listFiles[numFile];
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
    if (filename.startsWith(prefix))
    {
      listFiles[index] = filename;
      Serial.println(listFiles[index]);
      index++;
    }
    if (numFile == index + 1)
    {
      break;
    }
  }
  return listFiles;
}
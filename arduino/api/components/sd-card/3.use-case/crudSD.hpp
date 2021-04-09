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

void findFileByName(String path, String name)
{
  File file = SD.open(path);
  File entry = file.openNextFile();
  String filename = String(entry.name());
  while (true)
  {

    if (!entry)
    {
      Serial.println("**nomorefiles**");
      break;
    }
    Serial.print("COMPARANDO: ");
    Serial.println(filename.compareTo(name));
    Serial.print("START AT: ");
    Serial.println(filename.startsWith(name));
  }
}
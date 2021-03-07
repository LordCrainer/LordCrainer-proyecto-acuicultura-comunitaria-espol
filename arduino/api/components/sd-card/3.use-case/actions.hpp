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
  file = SD.open(nameFile, FILE_READ);
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
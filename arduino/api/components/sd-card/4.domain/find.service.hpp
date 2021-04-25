/**
 *  sd-card/use-case: Encuentra un archivo por las iniciales del nombre
 *  @param  path  Ruta a buscar
 *  @param  prefix  Prefijo del archivo a buscar
 *  @param  numFile  Cantidad de archivos a buscar (default=10)
 */
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

    if (filename.startsWith(prefix))
    {
      listFiles = filename + "," + listFiles;
      if (numFile == index + 1)
      {
        break;
      }
      index++;
    }
  }
  // listFiles.remove(0, 1);
  return listFiles;
}
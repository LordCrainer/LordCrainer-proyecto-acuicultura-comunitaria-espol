/**
 *  sd-card/use-case: Imprime y obtiene todos los archivos de un directorio
 *  @param  dir  Necesita de una clase File para ser ejecutado
 *  @param  numTabs  Número de tabulaciones por cada archivo dentro de un directorio
 */
String printDirectory(File dir, int numTabs = 0, byte filemax = 10)
{
  String json = "";
  IDirectory folder;
  IFiles file;
  byte iteration = 0;
  while (true)
  {
    File entry = dir.openNextFile();
    if (filemax < iteration)
    {
      Serial.println("**END DIR**");
      break;
    }

    if (!entry)
    {
      Serial.println("**END DIR**");
      break;
    }
    if (entry.isDirectory())
    {
      folder.name = entry.name();
      folder.type = 1;
      Serial.println("DIR: " + folder.name);
      folder.content = "[" + printDirectory(entry, numTabs + 1) + "]";
      json = json + "," + dirModel(folder);
    }
    else
    {
      file.name = entry.name();
      file.size = entry.size();
      file.type = 0;
      Serial.println("\tFILE: \t" + file.name + "\t\t\t\t\tSize: " + ajustUnitSize(file.size));
      json = json + "," + fileModel(file);
    }
    iteration++;
  }
  json.remove(0, 1);
  return json;
}
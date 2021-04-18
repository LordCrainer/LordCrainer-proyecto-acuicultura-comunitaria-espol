/**
 *  sd-card/use-case: Escribe en un archivo de la SD. Si no existe lo crea, si existe adjunta la información
 *  @param  filename  Nombre del archivo
 *  @param  data  Información a guardar
 */
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

/**
 *  sd-card/use-case: Crea un archivo nuevo, si existe sale de la función
 *  @param  filename  Nombre del archivo
 *  @param  data  Información a guardar
 */
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

/**
 *  sd-card/use-case: Lee la información de un archivo
 *  @param  filename  Nombre del archivo
 */
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

/**
 *  sd-card/use-case: Borra el archivo seleccionado
 *  @param  filename  Nombre del archivo
 */
String deleteSD(String filename)
{
  return SD.remove(filename) == 1 ? filename : "";
}

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

/**
 *  sd-card/use-case: Executa una función para toda una cadena continua de datos que se encuentre separados por algún caracter
 *  @param  sdFunc  Llamada de la función a ejecutar
 *  @param  list  Lista de valores
 *  @param  separator  Caracter usado para separar la cadena
 *  @param  filemax  Numero máximo de archivos a ejecutar
 */
String execManyFiles(callFunction sdFunc, String list, String separator = ",", int filemax = 10)
{
  const int lengthData = list.length();
  int position[filemax];
  int index = 0;
  String input;
  String output = "";
  if (lengthData <= 0)
  {
    return "{}";
  }
  // INICIO DEL BUCLE
  position[0] = 0;
  for (byte i = 0; i < filemax; i++)
  {
    position[i + 1] = list.indexOf(separator, index);
    if (position[i + 1] == -1) //Si al final no hay separador
    {
      /*       if (lengthData > 0) // Pero la cadena tiene información
      {
        return sdFunc(list);
      } */
      break;
    }
    input = sdFunc(list.substring(index, position[i + 1]));
    if (input.startsWith("["))
    {
      input.remove(0, 1);
      input.remove(input.length() - 1, 1);
    }
    output = output + "," + input;
    if (input == "")
    {
      output.remove(output.length() - 1, 1);
    }
    index = position[i + 1] + 1;
  }
  output.remove(0, 1);
  return output;
}

/**
 *  sd-card/use-case: Imprime y obtiene todos los archivos de un directorio
 *  @param  dir  Necesita de una clase File para ser ejecutado
 *  @param  numTabs  Número de tabulaciones por cada archivo dentro de un directorio
 */
String printDirectory(File dir, int numTabs, byte filemax = 10)
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
      break;

      if (!entry)
      {
        Serial.println("**END DIR**");
        break;
      }
      /*     for (uint8_t i = 0; i < numTabs; i++)
    {
      // Serial.print('\t');
    } */
      if (entry.isDirectory())
      {
        Serial.println(entry.name());
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
  }
  json.remove(0, 1);
  return json;
}
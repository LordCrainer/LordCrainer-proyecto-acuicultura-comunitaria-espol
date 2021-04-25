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

/**
 *  sd-card/use-case: Executa una función para toda una cadena continua de datos que se encuentre separados por algún caracter
 *  @param  sdFunc  Llamada de la función a ejecutar
 *  @param  list  Lista de valores
 *  @param  separator  Caracter usado para separar la cadena
 *  @param  filemax  Numero máximo de archivos a ejecutar
 *  @param  path  Ruta de los archivos (default: "/")
 */
String execManyFiles(callFunction sdFunc, String list, String separator = ",", int filemax = 10, String path = "/")
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
    input = sdFunc(path + list.substring(index, position[i + 1]));
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
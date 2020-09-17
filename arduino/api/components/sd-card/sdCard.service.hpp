#include <SD.h>

File myFile;
int pool = 1;
int temp = 30;
int oxi = 1000;
int ph = 5;
bool alertaTemp = true;
bool alertaOxi = true;
bool alertaPh = false;
// String cadena="";

void initSdCard()
{
  Serial.begin(9600);
  Wire.begin();
  Serial.print("Iniciando SD ...");
  if (!SD.begin(9))
  {
    Serial.println("No se pudo inicializar");
    return;
  }
  Serial.println("inicializacion exitosa");
}

void escribirSD()
{
  myFile = SD.open("datalog.txt", FILE_WRITE);
  if (myFile)
  {
    String json;
    DynamicJsonDocument doc(sizeDoc);
    doc["Pool_id"] = pool;
    doc["Pool_id"] = pool;
    doc["Pool_id"] = pool;
    doc["Parametros"]["Temperatura"] = pool;
    serializeJson(doc, json);
    println(json);
    Serial.println("Escribiendo en SD: ");
    myFile.println();
    doc[key] = value;
    myFile.print("{\"Pool_id\":");
    myFile.print(pool);
    myFile.print(", \"Parametros\":");
    myFile.print(" \"Temperatura\":");
    myFile.print("{\"valor\":");
    myFile.print(temp);
    myFile.print(", \"alerta\":");
    myFile.print(alertaTemp);
    myFile.print("}");
    myFile.print(", \"Oxigeno\":");
    myFile.print("{ \"valor\":");
    myFile.print(oxi);
    myFile.print(", \"alerta\":");
    myFile.print(alertaOxi);
    myFile.print("}");
    myFile.print(", \"Ph\":");
    myFile.print("{ \"valor\":");
    myFile.print(ph);
    myFile.print(", \"alerta\":");
    myFile.print(alertaPh);
    myFile.print("}");
    myFile.print("}");
    myFile.print("} ");

    myFile.close();
  }
}

String leerSD(String origin)
{
  File myFile;
  String cadena = "";
  myFile = SD.open(origin, FILE_READ); //abrimos  el archivo

  if (myFile)
  {
    bool line = false;
    myFile.seek(myFile.size() - 1); //Ubicacion en posicion anterior a ultimo caracter

    while (myFile.available())
    {
      if (line == false) //Primero leer en reversa para buscar salto de linea
      {
        char caracter = myFile.read();
        //Serial.println(caracter);
        myFile.seek(myFile.position() - 2);

        if (caracter == '\n') //Cuando encuentra salto de linea cambia estado
        {
          line = true;
        }
      }

      if (line == true) //Empieza a leer normalmente de izquierda a derecha
      {
        char caracter = myFile.read();
        //Serial.println(caracter);
        cadena = cadena + caracter;

        if (caracter == ']}') //La cadena termina en este caracter para formato JSON
        {
          break;
        }
      }
    }

    myFile.close(); //cerramos el archivo
    delay(300);
    return cadena
  }
  else
  {
    Serial.println("Error al abrir el archivo");
  }

  return ""
}

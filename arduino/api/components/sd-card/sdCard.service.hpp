#include <SD.h>

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

void initSD()
{
  Serial.begin(9600);
  Serial.print("Iniciando SD ...");
  if (!SD.begin(9))
  {
    Serial.println("No se pudo inicializar");
    return;
  }
  Serial.println("inicializacion exitosa");
}

void escribirSD(String nameFile)
{
  // Tratar de dinamizar las funciones usando argumentos
  // Evitar las variables con alcance global. Instanciar o declarar dentro de la función
  File myFile;
  Config measurement;
  myFile = SD.open(nameFile, FILE_WRITE);
  if (myFile)
  {
    Serial.println("Escribiendo en SD: ");
    myFile.println();
    myFile.print("{\"Pool_id\":");
    myFile.print(measurement.pool);
    myFile.print(", \"Parametros\":");
    myFile.print("{ \"Temperatura\":");
    myFile.print("{\"valor\":");
    myFile.print(measurement.temp);
    myFile.print(", \"alerta\":");
    myFile.print(measurement.alertaTemp);
    myFile.print("}");
    myFile.print(", \"Oxigeno\":");
    myFile.print("{ \"valor\":");
    myFile.print(measurement.oxi);
    myFile.print(", \"alerta\":");
    myFile.print(measurement.alertaOxi);
    myFile.print("}");
    myFile.print(", \"Ph\":");
    myFile.print("{ \"valor\":");
    myFile.print(measurement.ph);
    myFile.print(", \"alerta\":");
    myFile.print(measurement.alertaPh);
    myFile.print("}");
    myFile.print("}");
    myFile.print("} ");

    myFile.close();
  }
}

String leerSD(String nameFile)
{
  // Tratar de siempre retornar las funciones

  File myFile;
  String cadena;
  myFile = SD.open(nameFile, FILE_READ); //abrimos  el archivo

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

        if (caracter == "} ") //La cadena termina en este caracter para formato JSON
        {
          break;
        }
      }
    }

    myFile.close(); //cerramos el archivo
    delay(300);
  }
  else
  {
    Serial.println("Error al abrir el archivo");
  }
  return cadena;
  //cadena="";
}

void mostrar(String data)
{
  Config measurement;
  StaticJsonDocument<1024> doc;
  DeserializationError error = deserializeJson(doc, data);
  String Pool = doc["Pool_id"];
  String Parametros = doc["Parametros"];
  String Temperatura = doc["Parametros"]["Temperatura"]["valor"];
  String alertTemp = doc["Parametros"]["Temperatura"]["alerta"];
  String Oxigeno = doc["Parametros"]["Oxigeno"]["valor"];
  String alertOxi = doc["Parametros"]["Oxigeno"]["alerta"];
  String Ph = doc["Parametros"]["Ph"]["valor"];
  String alertPh = doc["Parametros"]["Ph"]["alerta"];

  Serial.println("*****************");
  Serial.println("datalog.txt: ");
  Serial.print("cadena Leida: ");
  Serial.print(data);
  Serial.println("");
  Serial.print("Pool_id: ");
  Serial.println(Pool);
  //Serial.print("Parametros: ");
  //Serial.println(Parametros);
  Serial.print("Temperatura:");
  Serial.println(Temperatura);
  Serial.print("Alerta de Temperatura:");
  Serial.println(alertTemp);
  Serial.print("Oxigeno:");
  Serial.println(Oxigeno);
  Serial.print("Alerta de Oxigeno:");
  Serial.println(alertOxi);
  Serial.print("Ph:");
  Serial.println(Ph);
  Serial.print("Alerta de Ph:");
  Serial.println(alertPh);
}
void createFileFromSD()
{
}

String readDataFromSD()
{
  String json;
  const size_t capacity = 4 * JSON_ARRAY_SIZE(3) + 9 * JSON_OBJECT_SIZE(3) + 3 * JSON_OBJECT_SIZE(4);
  DynamicJsonDocument doc(capacity);

  JsonObject doc_0 = doc.createNestedObject();
  doc_0["pool_id"] = 1;
  doc_0["device_id"] = "PC001";

  JsonArray doc_0_params = doc_0.createNestedArray("params");

  JsonObject doc_0_params_0 = doc_0_params.createNestedObject();
  doc_0_params_0["name"] = "temparature";
  doc_0_params_0["value"] = 25.43;
  doc_0_params_0["alert"] = "OK";

  JsonObject doc_0_params_1 = doc_0_params.createNestedObject();
  doc_0_params_1["name"] = "oxygen";
  doc_0_params_1["value"] = 12.05;
  doc_0_params_1["alert"] = "OVER";

  JsonObject doc_0_params_2 = doc_0_params.createNestedObject();
  doc_0_params_2["name"] = "ph";
  doc_0_params_2["value"] = 6.5;
  doc_0_params_2["alert"] = "UNDER";
  doc_0["created_at"] = 1600362938050;

  JsonObject doc_1 = doc.createNestedObject();
  doc_1["pool_id"] = 2;
  doc_1["device_id"] = "PC001";

  JsonArray doc_1_params = doc_1.createNestedArray("params");

  JsonObject doc_1_params_0 = doc_1_params.createNestedObject();
  doc_1_params_0["name"] = "temparature";
  doc_1_params_0["value"] = 25.45;
  doc_1_params_0["alert"] = "OK";

  JsonObject doc_1_params_1 = doc_1_params.createNestedObject();
  doc_1_params_1["name"] = "oxygen";
  doc_1_params_1["value"] = 11.25;
  doc_1_params_1["alert"] = "OVER";

  JsonObject doc_1_params_2 = doc_1_params.createNestedObject();
  doc_1_params_2["name"] = "ph";
  doc_1_params_2["value"] = 6.52;
  doc_1_params_2["alert"] = "UNDER";
  doc_1["created_at"] = 1600362938917;

  JsonObject doc_2 = doc.createNestedObject();
  doc_2["pool_id"] = 1;
  doc_2["device_id"] = "PC001";

  JsonArray doc_2_params = doc_2.createNestedArray("params");

  JsonObject doc_2_params_0 = doc_2_params.createNestedObject();
  doc_2_params_0["name"] = "temparature";
  doc_2_params_0["value"] = 25.47;
  doc_2_params_0["alert"] = "OK";

  JsonObject doc_2_params_1 = doc_2_params.createNestedObject();
  doc_2_params_1["name"] = "oxygen";
  doc_2_params_1["value"] = 11.25;
  doc_2_params_1["alert"] = "OVER";

  JsonObject doc_2_params_2 = doc_2_params.createNestedObject();
  doc_2_params_2["name"] = "ph";
  doc_2_params_2["value"] = 6.52;
  doc_2_params_2["alert"] = "UNDER";
  doc_2["created_at"] = 1600362939773;

  serializeJson(doc, json);
  return json;
}

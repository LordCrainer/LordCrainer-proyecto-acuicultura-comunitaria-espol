#include <SD.h>
#include<SPI.h>
int ss=4;
File Archivo;

//String json="{"sensor":"gps","time":1351824120,"data":[48.756080,2.302038]}";
String json2;
void setup() {
  StaticJsonDocument<200> doc;
  Serial.begin(9600);
  Serial.println("Comenzando la comunicación con la tarjeta SD");
  pinMode(9, OUTPUT);
  if (!SD.begin(9)) {
    Serial.println("Se ha producido un fallo al iniciar la comunicación");
    return;
  }

  Serial.println("Se ha iniciado la comunicación correctamente");
  Archivo = SD.open("Fichero.txt");
  if (Archivo) {
    Serial.println("Información contenida en tarjeta.txt: ");
    int i =0;
    while (Archivo.available()) {
     char c=Archivo.read();
     if (c==';'){
      Serial.println(json2);
        DeserializationError error = deserializeJson(doc,json2);
        if (error) {
          Serial.print("deserializeJson() failed with code ");
          Serial.println(error.c_str());
          return;
          }
      const char* sensor = doc["sensor"];
      long time = doc["time"];
      double latitude = doc["data"][0];
      double longitude = doc["data"][1];
      Serial.println(sensor);
      Serial.println(time);
      Serial.println(latitude, 6);
      Serial.println(longitude, 6);
     }
     json2.concat(c);
    }
    Archivo.close();
   
  }
  else {
    Serial.println("El archivo datos.txt no se abrió correctamente");
  }

}

void loop()
{
}
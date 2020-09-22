#include <SD.h>

File myFile;
struct Config {
  int pool = 1;
  int temp = 30;
  int oxi = 1000;
  int ph = 5;
  bool alertaTemp = true;
  bool alertaOxi = true;
  bool alertaPh = false;
  String cadena="";
};
Config config;  

void initSD()
{
  Serial.begin(9600);
  Serial.print("Iniciando SD ...");
  if (!SD.begin(9)) {
    Serial.println("No se pudo inicializar");
    return;
  }
  Serial.println("inicializacion exitosa");
}

void escribirSD()
{
    myFile=SD.open("datalog.txt",FILE_WRITE);
  if(myFile)
  {
    Serial.println("Escribiendo en SD: ");
    myFile.println();
    myFile.print("{\"Pool_id\":");
    myFile.print(config.pool);
    myFile.print(", \"Parametros\":");
    myFile.print("{ \"Temperatura\":");
    myFile.print("{\"valor\":");
    myFile.print(config.temp);
    myFile.print(", \"alerta\":");
    myFile.print(config.alertaTemp);
    myFile.print("}");
    myFile.print(", \"Oxigeno\":");
    myFile.print("{ \"valor\":");
    myFile.print(config.oxi);
    myFile.print(", \"alerta\":");
    myFile.print(config.alertaOxi);
    myFile.print("}");
    myFile.print(", \"Ph\":");
    myFile.print("{ \"valor\":");
    myFile.print(config.ph);
    myFile.print(", \"alerta\":");
    myFile.print(config.alertaPh);
    myFile.print("}");
    myFile.print("}");
    myFile.print("} ");
   

    myFile.close();
  }

}

void leerSD()
{
  myFile = SD.open("datalog.txt",FILE_READ);//abrimos  el archivo 

  if (myFile) 
  {
    bool line=false;
    myFile.seek(myFile.size()-1); //Ubicacion en posicion anterior a ultimo caracter
   
    while (myFile.available()) 
    {
      if(line==false) //Primero leer en reversa para buscar salto de linea
      {
        char caracter=myFile.read();
        //Serial.println(caracter);
        myFile.seek(myFile.position()-2);   
        
          if(caracter=='\n') //Cuando encuentra salto de linea cambia estado
          {
            line=true;
          }   
      }

      if(line==true) //Empieza a leer normalmente de izquierda a derecha
      {
          char caracter=myFile.read();
         //Serial.println(caracter);
          config.cadena=config.cadena+caracter;
        
          if(caracter=="} ") //La cadena termina en este caracter para formato JSON
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

  //cadena="";
}

void mostrar()
{
  StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc,config.cadena);
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
      Serial.print(config.cadena);
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

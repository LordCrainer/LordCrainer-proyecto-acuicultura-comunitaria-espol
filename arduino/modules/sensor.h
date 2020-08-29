/*
Agregaré una serie de comentarios para que el código se pueda leer con gran facilidad, sin antes
dar alusión a la siguiente frase.
"Cualquiera puede escribir código que la computadora entiende. Un buen programador escribe código
que los humanos entiendes"                                                                                                                                                                              Martin Fowler

Estos comentarios son para la etapa 2, que es de modularizar el código.
1) Este código se va a tratar de separarlo como un módulo o librería. Y será llamado para que
cumpla con ciertas acciones, en este caso: Devolver los valores de los parámetros.
- Cada medio segundo se va a obtener los valores, así que si hay tiempo para obtener el PH
- Para la etapa 3, sería de tratar de eliminar ese delay, y usar la función de millis.
- Si este código sólo realiza la calibración, entonces cambiar el nombre al archivo.

2) Utiliza la convención camelKase para variables, donde la primera letra de la primera palabra es en
 mínúscula, pero para las siguientes palabras será en mayúscula, ejemplo: temperaturaCalibration, phPin, 
voltajeReferencial, ejemploDeLowerCamelCase
3) Para el uso de constantes, se debe usar el ALL_CAPS, ejemplo: VOLTAJE_REFERENCE,
CALIBRATION_VOLTAJE
4) Definir mejor el nombre de las variables. Deben de ser pronunciables, autoexplicativos, expresivos
 y no tener información técnica (técnica: que está haciendo).
 Ejemplo: voltageCalibration, isActivated, getTemparature, measuredTemperature
 NOTA: Yo sé que para trabajar en microcontroladores se debe de cuidar del espacio que ocupa el 
 nombre de las variables, pero si es así, entonces colocar alguna abreviatura más explicativa.
 
 m_4? => water_ph_7

5) Las librerías deben de estar en la parte de arriba, luego la declaración de constantes,
declaracion de funciones, programa principal y por último el detalle de las funciones.
6) En este caso, es mejor cambiar los valores estáticos por variables, en las funciones. (4, 20)
7) Refactorizar el código: Eliminar los serial.print y cambiarlos por un return

*/
ara que#include <OneWire.h>   //Tener cuidado de lo que se escribe
#include <DallasTemperature.h>

// Temperatura 
OneWire ourWire(4);                //Se establece el pin 2  como bus OneWire //Se recomienda cambiar la variable, no sé que significa ourWire
DallasTemperature sensortemp(&ourWire); //Se declara una variable u objeto para nuestro sensor

// PH
// Pin donde se conecta el sensor de temperatura
const int pinDatosDQ=9;
int ph_pin = A2; // A2 -> Po
int m_4 = 623;
int m_7 = 605; //agua

//Oxigeno Disuelto
#include <Arduino.h>
#define DO_PIN A1
#define VREF 5000    // (mv)
#define ADC_RES 1024 //ADC Resolution

#define CAL1_V (1600) //mv
#define CAL1_T (25)   //℃
const uint16_t DO_Table[41] = {
    14460, 14220, 13820, 13440, 13090, 12740, 12420, 12110, 11810, 11530,
    11260, 11010, 10770, 10530, 10300, 10080, 9860, 9660, 9460, 9270,
    9080, 8900, 8730, 8570, 8410, 8250, 8110, 7960, 7820, 7690,
    7560, 7430, 7300, 7180, 7070, 6950, 6840, 6730, 6630, 6530, 6410};

uint8_t Temperaturet;
uint16_t ADC_Raw;
uint16_t ADC_Voltage;
uint16_t DO;
uint16_t V_saturation;
uint8_t READ_TEMP;

int16_t readDO(uint32_t voltage_mv, uint8_t temperature_c)
{
uint16_t V_saturation = (uint32_t)CAL1_V + (uint32_t)35 * temperature_c - (uint32_t)CAL1_T * 35;
return (voltage_mv * DO_Table[temperature_c] / V_saturation);
}
void setup() {
  // put your setup code here, to run once:
  // Iniciamos la comunicación serie
    Serial.begin(9600);
    // Iniciamos el sensor de temperatura
    sensortemp.begin(); 
}

void loop() {
    // Temperatura
    sensortemp.requestTemperatures();   //Se envía el comando para leer la temperatura
    float temp= sensortemp.getTempCByIndex(0); //Se obtiene la temperatura en ºC
    Serial.print("Temperatura= ");
    Serial.print(temp);
    Serial.println(" C");

  // PH 

   int measure = 0;
   int prom = 0;

    for(int i=0;i<20;i++)
  {  measure = analogRead(ph_pin);
     prom = prom + measure;
     delay(50);
  }

  prom = prom/20;
  //calibracion
  float Po = 7 + ((measure - m_7 ) * 3 / ( m_7 - m_4 ));
  Serial.print("\tPH: ");
  Serial.print(Po/10, 2);
  Serial.println("");


  // Temperatura 
  Temperaturet = (uint8_t)READ_TEMP;
  ADC_Raw = analogRead(DO_PIN);
  ADC_Voltage = uint32_t(VREF) * ADC_Raw / ADC_RES;
  Serial.println("DO:\t" + String(readDO(ADC_Voltage, Temperaturet)/1000) + " mg/L \t");


    delay(4000); 
}
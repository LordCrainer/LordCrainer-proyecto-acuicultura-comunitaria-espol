#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
// Definimos los pines para los sensores 
#define phPIN A2 

#define oxiD A1

//Variables
#define voltageREF 500 // mv
#define adcRES 1024 // ADC Resolution
#define calVoltage 1600 //mv
#define calTemperature 25//°C

OneWire ourWire(4); // Se establece el pin 4 

DallasTemperature sensorTEMP(&ourWire); // Se declara una variable para el sensor 

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

int16_t readOXIGENO(uint32_t voltage_mv, uint8_t temperature_c)
  {
    uint16_t V_saturation = (uint32_t)calVoltage + (uint32_t)35 * temperature_c - (uint32_t)calTemperature * 35;
    return (voltage_mv * DO_Table[temperature_c] / V_saturation);
  }

void setup_prog()
{
  
  sensorTEMP.begin();
}


// Toma de Temperatura
void sensorTEMPE()
  {
    sensorTEMP.requestTemperatures(); 
    float temp = sensorTEMP.getTempCByIndex(0);
    Serial.print("\tTemperatura= ");
    Serial.print(temp);
    Serial.println(" C");
   }

// Medicion PH 
void resultadoPH()
{
  int measure = 0;
  int prom = 0;
   for(int i=0;i<20;i++)
  {  measure = analogRead(phPIN);
     prom = prom + measure;
  }

  prom = prom/20;
  float ph = (7 + ((measure - 605 ) * 3 / ( -18 )))/10;
  Serial.print("\tPH = " );
  Serial.println(ph, 2 );
}

//Medicion Oxigeno Disuelto 
void oxigenoD ()
{
  Temperaturet = (uint8_t)READ_TEMP;
  ADC_Raw = analogRead(oxiD);
  ADC_Voltage = uint32_t(voltageREF) * ADC_Raw / adcRES;
    Serial.print("\tOxigeno Disuelto = ");
    Serial.print(float(readOXIGENO(ADC_Voltage, Temperaturet)/1000));
    Serial.println(" mg/L ");
    delay(10000);
}

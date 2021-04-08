// Definimos los pines para los sensores
#include "../4.domain/sensor-model.hpp"

#define PH_PIN A0

#define D_OXY_PIN A0

//Variables
#define VOLT_REF 500  // mv
#define ADC_RES 1024  // ADC Resolution
#define CAL_VOLT 1600 //mv
#define CAL_TEMP 25   //°C

OneWire ourWire(4); // Se establece el pin 4

DallasTemperature sensorTemp(&ourWire); // Se declara una variable para el sensor

const uint16_t DO_TABLE[41] = {
    14460, 14220, 13820, 13440, 13090, 12740, 12420, 12110, 11810, 11530,
    11260, 11010, 10770, 10530, 10300, 10080, 9860, 9660, 9460, 9270,
    9080, 8900, 8730, 8570, 8410, 8250, 8110, 7960, 7820, 7690,
    7560, 7430, 7300, 7180, 7070, 6950, 6840, 6730, 6630, 6530, 6410};

// uint8_t Temperaturet;
// uint16_t ADC_Raw;
// uint16_t ADC_Voltage;
// uint16_t DO;
// uint16_t V_saturation;
// uint8_t READ_TEMP;

int16_t readingOxygen(uint32_t voltage, uint8_t temperature)
{
  uint16_t voltSaturation = (uint32_t)CAL_VOLT + (uint32_t)35 * temperature - (uint32_t)CAL_TEMP * 35;
  return (voltage * DO_TABLE[temperature] / voltSaturation);
}

void setup_prog()
{

  sensorTemp.begin();
}

// Medición de Temperatura
IParams getTemp()
{
  sensorTemp.requestTemperatures();
  IParams params;
  params.name = "Temperature";
  params.value = sensorTemp.getTempCByIndex(0);
  return params;
  // Serial.print("\tTemperatura= ");
  // Serial.print(temp);
  // Serial.println(" C");
}

// Medicion PH
IParams getPh()
{
  IParams params;
  params.name = "PH";
  int ph = 0;
  int prom = 0;
  for (int i = 0; i < 20; i++)
  {
    ph = analogRead(PH_PIN);
    prom = prom + ph;
  }

  prom = prom / 20;
  params.value = (7 + ((prom - 605) * 3 / (-18))) / 10;
  return params;
  // Serial.print("\tPH = ");
  // Serial.println(ph, 2);
}

//Medicion Oxigeno Disuelto
IParams getDOxygen()
{
  uint8_t READ_TEMP;
  IParams params;
  params.name = "DO";
  uint8_t temperature = (uint8_t)READ_TEMP;
  uint16_t oxyD = analogRead(D_OXY_PIN);
  uint32_t voltage = uint32_t(VOLT_REF) * oxyD / ADC_RES;
  //Serial.print("\tOxigeno Disuelto = ");
  //Serial.print();
  //Serial.println(" mg/L ");
  params.value = float(readingOxygen(voltage, temperature) / 1000);
  return params;
  // delay(10000);
}

// Sensor: Captura los datos de todos los sensores
String getAllSensor()
{
  IParams temp;
  IParams ph;
  temp.name = "Temperature";
  temp.value = 10.0;
  // // getPh();
  ph.value = 7.0;
  ph.name = "PH";
  return modelAllSensor(temp, ph);;
}
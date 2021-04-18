// Definimos los pines para los sensores
#include "../4.domain/sensor-model.hpp"

/**
	 * Sensor/use-case: Permite ajustar el valor del Oxigeno disuelto
   * @param volt  Voltaje medido
   * @param temp  Temperatura actual del agua
	 */
int16_t ajustDO(uint32_t volt, uint8_t temp)
{
  uint16_t volSalt = (uint32_t)CAL_VOLT + (uint32_t)35 * temp - (uint32_t)CAL_TEMP * 35;
  return (volt * DO_TABLE[temp] / volSalt);
}

double getValueTemp()
{
  sensorTemp.requestTemperatures();
  return sensorTemp.getTempCByIndex(0);
}

/**
	 * Sensor/use-case: Obtiene el valor de temperatura
	 */
IParams getTemp()
{
  sensorTemp.requestTemperatures();
  IParams params;
  params.max = 35;
  params.min = 25;
  params.name = "Temperature";
  params.value = getValueTemp();
  return params;
}

/**
	 * Sensor/use-case: Iniciar el bus de datos
	 */
void initSensorTemp()
{
  sensorTemp.begin();
  GLOBAL_TEMP = getTemp();
}

/**
	 * Sensor/use-case: Obtiene el valor de PH
	 */
IParams getPh(byte iteration = 20)
{
  IParams params;
  params.name = "PH";
  int ph = 0;
  double prom = 0;
  for (int i = 0; i < iteration; i++)
  {
    ph = analogRead(PH_PIN);
    prom = prom + ph;
  }
  prom = prom / iteration;
  params.value = (7 + ((prom - 605) * 3 / (-18))) / 10;
  return params;
}

/**
	 * Sensor/use-case: Obtiene el valor del Oxigeno disuelto
	 */
IParams getDOxygen()
{
  IParams params;
  params.name = "DO";
  uint8_t temp = (uint8_t)GLOBAL_TEMP.value;
  uint16_t oxyD = analogRead(D_OXY_PIN);
  uint32_t volt = uint32_t(VOLT_REF) * oxyD / ADC_RES;
  params.value = float(ajustDO(volt, temp) / 1000);
  return params;
}

/**
	 * Sensor/use-case: Realiza un barrido de todo los sensores manualmente insertados
	 */
String getAllSensor()
{
  IParams temp = GLOBAL_TEMP;
  IParams ph = getPh();
  IParams DO;
  DO.value = 21;
  DO.name = "DO";
  return modelAllSensor(temp, ph, DO);
}

unsigned long getTempDelay(unsigned long lastTime, unsigned long timerDelay)
{
  if ((millis() - lastTime) > timerDelay)
  {
    GLOBAL_TEMP = getTemp();
    lastTime = millis();
  }
  return lastTime;
}
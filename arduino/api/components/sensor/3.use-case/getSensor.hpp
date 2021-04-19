// *************** TEMPERATURE ***************
double getValueTemp()
{
  sensorTemp.requestTemperatures();
  return sensorTemp.getTempCByIndex(0);
}

/**
	 * Sensor/use-case: Obtiene el valor de temperatura
	 */
ISensor getTemp(ISensor temp)
{
  temp.value = getValueTemp();
  temp.alert = sensorStatus(temp);
  return temp;
}

/**
	 * Sensor/use-case: Iniciar el bus de datos
	 */
void initSensors()
{
  GLOBAL_TEMP.name = "Temperature";
  GLOBAL_TEMP.max = 35;
  GLOBAL_TEMP.min = 30;
  GLOBAL_PH.name = "PH";
  GLOBAL_PH.max = 8.00;
  GLOBAL_PH.min = 6.00;
  GLOBAL_DO.name = "DO";
  GLOBAL_DO.max = 200;
  GLOBAL_DO.min = 100;
  sensorTemp.begin();
  GLOBAL_TEMP = initilizeSensor("/config/sensor/temp", GLOBAL_TEMP);
  GLOBAL_PH = initilizeSensor("/config/sensor/ph", GLOBAL_PH);
  GLOBAL_DO = initilizeSensor("/config/sensor/do", GLOBAL_DO);
}

// *************** PH ***************
double getValuePH(const uint8_t pin, byte iteration)
{
  int ph = 0;
  double prom = 0;
  for (int i = 0; i < iteration; i++)
  {
    ph = analogRead(pin);
    prom = prom + ph;
  }
  prom = prom / iteration;
  return (7 + ((prom - 605) * 3 / (-18))) / 10;
}

/**
	 * Sensor/use-case: Obtiene el valor de PH
	 */
ISensor getPh(ISensor ph, byte iteration = 20)
{
  ph.value = getValuePH(PH_PIN, iteration);
  ph.alert = sensorStatus(ph);
  return ph;
}

// *************** DO ***************
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
/**
	 * Sensor/use-case: Obtiene el valor del Oxigeno disuelto
	 */
ISensor getDOxygen(ISensor DO)
{
  uint8_t temp = (uint8_t)GLOBAL_TEMP.value;
  uint16_t oxyD = analogRead(D_OXY_PIN);
  uint32_t volt = uint32_t(VOLT_REF) * oxyD / ADC_RES;
  DO.value = float(ajustDO(volt, temp) / 1000);
  DO.alert = sensorStatus(DO);
  return DO;
}

// *************** GENERAL ***************
/**
	 * Sensor/use-case: Realiza un barrido de todo los sensores manualmente insertados
	 */
String getAllSensor(ISensor sensors[])
{
  byte len = sizeof(sensors);
  ISensor DO;
  DO.value = 21;
  DO.name = "DO";
  for (byte i = 0; i < len; i++)
  {
    if (sensors[i].name == GLOBAL_PH.name)
    {
      sensors[i] = getPh(GLOBAL_PH);
    }
    if (sensors[i].name == GLOBAL_DO.name)
    {
      sensors[i] = DO;
    }
    if (sensors[i].name == GLOBAL_TEMP.name)
    {
      sensors[i] = GLOBAL_TEMP;
    }
  }

  // ISensor params[] = {GLOBAL_TEMP, getPh(GLOBAL_PH), DO};
  return modelAllSensor(sensors);
}

unsigned long getTempDelay(unsigned long lastTime, unsigned long timerDelay)
{
  if ((millis() - lastTime) > timerDelay)
  {
    GLOBAL_TEMP = getTemp(GLOBAL_TEMP);
    lastTime = millis();
  }
  return lastTime;
}
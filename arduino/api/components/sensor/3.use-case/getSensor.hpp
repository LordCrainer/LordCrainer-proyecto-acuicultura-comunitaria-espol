// *************** GENERAL ***************
/**
 * Sensor/use-case: Obtiene los datos de un sensor
 * @param sensor Estructura de tipo ISensor
*/
String getOneSensor(ISensor sensor)
{
  String data = sensorModel(execOneSensor(sensor));
  Serial.println("SENSOR/USE-CASE: " + data);
  return data;
}
/**
	 * Sensor/use-case: Realiza un barrido de todo los sensores manualmente insertados
   * @param sensors Array con estructura de tipo ISensor
	 */
String getSomeSensors(ISensor sensors[])
{
  byte len = sizeof(sensors) - 1;
  String data;
  for (byte i = 0; i < len; i++)
  {
    data = data + "," + getOneSensor(sensors[i]);
  }
  // modelAllSensor(sensors);
  data.remove(0, 1);
  return data;
}

unsigned long getTemperatureWithDelay(unsigned long lastTime, unsigned long timerDelay)
{
  if ((millis() - lastTime) > timerDelay)
  {
    GLOBAL_TEMP = getTemp(GLOBAL_TEMP);
    lastTime = millis();
  }
  return lastTime;
}

/**
	 * Sensor/use-case: Iniciar el bus de datos
	 */
void initSensors() //ISensor sensors[]
{
  sensorTemp.begin();
  GLOBAL_TEMP.name = "temperature";
  GLOBAL_TEMP.max = 36;
  GLOBAL_TEMP.min = 31;
  GLOBAL_PH.name = "ph";
  GLOBAL_TEMP.max = 8.52;
  GLOBAL_TEMP.min = 6.52;
  GLOBAL_DO.name = "do";
  GLOBAL_TEMP.max = 150;
  GLOBAL_TEMP.min = 120;
  GLOBAL_TEMP = initilizeSensor("/config/sensor/temp.json", GLOBAL_TEMP);
  GLOBAL_PH = initilizeSensor("/config/sensor/ph.json", GLOBAL_PH);
  GLOBAL_DO = initilizeSensor("/config/sensor/do.json", GLOBAL_DO);
}
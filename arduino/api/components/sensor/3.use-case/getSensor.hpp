// *************** GENERAL ***************
/**
 * Sensor/use-case: Obtiene los datos de un sensor
 * @param sensor Estructura de tipo ISensor
*/
String getOneSensor(ISensor sensor)
{
  return sensorModel(execOneSensor(sensor));
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
// *************** GENERAL ***************

String getOneSensor(ISensor sensor)
{
  return sensorModel(sensor);
}
/**
	 * Sensor/use-case: Realiza un barrido de todo los sensores manualmente insertados
	 */
String getAllSensor(ISensor sensors[])
{
  byte len = sizeof(sensors) - 1;
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
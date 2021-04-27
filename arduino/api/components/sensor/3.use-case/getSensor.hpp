// *************** GENERAL ***************

String getOneSensor(ISensor sensor)
{
  return sensorModel(execOneSensor(sensor));
}
/**
	 * Sensor/use-case: Realiza un barrido de todo los sensores manualmente insertados
	 */
String getManySensor(ISensor sensors[])
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

unsigned long getTempDelay(unsigned long lastTime, unsigned long timerDelay)
{
  if ((millis() - lastTime) > timerDelay)
  {
    GLOBAL_TEMP = getTemp(GLOBAL_TEMP);
    lastTime = millis();
  }
  return lastTime;
}
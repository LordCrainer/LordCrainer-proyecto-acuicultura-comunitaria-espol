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
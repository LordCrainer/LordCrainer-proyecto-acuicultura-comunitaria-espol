// ***************   DO *****************
/**
	 * Sensor/domain/sensors: Permite ajustar el valor del Oxigeno disuelto
   * @param volt  Voltaje medido
   * @param temp  Temperatura actual del agua
	 */
int16_t ajustDO(uint32_t volt, uint8_t temp)
{
    uint16_t volSalt = (uint32_t)CAL_VOLT + (uint32_t)35 * temp - (uint32_t)CAL_TEMP * 35;
    return (volt * DO_TABLE[temp] / volSalt);
}

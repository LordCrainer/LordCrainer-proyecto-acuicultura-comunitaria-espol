/**
	 * utils/time
	 * 
     * Obtiene el tiempo actual del RTC
	 */
DateTime getTime()
{
    DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC */
    return now;
}

String getTimeUnix()
{
    return String(getTime().unixtime()) + "000";
}
String getTime()
{
    DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC */
    return String(now);
}
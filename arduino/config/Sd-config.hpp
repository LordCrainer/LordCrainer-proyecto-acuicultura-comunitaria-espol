boolean initSD()
{
    if (SD.begin(PIN_SD))
    {
        return true;
    }
    return false;
}
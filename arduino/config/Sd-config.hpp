byte initSD()
{
    if (SD.begin(PIN_SD))
    {
        return 1;
    }
    return 0;
}
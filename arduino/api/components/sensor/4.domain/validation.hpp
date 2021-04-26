String sensorStatus(ISensor param)
{
    String letter = param.name.substring(0, 1);
    if (param.value > param.max)
    {
        return "SL" + letter;
    }
    if (param.value < param.min)
    {
        return "BL" + letter;
    }
    return "OK";
}
String readSerialData()
{
    String rdata;
    String myString;
    if (Serial.available() > 0)
    {
        rdata = Serial.read();
        myString = myString + rdata;
        if (rdata == '\n')
        {
        }
        return String;
    }
    return "";
}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = [ 0, -1 ];
    int maxIndex = data.length() - 1;
    
}
struct IDirectory
{
  String name;
  byte type;
  String content;
};

struct IFiles
{
  String name;
  byte type;
  int size;
};

boolean initSD()
{
    if (SD.begin(PIN_SD))
    {
        return true;
    }
    return false;
}
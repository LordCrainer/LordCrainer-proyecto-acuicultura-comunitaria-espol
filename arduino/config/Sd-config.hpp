// PIN
const PROGMEM uint16_t PIN_SD = 15; // D8

// INTERFACE
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

// SETUP

boolean initSD()
{
  if (SD.begin(PIN_SD))
  {
    return true;
  }
  return false;
}

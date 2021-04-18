// PIN
const PROGMEM uint16_t PIN_SD = 15; // D8

// SETUP

boolean initSD()
{
  if (SD.begin(PIN_SD))
  {
    return true;
  }
  return false;
}

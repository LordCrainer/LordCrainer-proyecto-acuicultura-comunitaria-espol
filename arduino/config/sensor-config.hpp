// CALIBRATION DE LOS SENSORES
const PROGMEM int REFERENCE_VOLT = 500;         // mv
const PROGMEM int RESOLUTION_ADC = 1024;        // ADC Resolution
const PROGMEM int CALIBRATION_VOLT = 1600;      //mv
const PROGMEM byte CALIBRATION_TEMP = 25;       //°C

// PIN
const PROGMEM byte TEMP_PIN = 0; // D3

struct IParams
{
    String name;
    double value;
    char alert[4] = "OK";
    double max;
    double min;
};

IParams global_temp;
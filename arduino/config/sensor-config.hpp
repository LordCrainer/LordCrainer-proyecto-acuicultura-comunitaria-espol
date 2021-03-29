// CALIBRATION DE LOS SENSORES

const int REFERENCE_VOLT = 500;    // mv
const int RESOLUTION_ADC = 1024;   // ADC Resolution
const int CALIBRATION_VOLT = 1600; //mv
const byte CALIBRATION_TEMP = 25;   //°C

struct IParams
{
    String name;
    float value;
    char alert[3];
};
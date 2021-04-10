// CALIBRATION DE LOS SENSORES
const int REFERENCE_VOLT = 500;         // mv
const int RESOLUTION_ADC = 1024;        // ADC Resolution
const int CALIBRATION_VOLT = 1600;      //mv
const byte CALIBRATION_TEMP = 25;       //°C

// PIN
const byte TEMP_PIN = 0; // D3

struct IParams
{
    String name;
    double value;
    char alert[4] = "OK";
};

IParams global_temp;
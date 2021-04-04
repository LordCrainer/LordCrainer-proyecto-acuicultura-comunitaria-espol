// CALIBRATION DE LOS SENSORES
OneWire ourWire(4); // Se establece el pin 4

DallasTemperature sensorTemp(&ourWire); // Se declara una variable para el sensor
const int REFERENCE_VOLT = 500;         // mv
const int RESOLUTION_ADC = 1024;        // ADC Resolution
const int CALIBRATION_VOLT = 1600;      //mv
const byte CALIBRATION_TEMP = 25;       //°C

struct IParams
{
    String name;
    double value;
    char alert[4] = "OK";
};
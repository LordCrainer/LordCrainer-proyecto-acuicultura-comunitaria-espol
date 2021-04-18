// CALIBRATION DE LOS SENSORES
const PROGMEM int VOLT_REF = 500;  // mv
const PROGMEM int ADC_RES = 1024;  // ADC Resolution
const PROGMEM int CAL_VOLT = 1600; //mv
const PROGMEM byte CAL_TEMP = 25;  //°C

// PIN
const PROGMEM byte TEMP_PIN = 0; // D3
const PROGMEM byte D_OXY_PIN = A0;
const PROGMEM uint8_t PH_PIN = A0;

// PARAMETROS

const uint16_t DO_TABLE[41] = {
    14460, 14220, 13820, 13440, 13090, 12740, 12420, 12110, 11810, 11530,
    11260, 11010, 10770, 10530, 10300, 10080, 9860, 9660, 9460, 9270,
    9080, 8900, 8730, 8570, 8410, 8250, 8110, 7960, 7820, 7690,
    7560, 7430, 7300, 7180, 7070, 6950, 6840, 6730, 6630, 6530, 6410};

OneWire ourWire(TEMP_PIN);

DallasTemperature sensorTemp(&ourWire); // Se declara una variable para el sensor
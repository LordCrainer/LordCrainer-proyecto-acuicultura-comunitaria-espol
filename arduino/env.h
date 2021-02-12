// CONFIGURACION DEL SERVIDOR
const PROGMEM  uint16_t port = 80;


// CONFIGURACION DE LA RED

const char* ssid     = "PRUEBA_NODEMCU";
const char* password = "12345678";
const char* hostname = "ESP8266_1";

// CONFIGURACIÓN SD CARD
const PROGMEM  uint16_t PIN_SD = 15; // D8

// ASIGNACION DE PINES PARA BOTONES
const PROGMEM byte BOT_ARRIBA = 7;
const PROGMEM byte BOT_ABAJO = 6;
const PROGMEM byte BOT_OK = 5;
const PROGMEM byte BOT_CANCELAR = 4;
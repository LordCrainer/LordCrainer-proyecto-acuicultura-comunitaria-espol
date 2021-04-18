struct ILCD_CHARACTER
{
    byte CHAR_UP[8] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00100,
        B01010,
        B10001,
        B00000};
    byte CHAR_DOWN[8] = {
        B10001,
        B01010,
        B00100,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000};
};

// Caracteres especiales direccion arriba y abajo
byte CHAR_UP[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00100,
    B01010,
    B10001,
    B00000};

byte CHAR_DOWN[8] = {
    B10001,
    B01010,
    B00100,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000};

struct IMenu
{
    String name;
    String opts;
};

/* struct IButtons
{
    uint16_t ARRIBA;
    uint16_t ABAJO;
    uint16_t OK;
    uint16_t CANCELAR;
}; */

void printLCD()
{
}
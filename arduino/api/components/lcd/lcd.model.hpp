struct LCD
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
    int pool = 1;
    int temp = 30;
    int oxi = 1000;
    int ph = 5;
    bool alertaTemp = true;
    bool alertaOxi = true;
    bool alertaPh = false;
    String cadena = "";
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
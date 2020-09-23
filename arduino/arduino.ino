#include <Arduino.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

//Asignacion de pines lcd 20x4
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
//Asignacion de pines para botones
int BOT_ARRIBA = 7;
int BOT_ABAJO = 6;
int BOT_OK = 5;
int BOT_CANCELAR = 4;


//DECLARACION DE FUNCIONES
#include "./api/components/lcd/lcd.service.hpp"

// Caracteres especiales direccion arriba y abajo

void setup()
{

  setup_lcd();
  // set up the LCD's number of columns and rows:

  //Bucle principal
}
void loop()
{
  controlBoton();
  menuPrin();
}

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
//Asignacion de pines para botones
int BOT_ARRIBA = 7;
int BOT_ABAJO = 6;
int BOT_OK = 5;
int BOT_CANCELAR = 4;

void setup_lcd()
{
  lcd.begin(20, 4);
  pinMode(BOT_ARRIBA,INPUT_PULLUP);
  pinMode(BOT_ABAJO,INPUT_PULLUP);
  pinMode(BOT_OK,INPUT_PULLUP);
  pinMode(BOT_CANCELAR,INPUT_PULLUP);

}
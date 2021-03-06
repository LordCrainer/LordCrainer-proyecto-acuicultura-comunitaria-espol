const PROGMEM uint8_t lcd_cols = 16;
const PROGMEM uint8_t lcd_rows = 2;
/**
	 * Constructor
	 *
	 * @param lcd_addr	I2C slave address of the LCD display. Most likely printed on the LCD circuit board, or look in the supplied LCD documentation.
	 * @param lcd_cols	Number of columns your LCD display has.
	 * @param lcd_rows	Number of rows your LCD display has.
	 * @param charsize	The size in dots that the display has, use LCD_5x10DOTS or LCD_5x8DOTS.
	 */
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ASIGNACION DE PINES PARA BOTONES
const PROGMEM uint16_t BOT_ARRIBA = 7;
const PROGMEM uint16_t BOT_ABAJO = 6;
const PROGMEM uint16_t BOT_OK = 5;
const PROGMEM uint16_t BOT_CANCELAR = 4;

/**
	 * Set the LCD display in the correct begin state, must be called before anything else is done.
	 */
void initLCD(String message = "")
{
	lcd.begin();
	// lcd.backlight();
	lcd.print(message);
	/*   pinMode(BOT_ARRIBA,INPUT_PULLUP);
  pinMode(BOT_ABAJO,INPUT_PULLUP);
  pinMode(BOT_OK,INPUT_PULLUP);
  pinMode(BOT_CANCELAR,INPUT_PULLUP); */
}
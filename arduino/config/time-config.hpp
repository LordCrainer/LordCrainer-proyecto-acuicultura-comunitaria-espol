RTC_DS1307 RTC;
unsigned long lastTime = 0;
void initTime()
{
    Wire.begin(4, 5, 0x02);
    RTC.begin();
    RTC.adjust(DateTime(__DATE__, __TIME__));
    delay(500);
}

/* void setup () {
Wire.begin(0,2); // Inicia el puerto I2C
RTC.begin(); // Inicia la comunicación con el RTC
delay(500);
RTC.adjust(DateTime(__DATE__, __TIME__)); // Establece la fecha y hora (Comentar una vez establecida la hora)
delay(1000);
Serial.begin(115200); // Establece la velocidad de datos del puerto serie

}
void loop(){
DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC */
void initSD()
{
    Serial.begin(9600);
    Serial.print("Iniciando SD ...");
    if (!SD.begin(9))
    {
        Serial.println("No se pudo inicializar");
        return;
    }
    Serial.println("inicializacion exitosa");
}
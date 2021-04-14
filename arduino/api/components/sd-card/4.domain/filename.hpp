/**
	 * sd-card/domain:  Establece el nombre del archivo
	 * 
	 * @param letter    Letra de inicio del archivo
	 * @param pool_id	El número de identificación de la piscina.
	 * @param time	Tiempo actual o establecido.
	 * @param ext	La extensión del archivo
	 */
String setFilename(const char letter[2], byte pool_id, String time, String ext)
{
    return letter + String(pool_id) + "_" + time + "." + ext;
}
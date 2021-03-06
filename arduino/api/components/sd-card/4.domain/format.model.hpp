/**
	 * sd-card/domain: Ajusta la unidad del espacio ocupado de un archivo
	 * 
	 * @param size    Tamaño del archivo
	 */
String ajustUnitSize(int size)
{
    const float KB = 1000.0;
    const float MB = 1000.0 * 1000.0;
    if (size >= MB)
    {
        return String(size / MB) + "MB";
    }
    if (size >= KB)
    {
        return String(size / KB) + "KB";
    }
    return String(size) + "B";
}
//typedef = Definición del tipo
//String = return value, String = cadena void = none
//callFunction = Nombre del tipo de función
//String, byte = arguments
//
// Ejemplo: String anyName(callFunction theFunctionAsParameter)
typedef String (*callFunction)(String, byte);

String repeatFunction(callFunction func, byte iteration, String time, byte pool_id)
{
    String allData;
    for (i = 0; i < iteration; i++)
    {
        allData = allData + func(time, pool_id);
    }
    return allData;
}
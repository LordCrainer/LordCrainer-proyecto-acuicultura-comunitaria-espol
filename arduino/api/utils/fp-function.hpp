//typedef = Definición del tipo
//String = return value, String = cadena void = none
//callFunction = Nombre del tipo de función
//String, byte = arguments
//
// Ejemplo: String anyName(callFunction theFunctionAsParameter)
typedef String (*callFunction)(String, byte);

String repeatFunction(callFunction func, byte iteration, String time, byte pool_id)
{
    int capacity = 210 * iteration;
    String json;
    DynamicJsonDocument doc(capacity);
    JsonArray arr = doc.as<JsonArray>();
    for (byte i = 0; i < iteration; i++)
    {
        arr.add(func(time, pool_id));
    }
    serializeJson(doc, json);
    return json;
}
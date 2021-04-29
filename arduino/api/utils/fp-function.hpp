//typedef = Definición del tipo
//String = return value, String = cadena void = none
//callFunction = Nombre del tipo de función
//String = argument
//
// Ejemplo: String anyName(callFunction theFunctionAsParameter)
typedef String (*callFunction)(String);

void mergeObjs(JsonObject dest, JsonObjectConst src)
{
    for (auto kvp : src)
    {
        dest[kvp.key()] = kvp.value();
    }
}
//typedef = Definición del tipo
//String = return value, String = cadena void = none
//callFunction = Nombre del tipo de función
//String, byte = arguments
//
// Ejemplo: String anyName(callFunction theFunctionAsParameter)
typedef String (*callFunction)(String, byte);

{
    int capacity = 210 * iteration;
    String json;
    DynamicJsonDocument doc(capacity);
    String data;
    String temp;
    for (byte i = 0; i < iteration; i++)
    {
        data = func(time, pool_id);
        data.replace("\\", "");
        if (i == iteration - 1)
        {
            temp = temp + data;
            break;
        }
        temp = data + "," + temp;
        // Serial.println("[" + data + "]");
        // arr[i] = "value";
        params.add(data);
    }
    Serial.println("DATA FINAL: ");
    Serial.println(temp);
    Serial.println("DATA SERIALIZADA: ");
    serializeJson(doc, json);
    Serial.println(json);

    //Serial.println(value2);

    return json;
}
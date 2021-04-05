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
    String data;
    /*     deserializeJson(doc, );
    JsonObject root = doc.as<JsonObject>();
    const char *value = root["pool_id"];
    Serial.println(String(value)); */
    // JsonArray arr = doc.as<JsonArray>();
    JsonArray params = doc.createNestedArray("params");
    for (byte i = 0; i < iteration; i++)
    {
        data = func(time, pool_id);
        data.replace("\\", "");
        // Serial.println("[" + data + "]");
        // arr[i] = "value";
        params.add(data);
    }
    Serial.println("Saliendo del for: ");
    serializeJson(doc, json);
    Serial.println(json);
    DynamicJsonDocument doc2(capacity);
    deserializeJson(doc2, json);
    JsonObject rep = doc2["params"];
    const char *value = doc2["params"];
    const char *value2 = doc2[0];
    Serial.println("\n VALUE: ");
    Serial.println(value);
    Serial.println(value2);

    return json;
}
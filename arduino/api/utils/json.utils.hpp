
string dinamicSerializeJson(int sizeDoc, const char *key)
{
    DynamicJsonDocument doc(sizeDoc);
    doc["sensor"] = "gps";

    doc["time"] = 1351824120;
    doc["data"][0] = 48.756080;
    doc["data"][1] = 2.302038;

    serializeJson(doc, Serial);
}

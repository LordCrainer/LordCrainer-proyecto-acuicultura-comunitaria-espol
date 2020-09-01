#include <ArduinoJson.h>

typedef void (*someFunction)(void);

String toJsonDynamic(char *key, char *value, int sizeDoc = 1024)
{
    String json;
    DynamicJsonDocument doc(sizeDoc);
    doc[key] = value;
    serializeJson(doc, json);
    return json;
}
String toJsonStatic(char *key, char *value, int sizeDoc = 256)
{
    String json;
    StaticJsonDocument<sizeDoc> doc;
    doc[key] = value;
    serializeJson(doc, json);
    return json;
}

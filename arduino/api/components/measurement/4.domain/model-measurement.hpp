
String measurementModel(IMeasurement data)
{
    String json;
    int capacity = JSON_ARRAY_SIZE(3) + 3 * JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(5);
    DynamicJsonDocument doc(capacity);
    doc["pool_id"] = data.pool_id;
    doc["device_id"] = data.device_id;
    doc["created_at"] = data.created_at;
    doc["status"] = data.status;
    doc["params"] = serialized(data.params);
    serializeJson(doc, json);
    return json;
}
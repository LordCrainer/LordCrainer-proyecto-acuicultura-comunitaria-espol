
String measurementModel(IMeasurement data)
{
    String json;
    DynamicJsonDocument doc(192);
    doc["pool_id"] = data.pool_id;
    doc["device_id"] = data.device_id;
    doc["created_at"] = data.created_at;
    doc["status"] = data.status;
    doc["params"] = serialized(data.params);
    serializeJson(doc, json);
    return json;
}
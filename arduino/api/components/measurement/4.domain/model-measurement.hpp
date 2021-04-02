
String measurementModel(IMeasurement data)
{
    String json;
    StaticJsonDocument<192> doc;
    doc["pool_id"] = data.pool_id;
    doc["device_id"] = data.device_id;
    doc["created_at"] = data.created_at;
    doc["status"] = data.status;
    // JsonArray params = doc.createNestedArray("params");
    // params.add(data.params);
    serializeJson(doc, json);
    return json;
}
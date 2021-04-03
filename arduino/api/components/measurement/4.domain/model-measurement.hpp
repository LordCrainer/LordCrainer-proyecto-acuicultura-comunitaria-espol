
String measurementModel(IMeasurement data)
{
    String json;
    DynamicJsonDocument doc(192);
    doc["pool_id"] = data.pool_id;
    doc["device_id"] = data.device_id;
    doc["created_at"] = data.created_at;
    doc["status"] = data.status;
    doc["data"] = "100";
    JsonArray array = doc.to<JsonArray>();
    JsonDocument params = doc.createNestedArray("params");
    JsonObject params_0 = params.createNestedObject();
    params_0["name"] = "Temperature";
    params_0["value"] = 10.2;
    // JsonArray params = doc.createNestedArray("params");
    // params.add(data.params);
    serializeJson(doc, json);
    return json;
}
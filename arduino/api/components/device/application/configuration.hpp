String getAllConfig()
{
    String config;
    const size_t capacity = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3);
    DynamicJsonDocument doc(capacity);

    doc["device_id"] = 101;

    JsonObject configuration = doc.createNestedObject("configuration");

    JsonObject configuration_sampling = configuration.createNestedObject("sampling");
    configuration_sampling["time"] = 2;
    configuration_sampling["delay"] = 15;
    configuration_sampling["rate"] = 1;

    serializeJson(doc, config);
    return config;
}
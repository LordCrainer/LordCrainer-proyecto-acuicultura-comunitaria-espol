void setConfigWifi(String filename)
{
    String data = "{\"mode\": \"AP\", \"staticIp\":false}";
    writeSD("/config/wifi/config.json", data);
}

void initWifiMode(String mode = "AP", boolean useStaticIP = false)
{
    String config = readSD("/config/wifi/config.json");
    if (config == "")
    {
        setConfigWifi("/config/wifi/config.json");
    }
    mode = jsonToString(config, "mode", 25);
    String staticIp = jsonToString(config, "staticIp", 25);

    mode = mode == "" ? "AP" : mode;
    useStaticIP = staticIp == "true" ? true : false;

    if (mode == "STA")
    {
        ConnectWiFi_STA(useStaticIP);
    }
    if (mode == "AP")
    {
        ConnectWiFi_AP(useStaticIP);
    }
}

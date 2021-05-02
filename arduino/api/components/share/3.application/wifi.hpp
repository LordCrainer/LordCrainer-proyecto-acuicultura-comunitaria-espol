void initWifiMode(String mode = "STA", boolean useStaticIP = false)
{
    String config = readSD("/config/wifi/config.json");

    mode = jsonToString(config, "mode", 25);
    String staticIp = jsonToString(config, "staticIp", 25);

    mode = mode == "" ? "STA" : mode;
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
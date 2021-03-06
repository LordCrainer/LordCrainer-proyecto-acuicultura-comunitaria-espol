IPAddress ip = IPAddress(192, 168, 150, 146);
IPAddress gateway = IPAddress(192, 168, 150, 1);
IPAddress subnet = IPAddress(255, 255, 255, 0);

void ConnectWiFi_STA(bool useStaticIP = false)
{
  Serial.println("");
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID_STA, PASSWORD_STA);
  if (useStaticIP)
    WiFi.config(ip, gateway, subnet);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print('.');
  }

  Serial.println("\nMODE STATION ON - SSID:\t");
  Serial.println(SSID_STA);
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
}

void ConnectWiFi_AP(bool useStaticIP = false)
{
  Serial.println("");
  WiFi.mode(WIFI_AP);
  while (!WiFi.softAP(SSID_AP, PASSWORD_AP))
  {
    Serial.println(".");
    delay(100);
  }
  if (useStaticIP)
    WiFi.softAPConfig(ip, gateway, subnet);

  Serial.print("\nMODE ACCESS-POINT ON - SSID:\t");
  Serial.println(SSID_AP);
  Serial.print("IP address:\t");
  Serial.println(WiFi.softAPIP());
}

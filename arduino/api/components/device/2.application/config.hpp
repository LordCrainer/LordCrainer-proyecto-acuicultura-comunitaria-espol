String getAllConfig()
{
    String configuration = readSD("configuration.txt");
    configuration = configurationModel();
    return configuration;
}
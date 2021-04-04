String allConfig()
{
    String configuration = readSD("configuration.txt");
    configuration = configurationModel();
    return configuration;
}
void initFS()
{
    if (!LittleFS.begin())
    {
        Serial.printf("Unable to begin(), aborting\n");
        return;
    }
}

String writeFS(const char *dirname, const char *infodata)
{
    File f = LittleFS.open(dirname, "w");
    if (f)
    {

        f.write(infodata);
        f.close();
        return "OK FS";
    }
    return "FAILED FS";
}

String readFS(const char *dirname)
{
    File f = LittleFS.open(dirname, "r");
    String readed = f.readString();
    f.close();
    return readed;
}
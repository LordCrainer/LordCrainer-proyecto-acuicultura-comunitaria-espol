#include "../4.domain/file-model.hpp"

void initFS()
{
    if (!LittleFS.begin())
    {
        Serial.printf("Unable to begin(), aborting\n");
        return;
    }
}

String writeFS(String dirname, String infodata)
{
    File f = LittleFS.open(dirname.c_str(), "w");
    if (f)
    {
        f.write(infodata.c_str());
        f.close();
        return "OK FS";
    }
    return "FAILED FS";
}

String readFS(String dirname)
{
    File f = LittleFS.open(dirname.c_str(), "r");
    String readed = f.readString();
    f.close();
    return readed;
}

String appendFile(String path, String message){
    // Serial.printf("Appending to file: %s\r\n", path);

    File file = LittleFS.open(path.c_str(), "a");
    if(!file){
        Serial.println("- failed to open file for appending");
        return "BAD";
    }
    if(file.print(message.c_str())){
        Serial.println("- message appended");
    } else {
        Serial.println("- append failed");
        return "BAD";
    }
    file.close();
    return "OK";
}
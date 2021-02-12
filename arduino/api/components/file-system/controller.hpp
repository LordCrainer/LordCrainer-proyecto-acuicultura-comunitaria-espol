#include "./service.hpp"

void readingFS(AsyncWebServerRequest *request)
{
    String response = readFS("data.txt");
    request->send(200, "application/json", response);
}
void writingFS(AsyncWebServerRequest *request)
{
    String response = writeFS("data.txt", "Solo es una prueba");
    request->send(200, "application/json", response);
}

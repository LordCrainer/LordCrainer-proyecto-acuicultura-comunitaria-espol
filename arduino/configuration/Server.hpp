AsyncWebServer server(port);

#include "../api/utils/api.utils.hpp"
#include "../api/utils/json.utils.hpp"
#include "../api/components/measurement/measurement.controller.hpp"


void InitServer()
{
	// TEST
	server.on("/", HTTP_GET, homeRequest);
	server.on("/item", HTTP_GET, getRequest);
	server.on("/item", HTTP_POST, [](AsyncWebServerRequest * request){}, NULL, postRequest);
	server.on("/item", HTTP_PUT, [](AsyncWebServerRequest * request){}, NULL, putRequest);
	server.on("/item", HTTP_PATCH, [](AsyncWebServerRequest * request){}, NULL, patchRequest);
	server.on("/item", HTTP_DELETE, deleteRequest);

	// MEASUREMENT
	server.on("/measurement", HTTP_GET, getAll);

	// ERROR
	server.onNotFound(notFound);

	server.begin();
    Serial.println("HTTP server started");
}
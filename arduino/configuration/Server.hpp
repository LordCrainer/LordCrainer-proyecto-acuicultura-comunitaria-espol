AsyncWebServer server(port);

#include "../api/utils/api.utils.hpp"
#include "../api/utils/json.utils.hpp"
#include "../api/components/sd-card/sdCard.service.hpp"
#include "../api/components/measurement/measurement.controller.hpp"
#include "../api/components/device/controller.hpp"

void InitServer()
{
	// TEST
	server.on("/", HTTP_GET, homeRequest);
	server.on("/item", HTTP_GET, getRequest);
	server.on(
		"/item", HTTP_POST, [](AsyncWebServerRequest *request) {}, NULL, postRequest);
	server.on(
		"/item", HTTP_PUT, [](AsyncWebServerRequest *request) {}, NULL, putRequest);
	server.on(
		"/item", HTTP_PATCH, [](AsyncWebServerRequest *request) {}, NULL, patchRequest);
	server.on("/item", HTTP_DELETE, deleteRequest);

	// TESTING LIBRARY
	server.on("/json", HTTP_GET, arduinoJsonCommonVariable);
	server.on("/headers", HTTP_GET, getHeaders);		  // /headers/12  /headers?pool_id=1
	server.on("/parameters", HTTP_GET, getAllParameters); // /parameters?pool_id=1 /parameters/12

	// MEASUREMENT
	server.on("/measurement", HTTP_GET, getRequest); //  /measurement?pool_id=1
	server.on("/measurement", HTTP_DELETE, deleteRequest);
	
	// DEVICE
	server.on("/device/configuration", HTTP_GET, allConfiguration);
	server.on("/device/start", HTTP_GET, initMeasurement);


	// DEVICE
	server.on("/device/start", HTTP_GET, startMeasurement);
	server.on("/device/configuration", HTTP_GET, allConfiguration);

	// ERROR
	server.onNotFound(notFound);
	server.begin();
	Serial.println("HTTP server started");
}
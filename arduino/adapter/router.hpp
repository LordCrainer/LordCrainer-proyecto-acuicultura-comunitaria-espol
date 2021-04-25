void InitServer()
{
	// TEST
	server.on("/", HTTP_GET, homeRequest);
	// server.on("/item", HTTP_GET, getRequest);
	server.on(
		"/item", HTTP_POST, [](AsyncWebServerRequest *request) {}, NULL, postRequest);
	server.on(
		"/item", HTTP_PUT, [](AsyncWebServerRequest *request) {}, NULL, putRequest);
	server.on(
		"/item", HTTP_PATCH, [](AsyncWebServerRequest *request) {}, NULL, patchRequest);
	server.on("/item", HTTP_DELETE, deleteRequest);

	// TESTING LIBRARY
	server.on("/headers", HTTP_GET, getHeaders);		  // /headers/12  /headers?pool_id=1
	server.on("/parameters", HTTP_GET, getAllParameters); // /parameters?pool_id=1 /parameters/12

	// SD CARD
	server.on("/write_sd", HTTP_POST, writingSD);
	server.on("/write_sd", HTTP_GET, writingSD);
	server.on("/read_sd", HTTP_GET, readingSD);
	server.on("/append_sd", HTTP_POST, appendSD);
	server.on("/directory_sd", HTTP_GET, directorySD);
	server.on("/delete_sd", HTTP_DELETE, deletingSD);
	
	// MEASUREMENT
	server.on("/measurement", HTTP_GET, readingMeasurement); //  /measurement?pool_id=1
	server.on("/measurement", HTTP_DELETE, deleteRequest);

	// DEVICE
	server.on("/device/start", HTTP_GET, startingDevice); // ?pool_id=1
	server.on("/device/configuration", HTTP_GET, getAllConfig);

	// SENSOR
	server.on("/sensor/temp", HTTP_GET, gettingTempSensor);

	// ERROR
	server.onNotFound(notFound);
	server.begin();
	Serial.println("HTTP server started");
}
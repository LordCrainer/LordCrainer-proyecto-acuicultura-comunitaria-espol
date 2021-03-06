void InitServer()
{
	// TEST
	server.on("/", HTTP_GET, homeRequest);
	// server.on("/item", HTTP_GET, getRequest);
	/* 	server.on(
		"/item", HTTP_POST, [](AsyncWebServerRequest *request) {}, NULL, postRequest);
	server.on(
		"/item", HTTP_PUT, [](AsyncWebServerRequest *request) {}, NULL, putRequest);
	server.on(
		"/item", HTTP_PATCH, [](AsyncWebServerRequest *request) {}, NULL, patchRequest);
	server.on("/item", HTTP_DELETE, deleteRequest); */

	// TESTING LIBRARY
	/* 	server.on("/headers", HTTP_GET, getHeaders);		  // /headers/12  /headers?pool_id=1
	server.on("/parameters", HTTP_GET, getAllParameters); // /parameters?pool_id=1 /parameters/12 */

	// SD CARD
	server.on("/write_sd", HTTP_POST, writingSD);
	server.on("/read_sd", HTTP_GET, readingSD);
	server.on("/append_sd", HTTP_POST, appendSD);
	server.on("/directory_sd", HTTP_GET, directorySD);
	// server.on("/delete_sd", HTTP_DELETE, deletingSD);
	server.on("/overwrite_sd", HTTP_POST, overwrittingSD);

	server.on("/delete_sd", HTTP_GET, deletingSD);
	server.on("/overwrite_sd", HTTP_GET, overwrittingSD);
	server.on("/write_sd", HTTP_GET, writingSD);

	// MEASUREMENT
	server.on("/measurement", HTTP_GET, readingMeasurement); //  /measurement?pool_id=1

	// DEVICE
	server.on("/device/start", HTTP_GET, startingDevice); // ?pool_id=1
	server.on("/device/configuration", HTTP_GET, getAllConfig);

	// SENSOR
	server.on("/sensor", HTTP_GET, gettingSensor); // ?name="Temperature"

	// ERROR
	server.onNotFound(notFound);
	server.begin();
	Serial.println("Servidor escuchando en el puerto:\t" + String(port));
}
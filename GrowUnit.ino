/*
Web client

This sketch connects to a website (http://www.google.com)
using an Arduino Wiznet Ethernet shield.

Circuit:
* Ethernet shield attached to pins 10, 11, 12, 13

created 18 Dec 2009
modified 9 Apr 2012
by David A. Mellis

*/

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <SPI.h>
#include "Configuration.h"

static int16_t counter;

// // Enter a MAC address for your controller below.
// // Newer Ethernet shields have a MAC address printed on a sticker on the shield
// byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// byte ip[] = { 192, 168, 1, 88 };
// IPAddress server(192,168,1,102); // Google
//
// LightSensor sensor(1);
//
// // Initialize the Ethernet client library
// // with the IP address and port of the server
// // that you want to connect to (port 80 is default for HTTP):
// EthernetClient client;

void setup()
{
	counter = 0;
	
	for(uint8_t i = 0; i < outputsSize; i++)
	{
		outputs[i]->onCreate();
	}
	
	for(uint8_t i = 0; i < mappingSize; i++)
	{
		mapping[i].sensor->addRule(mapping[i].condition, mapping[i].output);
	}
	
	
	// 	Ethernet.begin(mac, ip);
	//
	// 	// start the Ethernet connection:
	// 	//if (Ethernet.begin(mac, ip) == 0)
	// 	//{
	// 		//Serial.println("Failed to configure Ethernet using DHCP");
	// 		//// no point in carrying on, so do nothing forevermore:
	// 		//for(;;)
	// 		//;
	// 	//}
	// 	// give the Ethernet shield a second to initialize:
	// 	delay(1000);
	// 	Serial.println("connecting...");
	//
	// 	// if you get a connection, report back via serial:
	// 	if (client.connect(server, 80)) {
	// 		Serial.println("connected");
	// 		// Make a HTTP request:
	// 		client.println("GET /growagregator/index.php HTTP/1.0");
	// 		client.println();
	// 	}
	// 	else {
	// 		// if you didn't get a connection to the server:
	// 		Serial.println("connection failed");
	// 	}
}

void loop()
{
	Serial.print("Loop ");
	Serial.println(counter++);

	for(uint8_t i = 0; i < sensorsSize; i++)
	{
		sensors[i]->measure();
	}
	
	for(uint8_t i = 0; i < outputsSize; i++)
	{
		outputs[i]->onMeasured();
	}
	
	Serial.println(analogRead(0));
	
	delay(500);
	// 	// if there are incoming bytes available
	// 	// from the server, read them and print them:
	// 	if (client.available()) {
	// 		char c = client.read();
	// 		Serial.print(c);
	// 	}
	//
	// 	// if the server's disconnected, stop the client:
	// 	if (!client.connected()) {
	// 		Serial.println();
	// 		Serial.println("disconnecting.");
	// 		client.stop();
	//
	// 		// do nothing forevermore:
	// 		for(;;)
	// 		;
	// 	}
}

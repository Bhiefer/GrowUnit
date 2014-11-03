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
#include <Ethernet.h>
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
//

void setup()
{
	counter = 0;
	uint8_t i = 0;
	
	for(i = 0; i < outputsSize; i++)
	{
		outputs[i]->onCreate();
	}
	
	for(i = 0; i < sensorsSize; i++)
	{
		sensors[i]->onCreate();
	}
	
	for(i = 0; i < preconditionsSize; i++)
	{
		preconditions[i].sensor->setPrecondition(preconditions[i].precondition);
	}
	
	for(i = 0; i < mappingSize; i++)
	{
		mapping[i].sensor->addRule(mapping[i].condition, mapping[i].output);
	}
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
	
	delay(1000);
}

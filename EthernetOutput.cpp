/*
* EthernetOutput.cpp
*
* Created: 2.2.2014 12:21:04
* Author: Bhiefer
*/


#include "EthernetOutput.h"
#include <Ethernet.h>

uint8_t EthernetOutput::onReceive( int16_t value, Sensor * sensor )
{
	
}

uint8_t EthernetOutput::onCreate()
{
	Ethernet.begin(DEVICE_MAC, DEVICE_IP);
	
	// give the Ethernet shield a second to initialize:
	delay(1000);
	
}

uint8_t EthernetOutput::onMeasured()
{
	EthernetClient client;
	IPAddress server(SERVER_IP);
	
	Serial.println("connecting...");

	// if you get a connection, report back via serial:
	if (client.connect(server, SERVER_PORT)) 
	{
		Serial.println("connected");
		// Make a HTTP request:
		client.println("GET /growagregator/index.php HTTP/1.0");
		client.println();
	}
	else 
	{
		// if you didn't get a connection to the server:
		Serial.println("connection failed");
	}
}

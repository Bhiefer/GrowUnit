/* 
* SerialOutput.cpp
*
* Created: 25.1.2014 12:29:33
* Author: Bhiefer
*/

#include "SerialViewer.h"
#include "Data.h"

#define SERIAL_SPEED 9600

// default constructor
SerialViewer::SerialViewer(uint8_t id): Viewer(id)
{
} //SerialViewer

uint8_t SerialViewer::onCreate()
{
	// Open serial communications and wait for port to open:
	Serial.begin(SERIAL_SPEED);	
}



void SerialViewer::store( JsonObject& json )
{
	json["type"] = "serial";
	json["speed"] = SERIAL_SPEED;
}

uint8_t SerialViewer::onMeasured()
{
	// temporarily
// 	Data data;
// 	data.store();
}

/* 
* SerialOutput.cpp
*
* Created: 25.1.2014 12:29:33
* Author: Bhiefer
*/

#include "SerialOutput.h"

#define SERIAL_SPEED 9600

// default constructor
SerialOutput::SerialOutput(uint8_t id): Output(id)
{
} //SerialOutput

uint8_t SerialOutput::onCreate()
{
	// Open serial communications and wait for port to open:
	Serial.begin(SERIAL_SPEED);	
}

uint8_t SerialOutput::onReceive( int16_t value, Sensor * sensor )
{
	Serial.print("Pin:");
	Serial.print(sensor->getPin());
	Serial.print(",value:");
	Serial.println(value);	
}

void SerialOutput::store( JsonObject& json )
{
	json["type"] = "serial";
	json["speed"] = SERIAL_SPEED;
}

/* 
* SerialOutput.cpp
*
* Created: 25.1.2014 12:29:33
* Author: Bhiefer
*/

#include "SerialOutput.h"

// default constructor
SerialOutput::SerialOutput()
{
} //SerialOutput

uint8_t SerialOutput::onCreate()
{
	// Open serial communications and wait for port to open:
	Serial.begin(9600);	
}

uint8_t SerialOutput::onReceive( int16_t value, Sensor * sensor )
{
	Serial.print("Pin:");
	Serial.print(sensor->getPin());
	Serial.print(",value:");
	Serial.println(value);	
}

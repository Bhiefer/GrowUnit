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

byte SerialOutput::onCreate()
{
	// Open serial communications and wait for port to open:
//	Serial.begin(9600);	
}

byte SerialOutput::onReceive( int value, Sensor * sensor )
{
	Serial.print("Value:");
	Serial.println(value);	
}

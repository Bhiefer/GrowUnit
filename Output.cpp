/* 
* Output.cpp
*
* Created: 18.1.2014 23:26:52
* Author: Bhiefer
*/

#include "Output.h"

// functions
uint8_t Output::onReceive(int16_t value, Sensor * sensor)
{
	
}

uint8_t Output::onCreate()
{
	
}

uint8_t Output::onMeasured()
{
	
}

void Output::toString(char* string, uint8_t maxLength)
{
	memcpy(string, "Output", 6);
}


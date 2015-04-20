/* 
* Condition.cpp
*
* Created: 24.1.2014 23:34:15
* Author: Bhiefer
*/


#include "Condition.h"

bool Condition::check(int16_t value)
{
	Serial.println("Check");
	return true;
}

void Condition::toString(char* string, uint8_t maxLength)
{
	memcpy(string, "Condition", 9);	
}

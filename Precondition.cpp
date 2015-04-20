/* 
* Precondition.cpp
*
* Created: 2.11.2014 0:58:55
* Author: Bhiefer
*/


#include "Precondition.h"

void Precondition::toString(char* string, uint8_t maxLength)
{
	memcpy(string, "Precondition", 12);
}

bool Precondition::check()
{
	return true;
}

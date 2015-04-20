/* 
* Viewer.cpp
*
* Created: 14.4.2015 21:15:30
* Author: Bhiefer
*/


#include "Viewer.h"

uint8_t Viewer::onCreate()
{
	
}

uint8_t Viewer::onMeasured()
{
	
}

void Viewer::toString(char* string, uint8_t maxLength)
{
	memcpy(string, "Viewer", 6);
}

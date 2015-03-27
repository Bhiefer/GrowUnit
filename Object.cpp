/* 
* Object.cpp
*
* Created: 18.1.2014 11:40:08
* Author: Bhiefer
*/


#include "Object.h"
#include <SPI.h>

// functions
void Object::writeDebug()
{
	Serial.println(toString());
}

bool Object::needStoring()
{
	return false;
}

void Object::store( JsonObject& json )
{
	
}

void Object::restore( JsonObject& json )
{
	
}



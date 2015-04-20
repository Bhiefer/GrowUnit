/* 
* Object.cpp
*
* Created: 18.1.2014 11:40:08
* Author: Bhiefer
*/


#include "Object.h"
#include <SPI.h>

bool Object::needStoring()
{
	return false;
}

void Object::store( JsonObject& json )
{
	json["id"] = getId();
}

void Object::restore( JsonObject& json )
{
	
}



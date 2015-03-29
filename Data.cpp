/* 
* Data.cpp
*
* Created: 22.2.2015 19:20:29
* Author: Bhiefer
*/


#include "Data.h"
#include "Configuration.h"

// default constructor
Data::Data()
{	
} //Data


JsonObject& Data::getPreconditionObject(JsonObject& root)
{
	JsonObject& obj = root.createNestedObject("preconditions");
	for(int i = 0; i < preconditionsSize; i++)
	{
		preconditions[i]->store(obj);
	}
}

JsonObject& Data::getOutputObject(JsonObject& root)
{
	
}

void Data::store()
{
	JsonObject& root = mBuffer.createObject();
	
	getPreconditionObject(root);
	getOutputObject(root);
	
	root.prettyPrintTo(Serial);
	Serial.println();
}

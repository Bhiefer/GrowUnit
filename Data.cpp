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

JsonObject& Data::getSensorObject( JsonObject& root )
{
	JsonArray& a = root.createNestedArray("sensors");
	for(int i = 0; i < sensorsSize; i++)
	{
		JsonObject& obj = mBuffer.createObject();
		sensors[i]->store(obj);
		
		a.add(obj);
	}
}

JsonObject& Data::getOutputObject(JsonObject& root)
{
	JsonArray& a = root.createNestedArray("outputs");
	for(int i = 0; i < outputsSize; i++)
	{
		JsonObject& obj = mBuffer.createObject();
		outputs[i]->store(obj);
		
		a.add(obj);
	}
}

void Data::store()
{
	JsonObject& root = mBuffer.createObject();
	
	getSensorObject(root);
	//getOutputObject(root);
	
	root.prettyPrintTo(Serial);
	Serial.println();
}



/*
* Object.h
*
* Created: 18.1.2014 11:40:09
* Author: Bhiefer
*/


#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <ArduinoJson.h>
#include "Arduino.h"

class Object 
{
	uint8_t mId;
	
	//functions
	public:
	Object(uint8_t id)
	{
		mId = id;
	}
	
	virtual void toString(char* string, uint8_t maxLength)=0;
//	virtual void writeDebug();
	virtual bool needStoring();
	virtual void store(JsonObject& json);
	virtual void restore(JsonObject& json);
	
	virtual bool isUsingEeprom();
	virtual uint8_t storeToEeprom(int16_t address);
	virtual uint8_t restoreFromEeprom(int16_t address);
	
	virtual uint8_t getId()
	{
		return mId;
	}
};

#endif //__OBJECT_H__

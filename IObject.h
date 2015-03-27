/* 
* Object.h
*
* Created: 18.1.2014 11:38:02
* Author: Bhiefer
*/


#ifndef __IOBJECT_H__
#define __IOBJECT_H__

#include <ArduinoJson.h>
#include "Arduino.h"


// class JsonObject;

class IObject
{
//functions
public:
	virtual ~IObject(){}
	virtual void writeDebug() = 0;
	virtual char * toString() = 0;
	virtual bool needStoring() = 0;
	virtual void store(JsonObject& json) = 0;
	virtual void restore(JsonObject& json) = 0;

}; //Object

#endif //__IOBJECT_H__

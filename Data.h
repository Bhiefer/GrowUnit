/* 
* Data.h
*
* Created: 22.2.2015 19:20:29
* Author: Bhiefer
*/


#ifndef __DATA_H__
#define __DATA_H__

#include <ArduinoJson.h>
#include <JsonGenerator.h>



class Data
{
//variables
private:
	StaticJsonBuffer<150> mBuffer;	

//functions
public:
	Data();
	
	JsonObject& getPreconditionObject(JsonObject& root);
	JsonObject& getSensorObject(JsonObject& root);
	JsonObject& getOutputObject(JsonObject& root);
	
	void store();

}; //Data

#endif //__DATA_H__

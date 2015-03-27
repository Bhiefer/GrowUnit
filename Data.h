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
public:
protected:
private:
	StaticJsonBuffer<200> mBuffer;
  
  JsonObject* mPrecondition;
  JsonObject* mOutput;

//functions
public:
	Data();
	
	JsonObject& getPreconditionObject();
	JsonObject& getOutputObject();
	
	void store();
protected:
private:

}; //Data

#endif //__DATA_H__
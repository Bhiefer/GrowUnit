/* 
* SerialOutput.h
*
* Created: 25.1.2014 12:29:33
* Author: Bhiefer
*/


#ifndef __SERIALOUTPUT_H__
#define __SERIALOUTPUT_H__

#include "Viewer.h"

class SerialViewer : public Viewer
{
//variables
public:
protected:
private:

//functions
public:
	SerialViewer(uint8_t id);
	
	virtual uint8_t onCreate();
	virtual uint8_t onMeasured();
	
	virtual void store(JsonObject& json);
protected:
private:

}; //SerialOutput

#endif //__SERIALOUTPUT_H__

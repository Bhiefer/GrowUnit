/* 
* SerialOutput.h
*
* Created: 25.1.2014 12:29:33
* Author: Bhiefer
*/


#ifndef __SERIALOUTPUT_H__
#define __SERIALOUTPUT_H__

#include "Output.h"

class SerialOutput : public Output
{
//variables
public:
protected:
private:

//functions
public:
	SerialOutput();
	
	virtual uint8_t onReceive(int16_t value, Sensor * sensor);
	
	virtual uint8_t onCreate();
protected:
private:

}; //SerialOutput

#endif //__SERIALOUTPUT_H__

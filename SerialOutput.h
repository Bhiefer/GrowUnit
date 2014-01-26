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
	
	virtual byte onReceive(int value, Sensor * sensor);
	
	virtual byte onCreate();
protected:
private:

}; //SerialOutput

#endif //__SERIALOUTPUT_H__

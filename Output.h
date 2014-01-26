/*
* Output.h
*
* Created: 18.1.2014 23:26:52
* Author: Bhiefer
*/


#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include "IOutput.h"
#include "Object.h"
#include "Sensor.h"

class Output : public IOutput, public Object
{
	
	//functions
	public:
	virtual byte onReceive(int value, Sensor * sensor) = 0;
	virtual byte onCreate();
	virtual byte onMeasured();
	
	virtual char * toString();

}; //Output

#endif //__OUTPUT_H__

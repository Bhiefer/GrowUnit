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

class Output : public Object
{
	
	//functions
	public:
	Output(uint8_t id): Object(id)
	{
		
	}
	
	virtual uint8_t onReceive(int16_t value, Sensor * sensor) = 0;
	virtual uint8_t onCreate();
	virtual uint8_t onMeasured();
	virtual int16_t getStateValue()
	{
		return 0;
	}
	
	virtual char * toString();

}; //Output

#endif //__OUTPUT_H__

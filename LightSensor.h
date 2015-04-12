/* 
* LightSensor.h
*
* Created: 24.1.2014 23:20:54
* Author: Bhiefer
*/


#ifndef __LIGHTSENSOR_H__
#define __LIGHTSENSOR_H__

#include "AnalogSensor.h"

class LightSensor : public AnalogSensor
{
//variables
public:
protected:
private:

//functions
public:
	LightSensor(uint8_t id, uint8_t pin) : AnalogSensor(id, pin)
	{
		
	}
protected:
private:
	

}; //LightSensor

#endif //__LIGHTSENSOR_H__

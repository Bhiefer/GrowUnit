/*
* AnalogSensor.h
*
* Created: 25.1.2014 0:53:20
* Author: Bhiefer
*/


#ifndef __ANALOGSENSOR_H__
#define __ANALOGSENSOR_H__

#include "Sensor.h"

class AnalogSensor : public Sensor
{
	//variables
	public:
	protected:
	uint8_t mPin;
	private:

	//functions
	public:
	AnalogSensor(uint8_t id, uint8_t pin, Precondition* precondition, ValueProcessor* valueProcessor) : Sensor(id, pin, precondition, valueProcessor)
	{}
	protected:
	virtual int16_t measureValue();
	virtual uint8_t onCreate();
	private:

}; //AnalogSensor

#endif //__ANALOGSENSOR_H__

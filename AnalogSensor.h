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
	byte mPin;
	private:

	//functions
	public:
	AnalogSensor(byte pin) : Sensor(pin)
	{}
	protected:
	virtual int measureValue();
	private:

}; //AnalogSensor

#endif //__ANALOGSENSOR_H__

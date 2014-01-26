/*
* Output.h
*
* Created: 18.1.2014 11:31:57
* Author: Bhiefer
*/


#ifndef __IOUTPUT_H__
#define __IOUTPUT_H__

#include "Arduino.h"
#include "Sensor.h"

class Sensor;

class IOutput
{
	//functions
	public:
	virtual uint8_t onReceive(int16_t value, Sensor * sensor) = 0;
	virtual uint8_t onCreate() = 0;
	virtual uint8_t onMeasured() = 0;
};

#endif //__IOUTPUT_H__

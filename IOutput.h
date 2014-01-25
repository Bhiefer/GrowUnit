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
	virtual byte onReceive(int value, Sensor * sensor) = 0;
	virtual void onCreate() = 0;
	virtual void onMeasured() = 0;
};

#endif //__IOUTPUT_H__

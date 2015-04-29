/*
* DigitalSensor.h
*
* Created: 26.1.2014 22:01:11
* Author: Bhiefer
*/


#ifndef __DIGITALSENSOR_H__
#define __DIGITALSENSOR_H__

#include "Sensor.h"

class DigitalSensor : public Sensor
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
	DigitalSensor(uint8_t id, uint8_t pin, Precondition* precondition, ValueProcessor* valueProcessor) : Sensor(id, pin, precondition, valueProcessor) {};
	protected:
	virtual int16_t measureValue();
	virtual uint8_t onCreate();
	private:

}; //DigitalSensor

#endif //__DIGITALSENSOR_H__

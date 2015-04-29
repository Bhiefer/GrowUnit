/* 
* NoSensor.h
*
* Created: 29.4.2015 23:27:04
* Author: Bhiefer
*/


#ifndef __NOSENSOR_H__
#define __NOSENSOR_H__

#include "Sensor.h"

class NoSensor : public Sensor
{
//variables
public:
protected:
private:

//functions
public:
	NoSensor(uint8_t id): Sensor(id, -1, NULL, NULL)
	{
	}
	
	virtual int16_t measureValue()
	{
		return 0;
	}

}; //NoSensor

#endif //__NOSENSOR_H__

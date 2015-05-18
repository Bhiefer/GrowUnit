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
	NoSensor(uint8_t id, Precondition* precondition): Sensor(id, -1, precondition, NULL)
	{
	}
	
	virtual int16_t measureValue()
	{
		return 0;
	}
	
	void toString( char* string, uint8_t maxLength )
	{
		String str = String("Bez senzoru");
		memcpy(string, str.c_str(), min(str.length(), maxLength));
	}

}; //NoSensor

#endif //__NOSENSOR_H__

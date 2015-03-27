/* 
* DhtSensor.h
*
* Created: 12.3.2015 10:36:34
* Author: Bhiefer
*/


#ifndef __DHTSENSOR_H__
#define __DHTSENSOR_H__

#include "Sensor.h"
#include "DHT.h"

class DhtSensor: public Sensor
{
//variables
public:
protected:
	dht mDht;
	bool log;
private:
	

//functions
public:
	DhtSensor(uint8_t pin) : Sensor(pin)
	{
		log = true;
	}
protected:
private:
	virtual int16_t measureValue();
	virtual int16_t extractDhtValue() = 0;

}; //DhtSensor

#endif //__DHTSENSOR_H__

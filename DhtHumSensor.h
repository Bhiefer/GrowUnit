/* 
* DhtHumSensor.h
*
* Created: 12.3.2015 11:45:12
* Author: Bhiefer
*/


#ifndef __DHTHUMSENSOR_H__
#define __DHTHUMSENSOR_H__

#include "DhtSensor.h"

class DhtHumSensor : public DhtSensor
{
//variables
public:
protected:
private:

//functions
public:
	DhtHumSensor(uint8_t id, uint8_t pin, Precondition* precondition, ValueProcessor* valueProcessor) : DhtSensor(id, pin, precondition, valueProcessor)
	{
		
	}
	
	virtual void store(JsonObject& json);
protected:
private:
	virtual int16_t extractDhtValue();

}; //DhtHumSensor

#endif //__DHTHUMSENSOR_H__

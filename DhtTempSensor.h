/* 
* DhtTempSensor.h
*
* Created: 12.3.2015 11:50:09
* Author: Bhiefer
*/


#ifndef __DHTTEMPSENSOR_H__
#define __DHTTEMPSENSOR_H__

#include "DhtSensor.h"

class DhtTempSensor : public DhtSensor
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
	DhtTempSensor(uint8_t id, uint8_t pin) : DhtSensor(id, pin)
	{
		
	}
	protected:
	private:
	virtual int16_t extractDhtValue();

};//DhtTempSensor

#endif //__DHTTEMPSENSOR_H__

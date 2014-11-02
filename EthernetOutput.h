/* 
* EthernetOutput.h
*
* Created: 2.2.2014 12:21:04
* Author: Bhiefer
*/


#ifndef __ETHERNETOUTPUT_H__
#define __ETHERNETOUTPUT_H__

#include "Output.h"
#include "Constants.h"

class EthernetOutput : public Output
{
//variables
public:
protected:
	Measurement mMeasurements[MAX_MEASUREMENTS_COUNT];
	uint8_t mMeasurementsCnt;
private:

//functions
public:	
	EthernetOutput()
	{
		mMeasurementsCnt = 0;
	}

	virtual uint8_t onReceive(int16_t value, Sensor * sensor);
	virtual uint8_t onCreate();
	virtual uint8_t onMeasured();


}; //EthernetOutput

#endif //__ETHERNETOUTPUT_H__

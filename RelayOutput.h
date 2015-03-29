/* 
* RelayOutput.h
*
* Created: 12.3.2015 10:03:17
* Author: Bhiefer
*/


#ifndef __RELAYOUTPUT_H__
#define __RELAYOUTPUT_H__

#include "Output.h"

class RelayOutput: public Output
{
//variables
public:
	uint8_t mPin;
	uint16_t mLastOnTime;
	uint16_t mOnTime;
	bool mTurnOn;
	bool mIsTurnedOn; 
protected:
private:

//functions
public:
	RelayOutput(uint8_t pin, uint16_t onTime);
	
	virtual uint8_t onCreate();
	virtual uint8_t onReceive(int16_t value, Sensor * sensor);
	virtual uint8_t onMeasured();
	
	virtual void store(JsonObject& json);
protected:
private:

}; //RelayOutput

#endif //__RELAYOUTPUT_H__

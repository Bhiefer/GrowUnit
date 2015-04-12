/* 
* RelayOutput.cpp
*
* Created: 12.3.2015 10:03:17
* Author: Bhiefer
*/


#include "RelayOutput.h"
#include "Timer.h"

 RelayOutput::RelayOutput(uint8_t id, uint8_t pin, uint16_t onTime ) : Output(id)
 {
	mPin = pin;
	mOnTime = onTime;
	mIsTurnedOn = false;
	mLastOnTime = 0;
	mTurnOn = false;
	mLastOnTime = 0;
 }

uint8_t RelayOutput::onReceive(int16_t value, Sensor * sensor)
{
//	Serial.println("Received");
	mTurnOn = true;
	
	return RC_OK;
}

uint8_t RelayOutput::onMeasured()
{
//	Serial.println("on measured");
	if(mIsTurnedOn)
	{
		if(timer.checkElapsed(mLastOnTime, mOnTime))
		{
			Serial.println("Turn off");
			digitalWrite(mPin, HIGH);
			
			mIsTurnedOn = false;			
		}
	}
	else
	{
		if(mTurnOn)
		{
			Serial.println("Turn on");
			digitalWrite(mPin, LOW);
			
			mLastOnTime = timer.current();
			mIsTurnedOn = true;
		}
	}
	
	mTurnOn = false;
	
	return RC_OK;
}

uint8_t RelayOutput::onCreate()
{
	pinMode(mPin, OUTPUT);
}

void RelayOutput::store( JsonObject& json )
{
	json["type"] = "relay";
	json["pin"] = mPin;
	json["state"] = mIsTurnedOn ? "on" : "off";
}





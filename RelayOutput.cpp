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
// 		Serial.print("Last:");
// 		Serial.println(mLastOnTime);
// 		Serial.print("Current:");
// 		Serial.println(timer.current());
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
	digitalWrite(mPin, HIGH);
}

void RelayOutput::store( JsonObject& json )
{
	json["type"] = "relay";
	json["pin"] = mPin;
	json["state"] = mIsTurnedOn ? "on" : "off";
}

int16_t RelayOutput::getStateValue()
{
	return mIsTurnedOn ? 256 : 0;
}

void RelayOutput::toString( char* string, uint8_t maxLength )
{
	String str = new String("Relay:") + mIsTurnedOn ?"ON":"OFF";
	memcpy(string, str.c_str(), min(str.length(), maxLength));
}





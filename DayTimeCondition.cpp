/* 
* DayTimeCondition.cpp
*
* Created: 29.4.2015 22:37:33
* Author: Bhiefer
*/


#include "DayTimeCondition.h"

#include "Timer.h"

bool DayTimeCondition::check( int16_t value )
{
	uint8_t h = hour(timer.currentLocal());
	
	if(mFrom < mTo)
	{
		
// 		Serial.println("qqq");
// 		Serial.println(mFrom);
// 		Serial.println(mTo);
// 		Serial.println(h);
		
		return h >= mFrom && h < mTo; 
	}
	else if(mFrom == mTo)
	{
// 		Serial.println("aaa");
// 		Serial.println(mFrom);
// 		Serial.println(h);
		return h == mFrom;
	}
	else
	{
// 		Serial.println("ttt");
// 		Serial.println(mFrom);
// 		Serial.println(mTo);
// 		Serial.println(h);
		return h > mFrom || h < mTo;
	}
}

void DayTimeCondition::toString( char* string, uint8_t maxLength )
{
	String str = String(mFrom);
	str += ":00 - ";
	str += mTo;
	str += ":00";
	
	memcpy(string, str.c_str(), min(str.length(), maxLength));
}

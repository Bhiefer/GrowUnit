/* 
* HourCondition.cpp
*
* Created: 30.4.2015 9:24:59
* Author: Bhiefer
*/


#include "HourCondition.h"

#include "Timer.h"

bool HourCondition::check( int16_t value )
{
	uint8_t h = hour(timer.currentLocal());
	
	if(mLastHour != mHour && h == mHour)
	{
		mLastHour = h;
		return true;
	}
	else
	{
		mLastHour = h;
		return false;
	}
}

void HourCondition::toString( char* string, uint8_t maxLength )
{
	String str = String(mHour);
	str += ":00";
	
	memcpy(string, str.c_str(), min(str.length(), maxLength));
}

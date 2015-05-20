/* 
* DayTimeCondition.cpp
*
* Created: 29.4.2015 22:37:33
* Author: Bhiefer
*/


#include "DayTimeCondition.h"
#include "Constants.h"

#include "Timer.h"

const int sunHours[12][2] =
{
	{8,		16},
	{7,		17},
	{6,		18},
	{5,		19},
	{4,		19},
	{4,		20},
	{4,		20},
	{5,		19},
	{6,		18},
	{6,		17},
	{7,		16},
	{8,		16},
};

bool DayTimeCondition::check( int16_t value )
{
	time_t t = timer.current() + TIMEZONE_SHIFT_SECONDS;
	uint8_t h = hour(t);
	uint8_t m = month(t) - 1;
	
	uint8_t from = sunHours[m][0] + mFromOffset;
	uint8_t to = sunHours[m][1] + mToOffset;
	
	if(from < to)
	{
		
// 		Serial.println("qqq");
// 		Serial.println(mFrom);
// 		Serial.println(mTo);
// 		Serial.println(h);
		
		return h >= from && h < to; 
	}
	else if(from == to)
	{
// 		Serial.println("aaa");
// 		Serial.println(mFrom);
// 		Serial.println(h);
		return h == from;
	}
	else
	{
// 		Serial.println("ttt");
// 		Serial.println(mFrom);
// 		Serial.println(mTo);
// 		Serial.println(h);
		return h > from || h < to;
	}
}

void DayTimeCondition::toString( char* string, uint8_t maxLength )
{
	uint8_t m = month(timer.current() + TIMEZONE_SHIFT_SECONDS) - 1;
	uint8_t s = timer.isSummerTime();
	
	String str = String((sunHours[m][0] + mFromOffset + s));
	str += ":00 - ";
	str += (sunHours[m][1] + mToOffset + s);
	str += ":00";
	
	memcpy(string, str.c_str(), min(str.length(), maxLength));
}



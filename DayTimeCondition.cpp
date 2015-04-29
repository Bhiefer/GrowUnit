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
		return h >= mFrom && h < mTo; 
	}
	else if(mFrom == mTo)
	{
		return h == mFrom;
	}
	else
	{
		return h > mFrom || h < mTo;
	}
}

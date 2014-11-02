/* 
* TimePrecondition.cpp
*
* Created: 2.11.2014 1:02:27
* Author: Bhiefer
*/

#include "TimePrecondition.h"
#include "Timer.h"

// default constructor
TimePrecondition::TimePrecondition(uint16_t period)
{
	mPeriod = period;
} //TimePrecondition

bool TimePrecondition::check()
{
	if(timer.checkElapsed(mLastTime, mPeriod))
	{
		mLastTime = timer.current();
		return true;
	}		
	else
	{
		return false;
	}
}

char * TimePrecondition::toString()
{
	return "TimePrecondition";
}

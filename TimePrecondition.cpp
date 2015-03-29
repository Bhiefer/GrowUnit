/* 
* TimePrecondition.cpp
*
* Created: 2.11.2014 1:02:27
* Author: Bhiefer
*/

#include "TimePrecondition.h"
#include "Timer.h"
#include <Json>

// default constructor
TimePrecondition::TimePrecondition(time_t period)
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

void TimePrecondition::store( JsonObject& json )
{
	JsonObject& time = json.createNestedObject("timePrecondition");
	time["last"] = (long)mLastTime;	
}

void TimePrecondition::restore( JsonObject& json )
{
	
}

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
TimePrecondition::TimePrecondition(uint8_t id, time_t period): Precondition(id)
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
	Precondition::store(json);
	
	json["type"] = "time";
	json["last"] = static_cast<long>(mLastTime);
	json["period"] = static_cast<long>(mPeriod);	
}

void TimePrecondition::restore( JsonObject& json )
{
	
}

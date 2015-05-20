/* 
* Timer.cpp
*
* Created: 2.11.2014 19:24:03
* Author: Bhiefer
*/


#include "Timer.h"

#include "Constants.h"

Timer timer;

// default constructor
Timer::Timer()
{
	// SET CLOCK
	 
} //Timer

time_t Timer::current()
{
	return mRtc.get();
}

time_t Timer::currentLocal()
{
	return  mRtc.get() + TIMEZONE_SHIFT_SECONDS + isSummerTime()*ONE_HOUR;
}

bool Timer::checkElapsed( time_t last, time_t period )
{
//	uint16_t elapsed = current() - last;
// 	uint16_t elapsed = mRtc.get() - last;
// 	Serial.println(elapsed);
// 	return elapsed > period;
	
	return current() - last > period;	
}

char * Timer::toString()
{
	return "Timer";	
}

float Timer::getTemp()
{
	return mRtc.getTemp();
}

uint8_t Timer::isSummerTime()
{
	time_t t = mRtc.get() + TIMEZONE_SHIFT_SECONDS;
	
	uint8_t m = month(t);
	
	if(m > 10 || m < 3)
	{
		return 0;
	}
	else if(m > 3 && m < 10)
	{
		return 1;
	}
	else
	{
		uint8_t w = weekday(t);
		
		// otestovat posledni nedeli v mesici
		if(day(t) + 7 - w < 31)
		{
			return m == 3 ? 0 : 1;
		}
		else
		{
			// nedele - otestovat cas
			if(w == 1)
			{
				if(m == 3)
				{
					// brezen po druhe hodine
					return ( hour(t) > 2 ? 1 : 0);
				}
				else
				{
					// rijen po treti hodine
					return ( hour(t) > 2 ? 0 : 1);
					
				}
			}
			else
			{
				return m == 3 ? 1 : 0;
			}
		}
	}
}

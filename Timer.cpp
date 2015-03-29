/* 
* Timer.cpp
*
* Created: 2.11.2014 19:24:03
* Author: Bhiefer
*/


#include "Timer.h"

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

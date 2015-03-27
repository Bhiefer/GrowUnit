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
	//	mRtc.set(1424617980);
} //Timer

// default destructor
Timer::~Timer()
{
} //~Timer

uint16_t Timer::current()
{
	return mRtc.get();
}

bool Timer::checkElapsed( uint16_t last, uint16_t period )
{
//	uint16_t elapsed = current() - last;
//	Serial.println(elapsed);
//	return elapsed > period;
	
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

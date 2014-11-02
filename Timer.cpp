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
} //Timer

// default destructor
Timer::~Timer()
{
} //~Timer

uint16_t Timer::current()
{
	return millis() / 1000;
}

bool Timer::checkElapsed( uint16_t last, uint16_t period )
{
	return current() - last > period;	
}

char * Timer::toString()
{
	return "Timer";	
}

/* 
* Timer.h
*
* Created: 2.11.2014 19:24:03
* Author: Bhiefer
*/


#ifndef __TIMER_H__
#define __TIMER_H__

#include "Object.h"

class Timer : public Object
{
//variables
public:
protected:
private:

//functions
public:
	Timer();
	~Timer();
	
	uint16_t current();
	bool checkElapsed(uint16_t last, uint16_t period);
	
	virtual char * toString();
protected:
private:

}; //Timer

extern Timer timer;

#endif //__TIMER_H__

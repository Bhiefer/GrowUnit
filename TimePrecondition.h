/* 
* TimePrecondition.h
*
* Created: 2.11.2014 1:02:27
* Author: Bhiefer
*/


#ifndef __TIMEPRECONDITION_H__
#define __TIMEPRECONDITION_H__

#include "Precondition.h"
#include <DS3231RTC.h>

class TimePrecondition : public Precondition
{
//variables
public:
protected:
private:
  time_t mPeriod;
  time_t mLastTime;

//functions
public:
	TimePrecondition(time_t period);
	
	virtual bool check();
	
	virtual char * toString();
	
	virtual void store(JsonObject& json);
	virtual void restore(JsonObject& json);
	
protected:
private:

}; //TimePrecondition

#endif //__TIMEPRECONDITION_H__

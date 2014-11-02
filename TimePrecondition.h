/* 
* TimePrecondition.h
*
* Created: 2.11.2014 1:02:27
* Author: Bhiefer
*/


#ifndef __TIMEPRECONDITION_H__
#define __TIMEPRECONDITION_H__

#include "Precondition.h"

class TimePrecondition : public Precondition
{
//variables
public:
protected:
private:
  uint16_t mPeriod;
  uint16_t mLastTime;

//functions
public:
	TimePrecondition(uint16_t period);
	
	virtual bool check();
	
	virtual char * toString();
protected:
private:

}; //TimePrecondition

#endif //__TIMEPRECONDITION_H__

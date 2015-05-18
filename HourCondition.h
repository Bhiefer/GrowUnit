/* 
* HourCondition.h
*
* Created: 30.4.2015 9:24:59
* Author: Bhiefer
*/


#ifndef __HOURCONDITION_H__
#define __HOURCONDITION_H__

#include "Condition.h"

class HourCondition : public Condition
{
	//variables
	private:
	uint8_t mHour;
	uint8_t mLastHour;

	//functions
	public:
	HourCondition(uint8_t id, uint8_t hour): Condition(id)
	{
		mHour = hour;
		mLastHour = 99;
	}

	virtual bool check(int16_t value);
	
	virtual void toString(char* string, uint8_t maxLength);

}; //HourCondition

#endif //__HOURCONDITION_H__

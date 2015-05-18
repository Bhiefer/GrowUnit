/* 
* DayTimeCondition.h
*
* Created: 29.4.2015 22:37:33
* Author: Bhiefer
*/


#ifndef __DAYTIMECONDITION_H__
#define __DAYTIMECONDITION_H__

#include "Condition.h"

class DayTimeCondition : public Condition
{
//variables
private:
	uint8_t mFrom;
	uint8_t mTo;

//functions
public:
	DayTimeCondition(uint8_t id, uint8_t fromHour, uint8_t toHour): Condition(id)
	{
		mFrom = fromHour;
		mTo = toHour;
	}

	virtual bool check(int16_t value);
	
	virtual void toString(char* string, uint8_t maxLength);

}; //DayTimeCondition

#endif //__DAYTIMECONDITION_H__

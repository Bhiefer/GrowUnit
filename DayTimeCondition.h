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
	int8_t mFromOffset;
	int8_t mToOffset;

//functions
public:
	DayTimeCondition(uint8_t id, int8_t fromOffset, int8_t toOffset): Condition(id)
	{
		mFromOffset = fromOffset;
		mToOffset = toOffset;
	}

	virtual bool check(int16_t value);
	
	virtual void toString(char* string, uint8_t maxLength);
}; //DayTimeCondition

#endif //__DAYTIMECONDITION_H__

/*
* Condition.h
*
* Created: 24.1.2014 23:34:16
* Author: Bhiefer
*/


#ifndef __CONDITION_H__
#define __CONDITION_H__

#include "ICondition.h"
#include "Object.h"

class Condition : public Object
{
	uint8_t mByte;
	//functions
	public:
	Condition(uint8_t id): Object(id) 
	{ 
		mByte = 0;
	}
	
	virtual bool check(int16_t value);
	
	virtual void toString(char* string, uint8_t maxLength);
}; //Condition

#endif //__CONDITION_H__

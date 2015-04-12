/* 
* LessThanCondition.h
*
* Created: 12.3.2015 12:34:08
* Author: Bhiefer
*/


#ifndef __LESSTHANCONDITION_H__
#define __LESSTHANCONDITION_H__

#include "Condition.h"

class LessThanCondition : public Condition
{
//variables
public:
protected:
private:
	int16_t mTreshold;

//functions
public:
	LessThanCondition(uint8_t id, int16_t treshold): Condition(id)
	{
		mTreshold = treshold;
	}
	
	virtual bool check(int16_t value);
protected:
private:

}; //LessThanCondition

#endif //__LESSTHANCONDITION_H__

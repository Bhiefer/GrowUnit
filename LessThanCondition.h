/* 
* LessThanCondition.h
*
* Created: 12.3.2015 12:34:08
* Author: Bhiefer
*/


#ifndef __LESSTHANCONDITION_H__
#define __LESSTHANCONDITION_H__

#include "Condition.h"
#include "Time.h"

class LessThanCondition : public Condition
{
//variables
private:
	int16_t mTreshold;
	time_t mLastTime;
	boolean mAdjusted;

//functions
public:
	LessThanCondition(uint8_t id, int16_t treshold): Condition(id)
	{
		mTreshold = treshold;
		mAdjusted = false;
	}
	
	virtual bool check(int16_t value);

}; //LessThanCondition

#endif //__LESSTHANCONDITION_H__

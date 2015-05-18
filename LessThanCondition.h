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
	
	virtual void store(JsonObject& json);
	
	virtual bool check(int16_t value);
	
	virtual bool isUsingEeprom() { return true; }
	virtual uint8_t storeToEeprom(int16_t address);
	virtual uint8_t restoreFromEeprom(int16_t address);
	
	virtual void toString(char* string, uint8_t maxLength);

}; //LessThanCondition

#endif //__LESSTHANCONDITION_H__

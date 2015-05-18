/* 
* AndCondition.h
*
* Created: 3.11.2014 9:06:35
* Author: Bhiefer
*/


#ifndef __ANDCONDITION_H__
#define __ANDCONDITION_H__

#include "Condition.h"

class AndCondition : public Condition
{
//variables
public:
protected:
private:
	Condition * mFirst;
	Condition * mSecond;

//functions
public:
	AndCondition(uint8_t id, Condition * first, Condition * second): Condition(id)
	{
		mFirst = first;
		mSecond = second;
	}
	
	virtual bool check(int16_t value);
	
	virtual void store(JsonObject& json);
	
	virtual bool isUsingEeprom();
	virtual uint8_t storeToEeprom(int16_t address);
	virtual uint8_t restoreFromEeprom(int16_t address);
	
	virtual void toString(char* string, uint8_t maxLength);

}; //AndCondition

#endif //__ANDCONDITION_H__

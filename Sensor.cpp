/* 
* Sensor.cpp
*
* Created: 18.1.2014 11:36:04
* Author: Bhiefer
*/


#include "Sensor.h"
#include "Output.h"

// functions
byte Sensor::measure()//virtual
{
	for(int i = 0; i < mRulesCnt; i++)
	{
		Rule r = mRules[i];
		int value = measureValue();
		
		if(r.condition->check(value))
		{
			r.output->onReceive(value, this);
		}
	}
}

byte Sensor::addRule(Rule rule)
{
	if(isRulesFull())
	{
		return RC_OUT_OF_MEMORY_INSTANCE_FULL;
	}
	
	mRules[mRulesCnt] = rule;
	mRulesCnt++;
}

byte Sensor::addRule(Condition * condition, Output * output)
{
	if(isRulesFull())
	{
		return RC_OUT_OF_MEMORY_INSTANCE_FULL;
	}
	
	Rule rule = {condition, output};
	
	mRules[mRulesCnt] = rule;
	mRulesCnt++;
}

bool Sensor::isRulesFull()
{
	return mRulesCnt >= MAX_RULES_COUNT;
}

char * Sensor::toString()
{
	return "Abstract sensor";
}


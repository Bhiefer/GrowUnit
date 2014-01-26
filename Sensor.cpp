/*
* Sensor.cpp
*
* Created: 18.1.2014 11:36:04
* Author: Bhiefer
*/


#include "Sensor.h"
#include "Output.h"
#include "AlwaysCondition.h"
#include "MemoryFree.h"

// functions
byte Sensor::measure()//virtual
{
	Serial.println("measure");
	for(int i = 0; i < mRulesCnt; i++)
	{
		Rule r = mRules[i];
		int value = measureValue();
		
		//		Serial.println(value);
		
// 		Condition * c = r.condition;
// 		
// 		(*c).check(0);

		Condition c;
		c.toString();
		
//		r.condition->toString();

		//	if(r.condition->check(value))
		
		//if(c->check(0))
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


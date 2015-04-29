/*
* Sensor.cpp
*
* Created: 18.1.2014 11:36:04
* Author: Bhiefer
*/


#include "Sensor.h"
#include "Output.h"
#include "Condition.h"

// functions
uint8_t Sensor::measure()//virtual
{
	if(mPrecondition != NULL && !mPrecondition->check())
	{
		return RC_PRECONDITION_NOT_MET;
	}
	
	for(uint8_t i = 0; i < mRulesCnt; i++)
	{
		Rule r = mRules[i];
		
		if(mValueProcessor != NULL)
		{
			mMeasuredValue = mValueProcessor->process(measureValue());	
		}
		else
		{
			mMeasuredValue = measureValue();
		}
		
		if(r.condition->check(mMeasuredValue))
		{
			r.output->onReceive(mMeasuredValue, this);
		}
	}
}

uint8_t Sensor::addRule(Rule rule)
{
	if(isRulesFull())
	{
		return RC_OUT_OF_MEMORY_INSTANCE_FULL;
	}
	
	mRules[mRulesCnt] = rule;
	mRulesCnt++;
}

uint8_t Sensor::addRule(Condition * condition, Output * output)
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

void Sensor::toString( char* string, uint8_t maxLength )
{
	String str = String("Sensor\nPin:");
	str += mPin;
	str += ", value:";
	str += mMeasuredValue;
	memcpy(string, str.c_str(), min(str.length(), maxLength));
}

uint8_t Sensor::onCreate()
{
}

// uint8_t Sensor::setPrecondition( Precondition * precondition )
// {
// 	mPrecondition = precondition;
// }

void Sensor::store( JsonObject& json )
{
	Object::store(json);
	json["pin"] = mPin;
	json["value"] = mMeasuredValue;
	
	if(mPrecondition != NULL)
	{
		mPrecondition->store(json.createNestedObject("precondition"));		
	}
}

void Sensor::restore( JsonObject& json )
{
	
}


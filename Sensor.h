/*
* AbsSensor.h
*
* Created: 18.1.2014 11:36:05
* Author: Bhiefer
*/


#ifndef __SENSOR_H__
#define __SENSOR_H__

#include "Object.h"
#include "Constants.h"
#include "Condition.h"
#include "Precondition.h"
#include "ValueProcessor.h"
#include "Structs.h"

class Sensor :  public Object
{
	protected:
		Rule mRules[MAX_RULES_COUNT];
		uint8_t mRulesCnt;
		
		Precondition* mPrecondition;
		ValueProcessor* mValueProcessor;
		
		uint8_t mPin;
		
		int16_t mMeasuredValue;
	
	//functions
	private:
		bool isRulesFull();
	
	protected:	
		virtual int16_t measureValue() = 0;
	
	public:
		Sensor(uint8_t id, uint8_t pin, Precondition* precondition, ValueProcessor* valueProcessor) : Object(id)
		{			
			mPin = pin;
			mRulesCnt = 0;
			mPrecondition = precondition;
			mValueProcessor = valueProcessor;
		}

		virtual uint8_t addRule(Condition * condition, Output * output);
		virtual uint8_t addRule(Rule rule);
		Rule* getRules()
		{
			return mRules;	
		}
		
		uint8_t getRulesCnt()
		{
			return mRulesCnt;
		}
		
		//virtual uint8_t setPrecondition(Precondition * precondition);
		int16_t getMeasuredValue()
		{
			return mMeasuredValue;
		}
		
		uint8_t getPin()
		{
			return mPin;
		}
		
		Precondition* getPrecondition()
		{
			return mPrecondition;
		}
		
		virtual uint8_t measure();
		virtual uint8_t onCreate();
		
		
		virtual void store(JsonObject& json);
		virtual void restore(JsonObject& json);
		
		virtual void toString(char* string, uint8_t maxLength);
};

#endif //__SENSOR_H__

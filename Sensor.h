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
#include "Structs.h"

class Sensor :  public Object
{
	protected:
		Rule mRules[MAX_RULES_COUNT];
		uint8_t mRulesCnt;
		
		Precondition * mPrecondition;
		
		uint8_t mPin;
		
		
		int16_t mMeasuredValue;
	
	//functions
	private:
		bool isRulesFull();
	
		protected:
		virtual char * toString();
		virtual int16_t measureValue() = 0;
	
	public:
		Sensor(uint8_t id, uint8_t pin) : Object(id)
		{			
			mPin = pin;
			mRulesCnt = 0;
		}

		virtual uint8_t addRule(Condition * condition, Output * output);
		virtual uint8_t addRule(Rule rule);
		virtual uint8_t setPrecondition(Precondition * precondition);
		int16_t getMeasuredValue()
		{
			return mMeasuredValue;
		}
		
		uint8_t getPin()
		{
			return mPin;
		}
		
		virtual uint8_t measure();
		virtual uint8_t onCreate();
		
		
		virtual void store(JsonObject& json);
		virtual void restore(JsonObject& json);
};

#endif //__SENSOR_H__

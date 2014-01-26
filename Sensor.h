/*
* AbsSensor.h
*
* Created: 18.1.2014 11:36:05
* Author: Bhiefer
*/


#ifndef __SENSOR_H__
#define __SENSOR_H__

#include "ISensor.h"
#include "Object.h"
#include "Constants.h"
#include "Condition.h"
#include "Structs.h"

class Sensor : public ISensor, public Object
{
	private:
		Rule mRules[MAX_RULES_COUNT];
		uint8_t mRulesCnt;
		uint8_t mPin;
		uint8_t mIdentifier;
	
	//functions
	private:
		bool isRulesFull();
	
		protected:
		virtual char * toString();
		virtual int16_t measureValue() = 0;
	
	public:
		Sensor(uint8_t pin)
		{
			mPin = pin;
		}

		virtual uint8_t addRule(Condition * condition, Output * output);
		virtual uint8_t addRule(Rule rule);
		
		virtual uint8_t measure();
		virtual uint8_t onCreate();
	
};

#endif //__SENSOR_H__

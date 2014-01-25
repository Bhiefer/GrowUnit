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

struct Rule
{
	Condition * condition;
	Output * output;
};

typedef struct Rule Rule;

class Sensor : public ISensor, public Object
{
	private:
	Rule mRules[];
	byte mRulesCnt;
	byte mPin;
	byte mIdentifier;
	//functions
	private:
	bool isRulesFull();
	protected:
	virtual char * toString();
	virtual int measureValue() = 0;
	public:
	Sensor(byte pin)
	{
		mPin = pin;
	}

	virtual byte addRule(Condition * condition, Output * output);
	virtual byte addRule(Rule rule);
	
	virtual byte measure();
	
	
};

#endif //__SENSOR_H__

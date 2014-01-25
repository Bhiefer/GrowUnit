/*
* ISensor.h
*
* Created: 18.1.2014 11:16:42
* Author: Bhiefer
*/


#ifndef __ISENSOR_H__
#define __ISENSOR_H__

#include "Condition.h"
#include "Arduino.h"

class Output;

class ISensor
{
	//functions
	public:
	virtual byte addRule(Condition * condition, Output * output) = 0;
	virtual byte measure() = 0;

}; //ISensor

#endif //__ISENSOR_H__

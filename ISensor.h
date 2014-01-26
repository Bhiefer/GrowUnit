/*
* ISensor.h
*
* Created: 18.1.2014 11:16:42
* Author: Bhiefer
*/


#ifndef __ISENSOR_H__
#define __ISENSOR_H__

#include "Arduino.h"

class Output;
class Condition;

class ISensor
{
	//functions
	public:
	virtual uint8_t addRule(Condition * condition, Output * output) = 0;
	virtual uint8_t measure() = 0;

}; //ISensor

#endif //__ISENSOR_H__

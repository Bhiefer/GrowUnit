/*
* Condition.h
*
* Created: 24.1.2014 23:34:16
* Author: Bhiefer
*/


#ifndef __CONDITION_H__
#define __CONDITION_H__

#include "ICondition.h"
#include "Object.h"

class Condition : public ICondition, public Object
{
	byte mByte;
	//functions
	public:
	Condition() { mByte = 0;}
	
	virtual bool check(int value);
	
	virtual char * toString();
}; //Condition

#endif //__CONDITION_H__

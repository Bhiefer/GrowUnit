/*
* AlwaysCondition.h
*
* Created: 25.1.2014 17:44:29
* Author: Bhiefer
*/


#ifndef __ALWAYSCONDITION_H__
#define __ALWAYSCONDITION_H__

#include "Condition.h"

class AlwaysCondition : public Condition
{
	//functions
	public:
	AlwaysCondition() {};
	bool check(int value);

}; //AlwaysCondition

#endif //__ALWAYSCONDITION_H__

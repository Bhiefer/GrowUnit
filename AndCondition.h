/* 
* AndCondition.h
*
* Created: 3.11.2014 9:06:35
* Author: Bhiefer
*/


#ifndef __ANDCONDITION_H__
#define __ANDCONDITION_H__

#include "Condition.h"

class AndCondition : public Condition
{
//variables
public:
protected:
private:
	Condition * mFirst;
	Condition * mSecond;

//functions
public:
	AndCondition(Condition * first, Condition * second);
	
	virtual bool check(int16_t value);
protected:
private:

}; //AndCondition

#endif //__ANDCONDITION_H__
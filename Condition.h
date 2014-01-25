/* 
* Condition.h
*
* Created: 24.1.2014 23:34:16
* Author: Bhiefer
*/


#ifndef __CONDITION_H__
#define __CONDITION_H__

#include "ICondition.h"

class Condition : public ICondition
{
//variables
public:
protected:
private:

//functions
public:
	Condition();
protected:
private:
public:
	virtual bool check(int value);

}; //Condition

#endif //__CONDITION_H__

/* 
* AndCondition.cpp
*
* Created: 3.11.2014 9:06:34
* Author: Bhiefer
*/


#include "AndCondition.h"

 AndCondition::AndCondition( Condition * first, Condition * second )
{
	mFirst = first;
	mSecond = second;
}

bool AndCondition::check( int16_t value )
{
	return mFirst->check(value) && mSecond->check(value);
}


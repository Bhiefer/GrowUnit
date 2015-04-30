/* 
* AndCondition.cpp
*
* Created: 3.11.2014 9:06:34
* Author: Bhiefer
*/


#include "AndCondition.h"

bool AndCondition::check( int16_t value )
{
	Serial.println("xxxxx");
	Serial.println(value);
	Serial.println(mFirst->check(value));
	Serial.println(mSecond->check(value));
	return mFirst->check(value) && mSecond->check(value);
}


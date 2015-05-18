/* 
* AndCondition.cpp
*
* Created: 3.11.2014 9:06:34
* Author: Bhiefer
*/


#include "AndCondition.h"

bool AndCondition::check( int16_t value )
{
	boolean first = mFirst->check(value);
	boolean second = mSecond->check(value);
	Serial.println("xxxxx");
	Serial.println(value);
	Serial.println(first);
	Serial.println(second);
	return first && second;
}

void AndCondition::store( JsonObject& json )
{
	//mSecond->store(json);
}


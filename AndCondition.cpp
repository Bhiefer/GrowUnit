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
// 	Serial.println("xxxxx");
// 	Serial.println(value);
// 	Serial.println(first);
// 	Serial.println(second);
	return first && second;
}

void AndCondition::store( JsonObject& json )
{
	//mSecond->store(json);
}

bool AndCondition::isUsingEeprom()
{
	return mFirst->isUsingEeprom() || mSecond->isUsingEeprom();
}

uint8_t AndCondition::storeToEeprom( int16_t address )
{
	uint8_t size = mFirst->storeToEeprom(address);
	
	size += mSecond->storeToEeprom(address + size);
	
	return size;
}

uint8_t AndCondition::restoreFromEeprom( int16_t address )
{
	uint8_t size = mFirst->restoreFromEeprom(address);
	
	size += mSecond->restoreFromEeprom(address + size);
	
	return size;
}

void AndCondition::toString( char* string, uint8_t maxLength )
{
	mFirst->toString(string, maxLength);
	uint8_t len = strnlen(string, maxLength);
	
	string[len] = '\n';
	mSecond->toString(string + len + 1, maxLength - len - 1);
}


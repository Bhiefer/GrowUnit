/* 
* LessThanCondition.cpp
*
* Created: 12.3.2015 12:34:08
* Author: Bhiefer
*/


#include "LessThanCondition.h"
#include "Timer.h"
#include "Constants.h"
#include <EEPROMex.h>


bool LessThanCondition::check( int16_t value )
{
	Serial.print("Podminka:");
	// SUCHO
	if(value < mTreshold)
	{
		Serial.print("sucho");

		// neuplynuly ani tri hodiny - nemuze se jeste zalivat
		if(!timer.checkElapsed(mLastTime, 3*ONE_HOUR))
		{
			// nechat hodinku pro stabilizaci
			if(timer.checkElapsed(mLastTime, 1*ONE_HOUR))
			{
				Serial.print(": > 1 hodina");
				// jednou prizpusobit treshold
				if(!mAdjusted)
				{
					Serial.print("-prizpusobeni");
					mAdjusted = true;
					mTreshold = mTreshold * 1.2;
				}
			}
			else
			{
				Serial.print(": < 3 hodiny");
			}
			
			Serial.println();
			return false;
		}
		else
		{
			Serial.println(": > 3 hodiny");
			// sucho po vice nez trech hodinach -> zalit
			mAdjusted = false;
			mLastTime = timer.current();
			return true;
		}
	}
	// MOKRO
	else
	{
		Serial.print("mokro");
		
		// zalit aspon co 8 hodin
		if(timer.checkElapsed(mLastTime, 8*ONE_HOUR))
		{
			Serial.println(": > 8 hodin - ZALIT!");
			int dif = value - mTreshold;
			mTreshold = mTreshold + (0.8*dif);
		
			mAdjusted = false;
			mLastTime = timer.current();
			return true;
		}
		else
		{
			Serial.println(": < 8 hodin");
			// mene nez osm hodin a je dostatecne zalito
			return false;
		}
	}
}

void LessThanCondition::store( JsonObject& json )
{
	json["type"] = "dryCondition";
	json["treshold"] = mTreshold;
	json["interval"] = timer.current() - mLastTime;
}

uint8_t LessThanCondition::storeToEeprom( int16_t address )
{
	EEPROM.updateLong(address, mLastTime);
	uint8_t size = sizeof(mLastTime);
	EEPROM.updateInt(address + size, mTreshold);
	size += sizeof(mTreshold);
	EEPROM.updateByte(address+size, mAdjusted);
	
// 	Serial.print("Store:");
// 	Serial.print(mLastTime);
// 	Serial.print(",");
// 	Serial.print(mTreshold);
// 	Serial.print(",");
// 	Serial.println(mAdjusted);
	
	return size +1;	
}

uint8_t LessThanCondition::restoreFromEeprom( int16_t address )
{	
	mLastTime = EEPROM.readLong(address);
	uint8_t size = sizeof(mLastTime);
	mTreshold = EEPROM.readInt(address + size);
	size += sizeof(mTreshold);
	mAdjusted = EEPROM.readByte(address+size);
	
// 	Serial.print("Restore:");
// 	Serial.print(mLastTime);
// 	Serial.print(",");
// 	Serial.print(mTreshold);
// 	Serial.print(",");
// 	Serial.println(mAdjusted);
	
	return size +1;
}

void LessThanCondition::toString( char* string, uint8_t maxLength )
{
	time_t last = mLastTime + TIMEZONE_SHIFT_SECONDS;
	String str = String("x<") + mTreshold;
	str += ",";
	str += day(last);
	str += ".";
	str += month(last);
	str += ". ";
	str += hour(last);
	str += ":";
	if(minute(last) < 10)
		Serial.print(F("0"));
	str += minute(last);
	
	if(mAdjusted)
	{
		str += ",A";
	}
	else
	{
		str += ",N";
	}
	
	memcpy(string, str.c_str(), min(str.length(), maxLength));
}



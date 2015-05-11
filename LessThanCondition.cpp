/* 
* LessThanCondition.cpp
*
* Created: 12.3.2015 12:34:08
* Author: Bhiefer
*/


#include "LessThanCondition.h"
#include "Timer.h"
#include "Constants.h"


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
			
			return false;
		}
		else
		{
			Serial.print(": > 3 hodiny");
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
			Serial.print(": > 8 hodin - ZALIT!");
			int dif = value - mTreshold;
			mTreshold = mTreshold + (0.8*dif);
		
			mAdjusted = false;
			mLastTime = timer.current();
			return true;
		}
		else
		{
			Serial.print(": < 8 hodin");
			// mene nez osm hodin a je dostatecne zalito
			return false;
		}
	}
	
	Serial.println();
}

void LessThanCondition::store( JsonObject& json )
{
	json["type"] = "dryCondition";
	json["treshold"] = mTreshold;
	json["interval"] = timer.current() - mLastTime;
}

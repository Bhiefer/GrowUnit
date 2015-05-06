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
	// SUCHO
	if(value < mTreshold)
	{
		// neuplynuly ani tri hodiny - nemuze se jeste zalivat
		if(!timer.checkElapsed(mLastTime, 3*ONE_HOUR))
		{
			// nechat hodinku pro stabilizaci
			if(timer.checkElapsed(mLastTime, 1*ONE_HOUR))
			{
				// jednou prizpusobit treshold
				if(!mAdjusted)
				{
					mAdjusted = true;
					mTreshold = mTreshold * 1.2;
				}
			}
			
			return false;
		}
		else
		{
			// sucho po vice nez trech hodinach -> zalit
			mAdjusted = false;
			mLastTime = timer.current();
			return true;
		}
	}
	// MOKRO
	else
	{
		// zalit aspon co 8 hodin
		if(timer.checkElapsed(mLastTime, 8*ONE_HOUR))
		{
			int dif = value - mTreshold;
			mTreshold = mTreshold + (0.8*dif);
		
			mAdjusted = false;
			mLastTime = timer.current();
			return true;
		}
		else
		{
			// mene nez osm hodin a je dostatecne zalito
			return false;
		}
	}
}

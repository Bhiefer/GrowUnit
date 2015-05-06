/* 
* Avarager.cpp
*
* Created: 1.5.2015 11:28:58
* Author: Bhiefer
*/


#include "Averager.h"

int16_t Averager::process( int16_t value )
{
	mAverage.addValue(static_cast<float>(value));
	
	return static_cast<int16_t>(mAverage.getAverage());
}

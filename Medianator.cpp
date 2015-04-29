/* 
* Medianator.cpp
*
* Created: 2.11.2014 0:37:13
* Author: Bhiefer
*/


#include "Medianator.h"


int16_t Medianator::process( int16_t value )
{
	mMedian.add(static_cast<float>(value));
	
	return static_cast<int16_t>(mMedian.getMedian());
}



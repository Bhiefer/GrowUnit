/* 
* DhtTempSensor.cpp
*
* Created: 12.3.2015 11:50:09
* Author: Bhiefer
*/


#include "DhtTempSensor.h"

int16_t DhtTempSensor::extractDhtValue()
{
	return static_cast<int16_t>(mDht.temperature * 10);
}

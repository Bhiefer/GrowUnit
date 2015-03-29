/* 
* DhtHumSensor.cpp
*
* Created: 12.3.2015 11:45:12
* Author: Bhiefer
*/


#include "DhtHumSensor.h"

int16_t DhtHumSensor::extractDhtValue()
{
	return static_cast<int16_t>(mDht.humidity * 10);
}

void DhtHumSensor::store( JsonObject& json )
{
	json["type"] = "dhtHumidity";
	
	DhtSensor::store(json);
}

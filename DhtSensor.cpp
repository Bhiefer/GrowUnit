/* 
* DhtSensor.cpp
*
* Created: 12.3.2015 10:36:34
* Author: Bhiefer
*/


#include "DhtSensor.h"

int16_t DhtSensor::measureValue()
{
	if(log)
		Serial.print("DHT21, \t");
	uint8_t chk = mDht.read21(mPin);
	switch (chk)
	{
		case DHTLIB_OK:
		if(log)
			Serial.print("OK,\t");
		break;
		case DHTLIB_ERROR_CHECKSUM:
		if(log)
			Serial.print("Checksum error,\t");
		break;
		case DHTLIB_ERROR_TIMEOUT:
		if(log)
			Serial.print("Time out error,\t");
		break;
		default:
		if(log)
			Serial.print("Unknown error,\t");
		break;
	}
	
	if(log)
	{
		// DISPLAY DATA
		Serial.print(mDht.humidity, 1);
		Serial.print(",\t");
		Serial.println(mDht.temperature, 1);
	}
	
	return extractDhtValue();
}

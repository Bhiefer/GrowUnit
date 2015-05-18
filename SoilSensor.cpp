/* 
* SoilSensor.cpp
*
* Created: 3.11.2014 20:18:05
* Author: Bhiefer
*/


#include "SoilSensor.h"

int16_t SoilSensor::measureValue()
{
	int16_t i = 1024 - AnalogSensor::measureValue();
//	i = min(i,256);
	//Serial.println(i);
	return i;
}

void SoilSensor::store( JsonObject& json )
{
	json["type"] = "soilSensor";
	
	AnalogSensor::store(json);
}

void SoilSensor::toString( char* string, uint8_t maxLength )
{
	String str = String("Pudni senzor:") + mMeasuredValue;
	
	memcpy(string, str.c_str(), min(str.length(), maxLength));
}

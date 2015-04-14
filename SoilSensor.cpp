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
	Serial.println(i);
	return i;
}

void SoilSensor::store( JsonObject& json )
{
	json["type"] = "soilSensor";
	
	AnalogSensor::store(json);
}
/* 
* SoilSensor.cpp
*
* Created: 3.11.2014 20:18:05
* Author: Bhiefer
*/


#include "SoilSensor.h"

int16_t SoilSensor::measureValue()
{
	return 1024 - AnalogSensor::measureValue();
}

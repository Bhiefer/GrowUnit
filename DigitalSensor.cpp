/* 
* DigitalSensor.cpp
*
* Created: 26.1.2014 22:01:11
* Author: Bhiefer
*/


#include "DigitalSensor.h"
#include "arduino.h"

int16_t DigitalSensor::measureValue()
{
	return digitalRead(mPin);
}

uint8_t DigitalSensor::onCreate()
{
	pinMode(mPin, INPUT);	
}

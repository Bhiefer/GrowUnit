/* 
* AnalogSensor.cpp
*
* Created: 25.1.2014 0:53:20
* Author: Bhiefer
*/


#include "AnalogSensor.h"
#include "Arduino.h"

int16_t AnalogSensor::measureValue()
{
	Serial.println(mPin);
	return analogRead(mPin);
}

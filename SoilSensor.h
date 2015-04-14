/* 
* SoilSensor.h
*
* Created: 3.11.2014 20:18:05
* Author: Bhiefer
  
  # the sensor value description
  # 0  ~300     dry soil
  # 300~700     humid soil
  # 700~950     in water
*/


#ifndef __SOILSENSOR_H__
#define __SOILSENSOR_H__

#include "AnalogSensor.h"

class SoilSensor : public AnalogSensor
{
//variables
public:
protected:
private:

//functions
public:
	SoilSensor(uint8_t id, uint8_t pin) : AnalogSensor(id, pin)
	{
		
	}

	virtual int16_t measureValue();
	virtual void store(JsonObject& json);

protected:
private:

}; //SoilSensor

#endif //__SOILSENSOR_H__

/* 
* Pcd8544Output.h
*
* Created: 26.1.2014 17:34:42
* Author: Bhiefer
*/

#ifndef __PCD8544OUTPUT_H__
#define __PCD8544OUTPUT_H__

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#include "Output.h"

class Pcd8544Output : public Adafruit_PCD8544, public Output
{
private:
	int16_t mLight;	
int16_t mSwitch;
//functions
public:
	Pcd8544Output(uint8_t id, int8_t rst, int8_t ce, int8_t dc, int8_t din, int8_t clk);
	
	virtual uint8_t onReceive(int16_t value, Sensor * sensor);
	virtual uint8_t onCreate();
	virtual uint8_t onMeasured();

protected:
private:

}; //Pcd8544Output

#endif //__PCD8544OUTPUT_H__

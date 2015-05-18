/* 
* Ssd1306Viewer.h
*
* Created: 16.5.2015 10:50:25
* Author: Bhiefer
*/


#ifndef __SSD1306VIEWER_H__
#define __SSD1306VIEWER_H__

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Viewer.h"

class Ssd1306Viewer : public Adafruit_SSD1306, public Viewer
{
	//functions
	public:
	Ssd1306Viewer(uint8_t id, int8_t d0, int8_t d1, int8_t rst, int8_t dc, int8_t cs);
	
	virtual uint8_t onCreate();
	virtual uint8_t onMeasured();

};//Ssd1306Viewer

#endif //__SSD1306VIEWER_H__

/* 
* Pcd8544Viewer.h
*
* Created: 26.1.2014 17:34:42
* Author: Bhiefer
*/

#ifndef __PCD8544OUTPUT_H__
#define __PCD8544OUTPUT_H__

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#include "Viewer.h"

class Pcd8544Viewer : public Adafruit_PCD8544, public Viewer
{
private:
//functions
public:
	Pcd8544Viewer(uint8_t id, int8_t rst, int8_t ce, int8_t dc, int8_t din, int8_t clk);
	
	virtual uint8_t onCreate();
	virtual uint8_t onMeasured();

protected:
private:

}; //Pcd8544Viewer

#endif //__PCD8544OUTPUT_H__

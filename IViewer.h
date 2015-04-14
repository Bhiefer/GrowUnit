/* 
* IViewer.h
*
* Created: 14.4.2015 21:14:18
* Author: Bhiefer
*/


#ifndef __IVIEWER_H__
#define __IVIEWER_H__

#include "Arduino.h"

class IViewer
{
	//functions
	public:
	virtual uint8_t onCreate() = 0;
	virtual uint8_t onMeasured() = 0;
}; //IViewer

#endif //__IVIEWER_H__

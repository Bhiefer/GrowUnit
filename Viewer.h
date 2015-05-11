/* 
* Viewer.h
*
* Created: 14.4.2015 21:15:30
* Author: Bhiefer
*/


#ifndef __VIEWER_H__
#define __VIEWER_H__

#include "Object.h"

class Viewer: public Object
{
	
	//functions
	public:
	Viewer(uint8_t id): Object(id)
	{
		
	}
	
	virtual uint8_t onCreate();
	virtual uint8_t onMeasured();
	
	virtual void toString(char* string, uint8_t maxLength);

}; //Viewer

#endif //__VIEWER_H__

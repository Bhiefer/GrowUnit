/* 
* Viewer.h
*
* Created: 14.4.2015 21:15:30
* Author: Bhiefer
*/


#ifndef __VIEWER_H__
#define __VIEWER_H__

#include "Object.h"
#include "IViewer.h"

class Viewer: public IViewer, public Object
{
	
	//functions
	public:
	Viewer(uint8_t id): Object(id)
	{
		
	}
	
	virtual uint8_t onCreate();
	virtual uint8_t onMeasured();
	
	virtual char * toString();

}; //Viewer

#endif //__VIEWER_H__

/*
* Object.h
*
* Created: 18.1.2014 11:40:09
* Author: Bhiefer
*/


#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "IObject.h"

class Object : public IObject
{
	//functions
	public:
	virtual char * toString()=0;
	virtual void writeDebug();

};

#endif //__OBJECT_H__

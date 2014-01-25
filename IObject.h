/* 
* Object.h
*
* Created: 18.1.2014 11:38:02
* Author: Bhiefer
*/


#ifndef __IOBJECT_H__
#define __IOBJECT_H__

#include "Arduino.h"

class IObject
{
//functions
public:
	virtual ~IObject(){}
	virtual void writeDebug() = 0;
	virtual char * toString() = 0;

}; //Object

#endif //__IOBJECT_H__

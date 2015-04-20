/* 
* Precondition.h
*
* Created: 2.11.2014 0:58:56
* Author: Bhiefer
*/


#ifndef __PRECONDITION_H__
#define __PRECONDITION_H__

#include "Object.h"

class Precondition : public Object
{
	//functions
	public:
	Precondition(uint8_t id): Object(id)
	{
		
	}
	
	virtual bool check();
	
	virtual void toString(char* string, uint8_t maxLength);
}; //Precondition

#endif //__PRECONDITION_H__

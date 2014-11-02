/* 
* Precondition.h
*
* Created: 2.11.2014 0:58:56
* Author: Bhiefer
*/


#ifndef __PRECONDITION_H__
#define __PRECONDITION_H__

#include "IPrecondition.h"
#include "Object.h"

class Precondition : public IPrecondition, public Object
{
	//functions
	public:
	Precondition();
	
	virtual bool check();
	
	virtual char * toString();
}; //Precondition

#endif //__PRECONDITION_H__

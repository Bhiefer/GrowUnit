/* 
* ValueProcessor.h
*
* Created: 2.11.2014 0:34:25
* Author: Bhiefer
*/


#ifndef __VALUEPROCESSOR_H__
#define __VALUEPROCESSOR_H__

#include "Object.h"

class ValueProcessor : public Object
{
//functions
public:
	ValueProcessor(uint8_t id) : Object(id)
	{
	}
	
	virtual int16_t process(int16_t value) = 0;
	
	virtual void toString(char* string, uint8_t maxLength);

}; //ValueProcessor

#endif //__VALUEPROCESSOR_H__

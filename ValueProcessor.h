/* 
* ValueProcessor.h
*
* Created: 2.11.2014 0:34:25
* Author: Bhiefer
*/


#ifndef __VALUEPROCESSOR_H__
#define __VALUEPROCESSOR_H__

#include "Object.h"
#include "IValueProcessor.h"

class ValueProcessor : public IValueProcessor, public Object
{
//functions
public:
	virtual ~ValueProcessor();
	virtual int16_t process(int16_t value) = 0;

}; //ValueProcessor

#endif //__VALUEPROCESSOR_H__

/* 
* IValueProcessor.h
*
* Created: 2.11.2014 0:31:28
* Author: Bhiefer
*/


#ifndef __IVALUEPROCESSOR_H__
#define __IVALUEPROCESSOR_H__


class IValueProcessor
{
//functions
public:
	virtual ~IValueProcessor(){}
	virtual int16_t process(int16_t value) = 0;

}; //IValueProcessor

#endif //__IVALUEPROCESSOR_H__

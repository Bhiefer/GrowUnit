/* 
* Medianator.h
*
* Created: 2.11.2014 0:37:13
* Author: Bhiefer
*/


#ifndef __MEDIANATORFIVE_H__
#define __MEDIANATORFIVE_H__

#include "ValueProcessor.h"
#include <RunningMedian.h>

class Medianator : public ValueProcessor
{
//variables
public:
protected:
private:
	RunningMedian mMedian;

//functions
public:
	Medianator(uint8_t id, uint8_t size) : ValueProcessor(id), mMedian(RunningMedian(size))
	{
	}
	
	virtual int16_t process(int16_t value);
protected:
private:

}; //Medianator

#endif //__MEDIANATORFIVE_H__

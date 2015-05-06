/* 
* Avarager.h
*
* Created: 1.5.2015 11:28:58
* Author: Bhiefer
*/


#ifndef __AVERAGER_H__
#define __AVERAGER_H__

#include "ValueProcessor.h"
#include <RunningAverage.h>

class Averager: public ValueProcessor
{
	
//variables
private:
	RunningAverage mAverage;

//functions
public:
	Averager(uint8_t id, uint8_t size) : ValueProcessor(id), mAverage(RunningAverage(size))
	{
	}
	
	virtual int16_t process(int16_t value);

}; //Averager

#endif //__AVERAGER_H__

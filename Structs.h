/*
* IncFile1.h
*
* Created: 26.1.2014 12:43:05
*  Author: Bhiefer
*/


#ifndef STRUCTS_H_
#define STRUCTS_H_

class Sensor;
class Condition;
class Output;

struct Mapping
{
	Sensor * sensor;
	Condition * condition;
	Output * output;
};

typedef struct Mapping Mapping;

struct Rule
{
	Condition * condition;
	Output * output;
};

typedef struct Rule Rule;


#endif /* STRUCTS_H_ */
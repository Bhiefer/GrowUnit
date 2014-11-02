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
class Precondition;

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

struct Measurement
{
	Sensor * sensor;
	int16_t value;
};

typedef struct Measurement Measurement;

struct SensorPrecondition
{
	Precondition * precondition;
	Sensor * sensor;
};

typedef struct Measurement Measurement;


#endif /* STRUCTS_H_ */
/*
 * IncFile1.h
 *
 * Created: 25.1.2014 13:22:31
 *  Author: Bhiefer
 */ 


#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "SerialOutput.h"
#include "LightSensor.h"
#include "AlwaysCondition.h"

struct Mapping
{
	Sensor * sensor;
	Condition * condition;
	Output * output;
};

typedef struct Mapping Mapping;

LightSensor lightSensor(1);

AlwaysCondition always;

SerialOutput serialOutput;



static Sensor* sensors[] = {&lightSensor};
static byte sensorsSize = sizeof(sensors)/sizeof(Sensor*);

static Output* outputs[] = {&serialOutput};
static byte outputsSize = sizeof(outputs)/sizeof(Output*);

static Mapping mapping[] = {{&lightSensor, &always, &serialOutput}};
static byte mappingSize = sizeof(mapping)/sizeof(Mapping);


#endif /* CONFIGURATION_H_ */
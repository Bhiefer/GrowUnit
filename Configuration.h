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
#include "Structs.h"
#include "Pcd8544Output.h"


LightSensor lightSensor(0);

AlwaysCondition always;

SerialOutput serialOutput;

Pcd8544Output pcd8544Output(12,11,10,9,8);

static Sensor* sensors[] = {
	&lightSensor
};
static uint8_t sensorsSize = sizeof(sensors)/sizeof(Sensor*);

static Output* outputs[] = {
	&serialOutput,
	&pcd8544Output
};
static uint8_t outputsSize = sizeof(outputs)/sizeof(Output*);

static Mapping mapping[] = {
	{&lightSensor, &always, &serialOutput},
	{&lightSensor, &always, &pcd8544Output}
};
static uint8_t mappingSize = sizeof(mapping)/sizeof(Mapping);


#endif /* CONFIGURATION_H_ */
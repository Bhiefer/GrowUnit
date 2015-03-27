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
#include "DigitalSensor.h"
#include "TimePrecondition.h"
#include "SoilSensor.h"
#include "DhtHumSensor.h"
#include "RelayOutput.h"
#include "LessThanCondition.h"


// LightSensor lightSensor(0);
//SoilSensor soilSensor(0);
// DigitalSensor digiSensor(6);
DhtHumSensor dhtSensor(12);

AlwaysCondition always;
LessThanCondition lessThan(800);

TimePrecondition timePrecondition(5);

RelayOutput relayOutput(13, 3);
SerialOutput serialOutput;
//Pcd8544Output pcd8544Output(12,11,10,9,8);

static Sensor* sensors[] = {
	&dhtSensor,
//	&lightSensor,
//  &soilSensor,
//	&digiSensor
};
static uint8_t sensorsSize = sizeof(sensors)/sizeof(Sensor*);

static Output* outputs[] = {
	&serialOutput,
	&relayOutput
//	&pcd8544Output
};
static uint8_t outputsSize = sizeof(outputs)/sizeof(Output*);

static SensorPrecondition preconditions[] = {
	{&timePrecondition, &dhtSensor}
};
static uint8_t preconditionsSize = sizeof(preconditions)/sizeof(SensorPrecondition);

static Mapping mapping[] = {
	{&dhtSensor, &lessThan, &relayOutput},
//	{&soilSensor, &always, &pcd8544Output},
//	{&soilSensor, &always, &serialOutput}
};
static uint8_t mappingSize = sizeof(mapping)/sizeof(Mapping);


#endif /* CONFIGURATION_H_ */
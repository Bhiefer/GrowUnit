/*
* IncFile1.h
*
* Created: 25.1.2014 13:22:31
*  Author: Bhiefer
*/


#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "SerialViewer.h"
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
#include "PlotlyViewer.h"

//extern  LightSensor lightSensor;
extern SoilSensor soilSensor;
//extern DigitalSensor digiSensor;
//extern DhtHumSensor dhtSensor;

extern AlwaysCondition always;
extern LessThanCondition lessThan;

extern TimePrecondition timePrecondition;

extern RelayOutput relayOutput;

extern SerialViewer serialViewer;
extern PlotlyViewer plotlyViewer;
//extern Pcd8544Output pcd8544Viewer;

static Sensor* sensors[] = {
//	&dhtSensor,
//	&lightSensor,
  &soilSensor,
//	&digiSensor
};
static uint8_t sensorsSize = sizeof(sensors)/sizeof(Sensor*);

static Output* outputs[] = {
//	&relayOutput
};
static uint8_t outputsSize = sizeof(outputs)/sizeof(Output*);

static Viewer* viewers[] = {
	&serialViewer,
	&plotlyViewer
//	&pcd8544Viewer
};
static uint8_t viewersSize = sizeof(viewers)/sizeof(Viewer*);

static SensorPrecondition preconditionMapping[] = {
	{&timePrecondition, &soilSensor}
};
static uint8_t preconditionMappingSize = sizeof(preconditionMapping)/sizeof(SensorPrecondition);

static Mapping mapping[] = {
//	{&dhtSensor, &lessThan, &relayOutput},
//	{&soilSensor, &always, &pcd8544Output},
	{&soilSensor, &lessThan, &relayOutput}
};
static uint8_t mappingSize = sizeof(mapping)/sizeof(Mapping);


#endif /* CONFIGURATION_H_ */
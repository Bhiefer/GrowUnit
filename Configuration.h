/*
* IncFile1.h
*
* Created: 25.1.2014 13:22:31
*  Author: Bhiefer
*/


#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "SerialViewer.h"
#include "Structs.h"
#include "Pcd8544Viewer.h"
#include "DigitalSensor.h"
#include "TimePrecondition.h"
#include "SoilSensor.h"
#include "DhtHumSensor.h"
#include "RelayOutput.h"
#include "AndCondition.h"
#include "PlotlyViewer.h"
#include "Medianator.h"
#include "NoSensor.h"
#include "DayTimeCondition.h"
#include "HourCondition.h"

//extern  LightSensor lightSensor;
//extern DigitalSensor digiSensor;
//extern DhtHumSensor dhtSensor;

extern SoilSensor soilSensor;
extern NoSensor noSensor;

extern AndCondition floodCondition;
extern HourCondition morningCondition;
extern HourCondition afternoonCondition;

extern RelayOutput waterPumpRelayOutput;
extern RelayOutput airPumpRelayOutput;

extern SerialViewer serialViewer;
extern PlotlyViewer plotlyViewer;
//extern Pcd8544Viewer pcd8544Viewer;

static Sensor* sensors[] = {
  &soilSensor,
  &noSensor,
};
static uint8_t sensorsSize = sizeof(sensors)/sizeof(Sensor*);

static Output* outputs[] = {
	&waterPumpRelayOutput,
	&airPumpRelayOutput
};
static uint8_t outputsSize = sizeof(outputs)/sizeof(Output*);

static Viewer* viewers[] = {
	&serialViewer,
	&plotlyViewer,
//	&pcd8544Viewer
};
static uint8_t viewersSize = sizeof(viewers)/sizeof(Viewer*);

static Mapping mapping[] = {
	{&soilSensor, &floodCondition, &waterPumpRelayOutput},
	{&noSensor, &morningCondition, &airPumpRelayOutput},
	{&noSensor, &afternoonCondition, &airPumpRelayOutput}
};
static uint8_t mappingSize = sizeof(mapping)/sizeof(Mapping);


#endif /* CONFIGURATION_H_ */
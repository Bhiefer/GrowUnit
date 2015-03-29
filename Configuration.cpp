// 
// 
// 

#include "Configuration.h"

// LightSensor lightSensor(0);
//SoilSensor soilSensor(0);
// DigitalSensor digiSensor(6);
DhtHumSensor dhtSensor(12);

AlwaysCondition always;
LessThanCondition lessThan(800);

TimePrecondition timePrecondition(5);

RelayOutput relayOutput(10, 3);
SerialOutput serialOutput;
//Pcd8544Output pcd8544Output(12,11,10,9,8);
